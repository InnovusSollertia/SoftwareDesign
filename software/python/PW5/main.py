import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

x = np.linspace(0, 10, 100)
y0 = np.sin(x)
y1 = np.cos(x)

plt.plot(x, y0)
plt.show()
plt.plot(x, y1)
plt.show()

df.to_csv("data.csv")
