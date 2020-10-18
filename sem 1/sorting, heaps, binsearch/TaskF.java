import java.util.Scanner;

public class TaskF {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] arr1 = new int[n];
        int[] arr2 = new int[k];
        for (int i = 0; i < n; i++) {
            arr1[i] = sc.nextInt();
        }
        for (int i = 0; i < k; i++) {
            arr2[i] = sc.nextInt();
        }
        for (int i = 0; i < k; i++) {
            int x = arr2[i];
            int posL = binSearchLeft(arr1, x);
            int posR = binSearchRight(arr1, x);
            int a = arr1[posL];
            int b = arr1[posR];
            if (Math.abs(a - x) <= Math.abs(b - x)) {
                System.out.println(a);
            } else {
                System.out.println(b);
            }
        }
    }
    static int binSearchLeft(int[] arr, int x) {
        int l = 0;
        int r = arr.length - 1;
        int ans = 0;
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

    static int binSearchRight(int[] arr, int x) {
        int l = 0;
        int r = arr.length - 1;
        int ans = r;
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
}
