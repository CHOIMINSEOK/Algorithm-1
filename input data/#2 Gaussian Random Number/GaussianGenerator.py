import scipy.stats as ss
import numpy as np

fileStream = open('input.txt', 'w')

x = np.arange(-10, 11)
xU, xL = x + 0.5, x - 0.5
prob = ss.norm.cdf(xU, scale = 3) - ss.norm.cdf(xL, scale = 3)
prob = prob / prob.sum() #normalize the probabilities so their sum is 1
nums = np.random.choice(x, size = 100000000, p = prob)
datas = ""
for n in nums:
    datas += str(n) + " "
  
fileStream.write(datas)
fileStream.close()