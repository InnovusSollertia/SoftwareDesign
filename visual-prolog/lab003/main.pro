 UlugbekRUDN
/*
Ибрагимов Улугбек Ботырхонович
Группа: Нфибд-02-20, Фундаментальная информатика и информационные технологии
Факультет: Физико-математический

Описание проекта:
1. Какое сырье нужно для производства товара
2. Какие товары требуют сырье
3. Отдельная весовая характеристика сырья и товара
4. Общая весовая характеристика сырья и товара

*/

implement main
    open core, stdio

domains
    unit = кг; т; л; шт.

class facts - productionDB
    сырье : (integer ID, string Name, string Type, string Weight).
    товар : (integer ID, string Name, string Type, string Weight, integer QuantityGoods).

class facts
    s : (real Sum) single.

clauses
    s(0).

class predicates %Вспомогательные предикаты
    длина : (A*) -> integer N.
    сумма_элем : (real* List) -> real Sum.
    среднее_списка : (real* List) -> real Average determ.

clauses
    длина([]) = 0.
    длина([_ | T]) = длина(T) + 1.

    сумма_элем([]) = 0.
    сумма_элем([H | T]) = сумма_элем(T) + H.

    среднее_списка(L) = сумма_элем(L) / длина(L) :-
        длина(L) > 0.

class predicates %Основные предикаты
    состав : (string Goods) -> string* Компоненты determ.
    весТовара : (string WeightGoods) -> string* Компоненты determ.
    весСырья : (string WeightRaw) -> string* Компоненты determ.


clauses
    состав(X) :-
        товар(N, X, _),
        write("Товар ", X, ":\n"),
        сырье(N, NPR, _),
        write("  ", NamePr),
        nl,
        fail.
    состав(X) :-
        товар(_, X, _),
        write("Конец списка"),
        nl.

    весТовара(X) :-
        товар(Npr, X, _, _),
        write(X, " используется в:\n"),
        сырье(Nbl, Npr, _),
        сырье(Nbl, NameBl, _),
        write("  ", NameBl),
        nl,
        fail.
    весТовара(X) :-
        товар(_, X, _, _),
        write("Конец списка"),
        nl.

    run() :-
        console::init(),
        reconsult("..\\out.txt", productionDB),
        товар("Коробка"),
        fail.
    run() :-
        товар("Бочка"),
        fail.
    run() :-
        succeed.

end implement main

goal
    console::run(main::run).

