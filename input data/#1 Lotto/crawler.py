#-*- coding: utf-8 -*-
import sys
from selenium import webdriver
from bs4 import BeautifulSoup
import time

driver = webdriver.Chrome("./chromedriver")

## 역대 로또 당첨 번호 크롤링
driver.get("http://nlotto.co.kr/gameResult.do?method=allWin#")
time.sleep(0.5)
DBFileStream = open('./input.txt', 'w')

# pagination, max page = 78
try:
    for i in range(77):
        driver.execute_script("selfSubmit(" + str(i + 1) + ")")
        html = driver.page_source
        soup = BeautifulSoup(html, 'html.parser')
        
        rows = soup.select('body > section > article > article > div > table > tbody > tr')
        for row in rows:
            cols = row.find_all('td')
            try:
                DBFileStream.write(str(cols[1].string).replace(",", "") + " ")
            except:
                continue
        
        
        time.sleep(0.1)
finally:
    DBFileStream.close()
    driver.quit()
