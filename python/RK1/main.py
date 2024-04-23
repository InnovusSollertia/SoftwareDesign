# mpg - милли (1,6 км) на галон (4,54 л)
# cyl - сколько цилиндров в двигателе
# disp - объем в кубических сантиметрах
# hp - лошадинные силы
# drat - передаточное число карданного вала
# wt - вес
# qsec - ускорение м/с (1/4 мили)
# vs - форма двигателя (рядный или V-образный)
# am - трансмиссия (авто или ручная)
# gear - количество передач
# carb - количество корбюраторов

# Анализ данных mtcars.csv
# 1. Размер - 2 kB
# 2. Количество строк - 32
# 3. Количество столбцов - 12
# 4. Общее количество машин - 32

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import csv

X = []
Y = []

with open('ProjectScience\software\python\AT1\mtcars.csv', 'r') as datafile:
    plotting = csv.reader(datafile, delimiter=';')
    
    for ROWS in plotting:
        X.append(int(ROWS[0]))
        Y.append(int(ROWS[1]))

plt.plot(X, Y)
plt.title('Line Graph using CSV')
plt.xlabel('X')
plt.ylabel('Y')
plt.show()