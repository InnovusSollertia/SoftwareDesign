/* Linked list with hashcode
// Создаем связные списки
        LinkedList<Integer> cities = new LinkedList<>();

        // Добавляем элементы
        cities.add(15);
        cities.add(157741);
        cities.add(45);
        cities.add(7585);
        cities.add(55);
        cities.add(1587);
        cities.add(150);

        System.out.println("");
        System.out.println("Unsorted first list: " + cities); // Выводим неотсортированнный первый список

        LinkedList numbers = (LinkedList) cities.clone();  // Клонируем элементы из первого списка

        Collections.sort(cities); // Сортируем элементы первого списка
        System.out.println("");
        System.out.println("Sorted first list: " + cities); // Выводим отсортированный первый список

        System.out.println("");
        System.out.println("Unsorted second list: " + numbers); // Выводим неотсортированный второй список
        System.out.println("");
        System.out.println("Sorted second list:" + numbers); // Выводим сортированный второй список

        numbers.add(1, 850); // Добавляем элементы в позицию 2 со значением 850
        numbers.add(2, 15890); // Добавляем элементы в позицию 9 со значением 15890

        Collections.sort(numbers); // Сортируем элементы первого списка
        System.out.println("");
        System.out.println("Second list with new elements: " + numbers); // Выводим отсортированный первый список

        System.out.println("Hashcode of Cities" + cities.hashCode()); // Выводим хэш-код №1
        System.out.println("HashCode of Numbers: " + numbers.hashCode()); // Выводим хэш-код №2
*/