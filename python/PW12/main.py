import tensorflow as tf
import numpy as np
import matplotlib.pyplot as plt

np.random.seed(42)
data = np.random.rand(100, 2)

grid_size = 10
epochs = 100

som_model = tf.keras.layers.SelfAttention([grid_size, grid_size], attention_axes="ax")
som_model.compile(optimizer='adam', loss='mean_squared_error')
som_model.fit(data, data, epochs=epochs, verbose=0)

labels = som_model.predict(data)

plt.scatter(data[:, 0], data[:, 1], c=labels, cmap='viridis', edgecolors='k', s=50)
plt.title('Результаты кластеризации методом SOM')
plt.xlabel('Признак 1')
plt.ylabel('Признак 2')
plt.show()