/*
import java.io.*;
import java.nio.charset.Charset;

public class Main {
    public static void main(String [] args) throws IOException {
        File inputFile = new File("src/inputTest.txt"); // Чтение файла
        File outputFile = new File("src/outputTest.txt"); // Запись файла

        Reader fis = new FileReader(inputFile, Charset.forName("utf-8")); // Конвертация сообщения в файле
        Writer fos = new FileWriter(outputFile, Charset.forName("utf-8"));  // Конвертация сообщения в файле

        char[] buffer = new char[1024]; // Записывает промежуточные данные
        int i; // Читает количество байтовых символов

        while((i = fis.read(buffer)) != -1) { // Когда байтовый символ равен 0 -> взят последний элемент
            fos.write(buffer, 0, i); // Запишет все данные из читаемого файла в буффер
        }

        fis.close(); // Закрываем поток ввода информации
        fos.close(); // Закрываем поток вывода информации

        System.out.println(file.getAbsoluteFile());
        System.out.println(file.canRead());
        System.out.println(file.canWrite());
        System.out.println(file.exists());
        System.out.println(file.getName());
        System.out.println(file.getParent());
        System.out.println(file.lastModified());
        System.out.println(file.isFile());
        System.out.println(file.isDirectory());

        File file = new File("C:\\Text\\text2\\text2.txt");
        String text = "Hello world!";
        out.println(text);



    }
}
*/

