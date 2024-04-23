def computegrade(score):
    """
    Функция, принимающая оценку и возвращающая соответствующую буквенную оценку.
    """
    if 0.0 <= score <= 1.0:
        if score >= 0.9:
            return 'A'
        elif score >= 0.8:
            return 'B'
        elif score >= 0.7:
            return 'C'
        elif score >= 0.6:
            return 'D'
        else:
            return 'F'
    else:
        return "Ошибка: Оценка должна быть в диапазоне от 0.0 до 1.0."

# Запрос оценки от пользователя
try:
    score = float(input("Введите оценку от 0.0 до 1.0: "))
except ValueError:
    print("Ошибка: Введите числовое значение.")
    exit()

grade = computegrade(score)
print(f"Оценка: {grade}")
