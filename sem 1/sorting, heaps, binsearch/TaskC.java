import java.util.Scanner;

public class TaskC {
    public static void main(String[] args) {
        Scanner fs = new Scanner(System.in);
        int n = fs.nextInt();
        int[] temp = new int[n];
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = fs.nextInt();
        }
        System.out.print(calc(arr, temp, 0, n - 1));

    }

    static long calc(int[] arr, int[] temp, int left, int right) {
        long res = 0;
        if (right > left) {
            int mid = (right + left) / 2;
            res = calc(arr, temp, left, mid) +
                    calc(arr, temp, mid + 1, right) +
                    merge(arr, temp, left, mid + 1, right);
        }
        return res;
    }

    private static long merge(int[] arr, int[] tmp, int left, int mid, int right) {
        long res = 0;
        int i = left;
        int j = mid;
        int k = left;
        while (i < mid && j <= right) {
            if (arr[i] <= arr[j]) {
                tmp[k++] = arr[i++];
            } else {
                tmp[k++] = arr[j++];
                res += mid - i;
            }
        }
        while (j <= right) {
            tmp[k++] = arr[j++];
        }
        while (i < mid) {
            tmp[k++] = arr[i++];
        }


        for (i = left; i <= right; i++) {
            arr[i] = tmp[i];
        }
        return res;
    }
}
