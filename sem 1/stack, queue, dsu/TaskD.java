import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class TaskD {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int goblin;
        boolean isOdd = false;
        char c;
        Node head = null, end = null, center = null;
        for (int i = 0; i < n; i++) {
            c = sc.next().charAt(0);
            if (c == '-') {
                System.out.println(head.num);
                head = head.next;
                if (head == null) {
                    center = null;
                    end = null;
                } else if (!isOdd) {
                    center = center.next;
                }
            } else {
                goblin = sc.nextInt();
                Node temp = new Node();
                temp.num = goblin;
                temp.next = null;
                if (head == null) {
                    head = temp;
                    center = temp;
                    end = temp;
                } else {
                    if (c == '+') {
                        end.next = temp;
                        end = end.next;
                    }
                    if (c == '*') {
                        temp.next = center.next;
                        center.next = temp;
                        if (temp.next == null) {
                            end = end.next;
                        }
                    }
                    if (!isOdd) {
                        center = center.next;
                    }
                }
            }
            isOdd = !isOdd;
        }
    }
}

class Node {
    int num;
    Node next;
}

class Scanner implements AutoCloseable {

    BufferedReader br;
    StringTokenizer st;

    Scanner(InputStream is) {
        br = new BufferedReader(new InputStreamReader(is));
    }

    String next() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                String line = br.readLine();

                if (line == null) {
                    return null;
                }
                st = new StringTokenizer(line);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(next());
    }


    public void close() throws IOException {
        br.close();
    }
}
