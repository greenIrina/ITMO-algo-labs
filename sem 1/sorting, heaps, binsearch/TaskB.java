import java.util.Scanner;

public class TaskB {
    public static void main(String[] args) {
        Scanner line = new Scanner(System.in);
        String[] array1 = line.nextLine().split(" ");
        Integer[] array2 = new Integer[array1.length];
        int i = 0;
        for (String part : array1) {
            array2[i++] = Integer.parseInt(part);
        }
        int[] array = new int[101];
        for (Integer value : array2) {
            array[value] += 1;
        }
        int pos = 0;
        for (int num = 0; num < 101; num++) {
            for (int j = 0; j < array[num]; j++) {
                array2[pos] = num;
                pos++;
            }
        }
        for (Integer integer : array2) {
            System.out.print(integer + " ");
        }
    }
}
