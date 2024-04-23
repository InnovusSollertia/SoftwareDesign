from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score, classification_report

iris = datasets.load_iris()
X = iris.data
y = iris.target

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

svm_model = SVC(kernel='linear', C=1)
svm_model.fit(X_train, y_train)

svm_predictions = svm_model.predict(X_test)
accuracy = accuracy_score(y_test, svm_predictions)
print("Точность модели SVM:", accuracy)
print("Отчет о классификации для Support Vectory Machine:\n", classification_report(y_test, svm_predictions))