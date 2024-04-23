total = 0
count = 0

while True:
    user_input = input("Введите число или 'готово' для завершения: ")

    if user_input.lower() == 'готово':
        break

    try:
        number = float(user_input)
        total += number
        count += 1
    except ValueError:
        print("Ошибка: Введите числовое значение.")

if count > 0:
    average = total / count
    print(f"\nОбщее количество: {count}")
    print(f"Сумма чисел: {total}")
    print(f"Среднее число: {average}")
else:
    print("Вы не ввели ни одного числа.")
