import java.util.*;

public class Main {
    public static void main(String[] args) {
        Queue<String> myEnemies = new ArrayDeque<>();

        myEnemies.add("Kem Daniil");
        myEnemies.add("Secret Person 1582");
        myEnemies.add("Secret Person 0785");
        myEnemies.add("Secret Person 0957");
        myEnemies.add("Secret Person 0107");

        System.out.println("Мой первый враг: " + ((ArrayDeque<String>) myEnemies).peekFirst());
        System.out.println("Мой последний враг: " + ((ArrayDeque<String>) myEnemies).peekLast());
        System.out.println("Мой последний враг после удаления: " + ((ArrayDeque<String>) myEnemies).removeLast());
        System.out.println("Мой первый враг после удаления: " + ((ArrayDeque<String>) myEnemies).removeFirst());
        System.out.println("Все мои враги умерли? Ответ: " + ((ArrayDeque<String>) myEnemies).isEmpty());

        System.out.println(myEnemies);

    }
}






