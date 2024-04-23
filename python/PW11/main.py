from sklearn.datasets import make_blobs
from sklearn.cluster import KMeans
import matplotlib.pyplot as plt

X, _ = make_blobs(n_samples=300, centers=4, random_state=42)
kmeans_model = KMeans(n_clusters=4, random_state=42)

kmeans_model.fit(X)

labels = kmeans_model.labels_
centers = kmeans_model.cluster_centers_

plt.scatter(X[:, 0], X[:, 1], c=labels, cmap='viridis', edgecolors='k', s=50)
plt.scatter(centers[:, 0], centers[:, 1], c='red', marker='X', s=200, label='Центры кластеров')
plt.title('Результаты кластеризации методом K-средних')
plt.xlabel('Признак 1')
plt.ylabel('Признак 2')
plt.legend()
plt.show()
