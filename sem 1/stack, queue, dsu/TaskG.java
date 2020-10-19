import java.util.Random;
import java.util.Scanner;

public class TaskG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        DSU dsu = new DSU(n);
        while (sc.hasNext()) {
            String op = sc.next();
            if (op.equals("union")) {
                int v = sc.nextInt(), u = sc.nextInt();
                dsu.union(--v, --u);
            } else {
                int v = sc.nextInt();
                v = dsu.get(v - 1);
                System.out.println((dsu.min[v] + 1) + " " + (dsu.max[v] + 1) + " " + dsu.size[v]);
            }
        }
    }

}

class DSU {
    int[] parent;
    int[] size;
    int[] min;
    int[] max;
    Random random;

    DSU(int n) {
        random = new Random();
        parent = new int[n];
        size = new int[n];
        min = new int[n];
        max = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
            min[i] = i;
            max[i] = i;
        }
    }

    void make(int v) {
        parent[v] = v;
        size[v] = 1;
    }

    int get(int v) {
        if (v == parent[v]) {
            return v;
        }
        return parent[v] = get(parent[v]);
    }

    void union(int v, int u) {
        int a = get(v), b = get(u);
        if (a != b) {
            if (size[a] < size[b]) {
                int t = a;
                a = b;
                b = t;
            }
            parent[b] = a;
            size[a] += size[b];
            min[a] = Math.min(min[a], min[b]);
            max[a] = Math.max(max[a], max[b]);
        }
    }
}
