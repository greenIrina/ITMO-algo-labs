import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class TaskF {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        boolean isOkay = true;
        int that = 0;
        int[] p = new int[n + 1];
        int[][] d = new int[n + 1][n + 1];
        int[][][] c = new int[n + 1][n + 1][2];
        if (n == 0) {
            System.out.println(0);
            System.out.println(0 + " " + 0);
        } else {
            for (int i = 1; i < n + 1; i++) {
                p[i] = sc.nextInt();
            }
            for (int i = 0; i < n + 1; i++) {
                for (int j = 0; j < n + 1; j++) {
                    d[i][j] = 40000;
                }
            }
            if (p[1] > 100) {
                d[1][0] = 40000;
                d[1][1] = p[1];
            } else {
                d[1][0] = p[1];
                d[1][1] = 40000;
            }
            for (int i = 2; i < n + 1; i++) {
                if (p[i] < 101) {

                    c[i][n][0] = -1;
                    c[i][n][1] = -1;
                    d[i][n] = 40000;

                    for (int j = n - 1; j > -1; j--) {
                        if (d[i - 1][j] + p[i] < d[i - 1][j + 1] + 1) {
                            d[i][j] = d[i - 1][j] + p[i];
                        } else {
                            d[i][j] = d[i - 1][j + 1];
                        }

                        c[i][j][0] = i - 1;
                        c[i][j][1] = j;

                        if (d[i][j] == d[i - 1][j + 1]) {
                            c[i][j][0] = i - 1;
                            c[i][j][1] = j + 1;
                        }
                    }
                    isOkay = true;
                } else {
                    d[i][0] = d[i - 1][1];
                    c[i][0][0] = i - 1;
                    c[i][0][1] = 1;
                    for (int j = 1; j < n; j++) {

                        c[i][j][0] = i - 1;
                        c[i][j][1] = j - 1;

                        if (d[i - 1][j - 1] + p[i] < d[i - 1][j + 1] + 1) {
                            d[i][j] = d[i - 1][j - 1] + p[i];
                        } else {
                            d[i][j] = d[i - 1][j + 1];
                        }


                        if (d[i][j] == d[i - 1][j + 1]) {
                            c[i][j][0] = i - 1;
                            c[i][j][1] = j + 1;
                        }

                    }

                    isOkay = false;

                    c[i][n][0] = i - 1;
                    c[i][n][1] = n - 1;

                    d[i][n] = d[i - 1][n - 1] + p[i];
                }
            }
            int s = d[n][0];
            int l = 0, b = 0, v = 0;
            for (int u = 1; u < n + 1; u++) {
                if (d[n][u] < d[n][b] + 1) {
                    s = d[n][u];
                    l = v = b = u;
                    that++;
                } else {
                    that--;
                }
            }
            List<Integer> t = new ArrayList<>();
            int q = n;
            while (q > 1) {
                if (c[q][v][1] == v + 1 && c[q][v][0] == q - 1) {
                    t.add(q);
                    v += 1;
                    q -= 1;

                } else {
                    int h = q;
                    q = c[h][v][0];
                    v = c[h][v][1];
                }
            }
            Collections.sort(t);
            System.out.println(s);
            int m = t.size();
            System.out.println(l + " " + m);
            for (Integer integer : t) {
                System.out.println(integer);
            }
        }

    }
}
