import java.util.Scanner;

public class TaskJ {
    public static double time(double x, double a, int v1, int v2) {
        return Math.sqrt(x * x + (1 - a) * (1 - a)) / v1 +
                Math.sqrt(a * a + (1 - x) * (1 - x)) / v2;
    }

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int vp = scanner.nextInt();
            int vf = scanner.nextInt();
            double a = scanner.nextDouble();
            double left = 0;
            double right = 1;
            while (right - left >= 1e-7) {
                double x1 = left + (right - left) / 3;
                double x2 = right - (right - left) / 3;
                if (time(x1, a, vp, vf) < time(x2, a, vp, vf)) {
                    right = x2;
                } else {
                    left = x1;
                }
            }
            System.out.println(left);
        }
    }
}
