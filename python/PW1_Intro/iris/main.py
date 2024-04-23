import pandas as pd
import numpy as np
import seaborn as sns

irisData = pd.read_csv('iris.csv')

irisData.columns = ['Slength', 'Swidth' , 'Plength', 'Pwidth', 'Other']

irisData.head(100)
irisData.shape
print(irisData.groupby('Other elements').size())
irisData.min()
irisData.max()
irisData.mean()
irisData.median()
irisData.std()

TotalFunction = irisData.describe()
Total = TotalFunction.transpose()
Total.head()

