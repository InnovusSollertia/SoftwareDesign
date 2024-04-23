import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import csv

x = [] 
y = [] 
  
with open('X:\Projects\Engineering\ProjectScience\software\python\gapminder\GDP.csv','r') as csvfile: 
    plots = csv.reader(csvfile, delimiter = ',')
    for row in plots:
        x.append((row[0]))
        y.append((row[0]))
          
plt.bar(x, y, color = 'g', width = 0.5, label = "Graphics 1") 
plt.xlabel('date') 
plt.ylabel('description') 
plt.title('Graphics 1') 
plt.legend() 
plt.show() 