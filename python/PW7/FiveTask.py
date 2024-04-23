# Исходная строка
s = 'X-DSPAM-Confidence:0.8475'

colon_pos = s.find(':')

confidence_str = s[colon_pos + 1:]

try:
    confidence = float(confidence_str)

    print(f"Извлеченное число с плавающей запятой: {confidence}")
except ValueError:
    print("Ошибка: Невозможно преобразовать в число с плавающей запятой.")
