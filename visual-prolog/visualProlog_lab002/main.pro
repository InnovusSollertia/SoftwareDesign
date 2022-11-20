% UlugbekRUDN
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
    open core, file, stdio

domains
    unit = кг; т; л; шт.

class facts - productionDB
    сырье : (integer ID, string Name, string Type, string Weight).
    товар : (integer ID, string Name, string Type, string Weight, integer QuantityGoods).

class facts
    s : (real Sum) single.

clauses
    s(0).

class predicates
    состав : (string Goods) nondeterm.
    весТовара : (string WeightGoods) nondeterm.
    весСырья : (string WeightRaw) nondeterm.

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
