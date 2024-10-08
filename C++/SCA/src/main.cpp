﻿#include <stdio.h>
#include <iostream>

// Количество клеток
const int count = 60; // default 61

int Index(int x) {
    if (x < 0) return x + count; else return x % count;
}

// Функция поведения клетки
int f(int a1, int a2, int a3) {
    return a1 ^ a2 ^ a3;
}

int main(int argc, char* argv[]) {
    int A[count]{};
    int B[count]{};

    // <enter> и <e> (exit)
    char c;

    for (int i = 0; i < count; i++) {
        A[i] = 0;
    }

    A[30] = 1;

    // Итерации автомата
    for (;;) {
        for (int i = 0; i < count; i++)

            printf("%c", A[i] ? '*' : ' ');

        for (int i = 0; i < count; i++) {
            B[i] = f(A[Index(i - 1)], A[Index(i)], A[Index(i + 1)]);
        }
        for (int i = 0; i < count; i++)
            A[i] = B[i];

        c = getchar();

        if (c == 'e') return 0;

    }

    return 0;
}
