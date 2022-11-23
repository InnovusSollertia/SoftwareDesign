import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Function();
    }
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
}