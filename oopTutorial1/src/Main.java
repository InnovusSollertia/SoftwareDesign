import java.time.*;
import java.util.Arrays;
import java.util.Calendar;
import java.util.Date;

public class Main {
    public static void main(String[] args) {
        Calendar calendar = Calendar.getInstance();

        int minute = calendar.get(Calendar.MINUTE);
        int hour = calendar.get(Calendar.HOUR);
        System.out.println("Ваше время: " + hour + minute);

        System.out.println(calendar.get(Calendar.DAY_OF_MONTH));
        calendar.add(Calendar.DAY_OF_MONTH, 15);
        System.out.println(calendar.get(Calendar.DAY_OF_MONTH));

        System.out.println(calendar.get(Calendar.SECOND) + ":" + calendar.get(Calendar.MINUTE) + ":" + calendar.get(Calendar.HOUR));
        calendar.clear(); // Clear the calendar
        System.out.println(calendar.get(Calendar.SECOND) + ":" + calendar.get(Calendar.MINUTE) + ":" + calendar.get(Calendar.HOUR));

        calendar.add(Calendar.MINUTE, 50);
        System.out.println(calendar.get(Calendar.SECOND) + ":" + calendar.get(Calendar.MINUTE) + ":" + calendar.get(Calendar.HOUR));

        System.out.println(calendar.getTime());

        System.out.println(calendar.get(Calendar.YEAR));
        calendar.set(Calendar.YEAR, 2000);
        System.out.println(calendar.get(Calendar.YEAR));

        // LocalTime localTime = LocalTime.now();

        // ZonedDateTime zonedDateTime = ZonedDateTime.of(LocalDateTime.of(2022, 11, 23, 14, 47), ZoneId.of("Asia/Almaty"));
        //System.out.println(localTime);
        // System.out.println(zonedDateTime);
        System.out.println(ZoneId.systemDefault());

        System.out.println("");
        System.out.println(ZoneId.getAvailableZoneIds());


        //System.out.println(localTime.getHour());

        System.out.println("");
        LocalTime localTime = LocalTime.now(); //Содержит только врем
        System.out.println(localTime);
        localTime.plusHours(2);
        LocalTime newLocalTime = localTime.plusHours(5);
        System.out.println("Старое время: " + localTime);
        System.out.println("Новое время: " + newLocalTime);
        localTime = localTime.plusHours(3);
        System.out.println("Обновленное старое время: " + localTime);


        Period period = Period.of(2000, 12, 5);
        System.out.println(period);

        Date date = new Date();
        System.out.println(date);

        Instant instant = date.toInstant();

        ZonedDateTime zonedDateTime = instant.atZone(ZoneId.of("Asia/Almaty"));
        System.out.println(zonedDateTime);


    }
}








/*
            // Function();

    private static void Function() {
        int a = 1;
        int b = 2;
        int c = 3;
        int d = 4;
        int result = 5;
        result*=d;

        int[] m ={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int[] m2 = Arrays.copyOf(m, m.length);
        int[] m3 = Arrays.copyOfRange(m, 5, 7);

        switch(a) {
            case 1:
                System.out.println((a * (a + 1) / 2) + "");
                for (int i = 0; i <= 5; i++){
                    System.out.println(i); }
                System.out.println("Case 50 it's worked! " + a + "M[1] = " + m[1]);
                System.out.println("m2 = " + m2[9]);
                System.out.println("m3 = " + m3[1]);
                break;
            case 2:
                System.out.println((b * (b + 1) / 2) + "");
                for (int i = 5; i <= 10; i++){
                    System.out.println(i); }
                System.out.println("Case 10 it's worked! "+ b + "M[2] = " + m[2]);
                break;
            case 3:
                System.out.println((c * (c + 1) / 2) + "");
                for (int i = 10; i <= 15; i++){
                    System.out.println(i); }
                System.out.println("Case 5 it's worked! "+ c + "M[3] = " + m[3]);
                break;
                default:
                    for (int i = 15; i <= 20; i++){
                        System.out.println(i); }
                    System.out.println("ondition not workder!" + d + "M[4] = " + m[4]);
                    break;

        }
    }
     */