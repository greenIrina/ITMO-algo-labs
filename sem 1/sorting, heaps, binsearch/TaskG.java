import java.util.Scanner;

public class TaskG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt() - 1;
        int x = sc.nextInt();
        int y = sc.nextInt();
        long cnt1 = (long) Math.floor((double) n * y / (x + y));
        long ans1 = Math.max(cnt1 * x, (n - cnt1) * y);
        long cnt2 = (long) Math.ceil((double) n * y / (x + y));
        long ans2 = Math.max(cnt2 * x, (n - cnt2) * y);
        System.out.println(Math.min(x, y) + Math.min(ans1, ans2));
    }
}
