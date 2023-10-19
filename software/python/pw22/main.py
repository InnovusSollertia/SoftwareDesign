import requests
from bs4 import BeautifulSoup

# Отправляем GET-запрос на страницу
url = 'https://www.github.com'
response = requests.get(url)

# Проверяем успешность запроса
if response.status_code == 200:
    # Получаем HTML-код страницы
    html = response.text

    # Создаем объект BeautifulSoup для парсинга HTML-кода
    soup = BeautifulSoup(html, 'html.parser')

    # Находим нужные элементы на странице
    title = soup.find('title').text
    links = [link['href'] for link in soup.find_all('a')]

    # Выводим результаты
    print(f'Title: {title}')
    print(f'Links: {links}')
else:
    print('Error')