import java.util.Scanner;

public class TaskE {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.nextLine();
        String s2 = sc.nextLine();
        int ans = distLev(s1, s2);
        System.out.println(ans);
    }

    static int distLev(String s1, String s2) {
        int m = s1.length(), n = s2.length();
        int[] tmp;
        int[] d = new int[n + 1];

        for (int i = 0; i <= n; i++) {
            d[i] = i;
        }

        for (int i = 1; i < m + 1; i++) {
            tmp = d;
            d = new int[n + 1];
            for (int j = 0; j < n + 1; j++) {
                if (j == 0) {
                    d[j] = i;
                } else {
                    int a;
                    if (s1.charAt(i - 1) != s2.charAt(j - 1)) {
                        a = 1;
                    } else {
                        a = 0;
                    }
                    if (d[j - 1] < tmp[j] && d[j - 1] < tmp[j - 1] + a) {
                        d[j] = d[j - 1] + 1;
                    } else if (tmp[j] < tmp[j - 1] + a) {
                        d[j] = tmp[j] + 1;
                    } else {
                        d[j] = tmp[j - 1] + a;
                    }
                }
            }
        }
        return d[n];
    }
}
