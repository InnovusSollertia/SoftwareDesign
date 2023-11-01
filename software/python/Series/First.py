import pandas as pd 
import numpy as np

arrayOne = np.array([1, 3, 5, 7, 9])
arrayTwo = np.array([2, 4, 6, 8, 10])

print(arrayOne)
print(arrayTwo)

seriesOne = pd.Series(arrayOne)
seriesTwo = pd.Series(arrayTwo)
seriesOneSum = seriesOne.sum()
seriesTwoSum = seriesTwo.sum()
seriesLast = seriesOneSum + seriesTwoSum
print(seriesLast)


