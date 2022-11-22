#define _WIN32_WINNT 0x601 // Адрес дисплея в памяти
#include <windows.h> // Подключаем библиотеку из операционной системы Windows
#include <stdio.h> // Подключаем стандартный ввод и вывод информации в стиле C

int main() {
    // Передаем изображение в консоль
    HWND console_handle = GetConsoleWindow(); 
    HDC device_context = GetDC(console_handle);

    // Здесь 5 пикселей широкой красной линии начинаются с [0,0] до [300,300]
    HPEN Line1 = CreatePen(PS_SOLID, 5, RGB(255, 0, 0)); // Цвет задается в RGB
    SelectObject(device_context, Line1); // Передается объект в консоль
    LineTo(device_context, 300, 300); // Определяются координаты X и Y объекта

    // Здесь 5 пикселей широкой красной линии начинаются с [0,0] до [300,300]
    HPEN Line2 = CreatePen(PS_SOLID, 5, RGB(255, 100, 100)); // Цвет задается в RGB
    SelectObject(device_context, Line2); // Передается объект в консоль
    LineTo(device_context, 300, 800); // Определяются координаты X и Y объекта

    ReleaseDC(console_handle, device_context); // Завершается передача объекта

    getchar(); // Ожидаем ввода пользователя

    return 0;
}