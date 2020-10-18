import java.util.Scanner;

public class TaskH {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long w = sc.nextInt();
        long h = sc.nextInt();
        long n = sc.nextInt();
        long len = 1;
        while (!((len / w) * (len / h) >= n)) {
            len *= 2;
        }
        long a = len / 2;
        while (a < len - 1) {
            long b = (a + len) / 2;
            if ((b / w) * (b / h) >= n) {
                len = b;
            } else {
                a = b;
            }
        }
        System.out.println(len);
    }
}
