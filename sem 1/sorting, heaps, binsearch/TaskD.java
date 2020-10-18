import java.util.Scanner;

public class TaskD {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Heap heap = new Heap(n);
        for (int i = 0; i < n; i++) {
            int op = sc.nextInt();
            if (op == 0) {
                heap.insert(sc.nextInt());
            } else {
                System.out.println(heap.extract());
            }
        }
    }
}

class Heap {
    int[] heap;
    int heapSize;

    Heap(int n) {
        heapSize = 0;
        heap = new int[n];
    }

    void insert(int v) {
        heap[heapSize] = v;
        int i = heapSize++;
        while (heap[i] > heap[(i - 1) / 2]) {
            swap(i, (i - 1) / 2);
            i = (i - 1) / 2;
        }
    }

    int extract() {
        int ans = heap[0];
        heap[0] = heap[heapSize - 1];
        heapSize--;
        int i = 0;
        while (2 * i + 1 < heapSize) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int j = l;
            if (r < heapSize && heap[r] > heap[l]) {
                j = r;
            }
            if (heap[i] >= heap[j]) {
                break;
            }
            swap(i, j);
            i = j;
        }
        return ans;
    }

    void swap(int i, int j) {
        int t = heap[i];
        heap[i] = heap[j];
        heap[j] = t;
    }
}