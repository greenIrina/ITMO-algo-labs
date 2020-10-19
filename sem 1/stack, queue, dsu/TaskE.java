import java.util.Scanner;

public class TaskE {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] stack = new int[100];
        int n = 0;
        String c;
        char ch;
        while (sc.hasNext()) {
            c = sc.next();
            if (c.equals(" ")) {
                continue;
            }
            ch = c.charAt(0);
            if (ch < '0' || ch > '9') {
                if (ch == '+') {
                    stack[n - 2] = stack[n - 2] + stack[n - 1];
                    n--;
                } else if (ch == '-') {
                    stack[n - 2] = stack[n - 2] - stack[n - 1];
                    n--;
                } else if (ch == '*') {
                    stack[n - 2] = stack[n - 2] * stack[n - 1];
                    n--;
                } else if (ch == '/') {
                    stack[n - 2] = stack[n - 2] / stack[n - 1];
                    n--;
                }
            } else {
                stack[n] = ch - '0';
                n++;
            }
        }
        System.out.println(stack[0]);
    }
}
