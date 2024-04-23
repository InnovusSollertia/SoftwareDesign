# Запрос оценки от пользователя
try:
    score = float(input("Введите оценку от 0.0 до 1.0: "))
except ValueError:
    print("Ошибка: Введите числовое значение.")
    exit()

# Проверка, находится ли оценка в допустимом диапазоне
if 0.0 <= score <= 1.0:
    # Преобразование оценки в буквенный формат
    if score >= 0.9:
        grade = 'A'
    elif score >= 0.8:
        grade = 'B'
    elif score >= 0.7:
        grade = 'C'
    elif score >= 0.6:
        grade = 'D'
    else:
        grade = 'F'

    # Вывод результата
    print(f"Оценка: {grade}")
else:
    print("Ошибка: Оценка должна быть в диапазоне от 0.0 до 1.0.")
