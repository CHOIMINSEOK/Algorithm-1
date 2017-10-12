import csv

fileStream = open('input.txt','w')
# 2008년부터 2017년까지의 지하철 이용객수 csv파일 읽기
for fileName in range(2008, 2018):
    csvData = open('./subwayData/'+str(fileName)+'.csv', 'r', encoding='utf-8')
    isHeader = True
    for line in csvData:
        if isHeader:
            isHeader = False
            continue
        cols = line.split(',')
        numstring = "".join(list(cols[i] for i in range(4, len(cols)))).replace("\"","").rstrip() + " "
        # print(numstring)
        fileStream.write(numstring)

fileStream.close()