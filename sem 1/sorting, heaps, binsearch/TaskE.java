import java.util.Arrays;
import java.util.Scanner;

public class TaskE {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);

        int k = sc.nextInt();
        for (int i = 0; i < k; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            int posL = binSearchLeft(arr, l);
            int posR = binSearchRight(arr, r);
            if (posL == -1 || posR == -1) {
                System.out.print(0 + " ");
            } else {
                System.out.print(Math.max(0, posR - posL + 1) + " ");
            }
        }
    }

    static int binSearchLeft(int[] arr, int x) {
        int l = 0;
        int r = arr.length - 1;
        int ans = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (arr[m] >= x) {
                r = m - 1;
                ans = m;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }

    static int binSearchRight(int[] arr, int x) {
        int l = 0;
        int r = arr.length - 1;
        int ans = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (arr[m] <= x) {
                l = m + 1;
                ans = m;
            } else {
                r = m - 1;
            }
        }
        return ans;
    }
}
