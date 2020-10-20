import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class TaskJ {
    public static void main(String[] args) {
        try (PrintWriter outFile = new PrintWriter(new OutputStreamWriter(
                new FileOutputStream("nice.out"), StandardCharsets.UTF_8.name()));
             Scanner sc = new Scanner(new File("nice.in"), StandardCharsets.UTF_8.name())) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            outFile.println(getPattern(n, m));

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    static boolean isComp(int p, int c, int h) {
        int pc = -1;
        for (int i = 0; i < h; i++) {
            int cb = c % 2;
            int pb = p % 2;
            if (cb == pb) {
                if (cb == pc) {
                    return false;
                }
                pc = cb;
            } else {
                pc = -1;
            }
            p /= 2;
            c /= 2;
        }
        return true;
    }

    static int getPattern(int w, int h) {
        if (h > w) {
            int tmp = h;
            h = w;
            w = tmp;
        }
        if (h == 0) {
            return 0;
        }
        int[] cnt = new int[1 << h];
        for (int i = 0; i < (1 << h); i++) {
            cnt[i] = 1;
        }
        for (int i = 2; i < w + 1; i++) {
            int[] newCnt = new int[1 << h];
            for (int j = 0; j < (1 << h); j++) {
                newCnt[j] = 0;
            }
            for (int p = 0; p < (1 << h); p++) {
                for (int c = 0; c < (1 << h); c++) {
                    if (isComp(p, c, h)) {
                        newCnt[c] += cnt[p];
                    }
                }
            }
            cnt = newCnt;

        }
        int s = 0;
        for (int value : cnt) {
            s += value;
        }
        return s;
    }
}
