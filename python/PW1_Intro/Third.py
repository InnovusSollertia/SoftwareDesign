import pandas as pd 
import numpy as np

myDict = {'a': 100, 'b': 200, 'c': 300, 'd': 400, 'e': 800}

seriesDict = pd.Series(myDict)
seriesDictSum = seriesDict.sum()

print(seriesDict)
print(seriesDictSum)
