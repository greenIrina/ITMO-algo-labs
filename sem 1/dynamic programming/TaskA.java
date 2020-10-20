import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class TaskA {
    public static void main(String[] args) {
        try (PrintWriter outFile = new PrintWriter(new OutputStreamWriter(
                new FileOutputStream("output.txt"), StandardCharsets.UTF_8.name()));
             FastScanner fs = new FastScanner(new File("input.txt"), StandardCharsets.UTF_8.name())) {
            int n = fs.nextInt();
            int k = fs.nextInt();
            int[] a = new int[n + 1];
            for (int i = 2; i < n; i++) {
                a[i] = fs.nextInt();
            }

            int[] d = new int[n + 1];
            int[] p = new int[n + 1];
            List<Integer> ans = new ArrayList<>();
            for (int i = 2; i < n + 1; i++) {
                int mx = i - 1;
                for (int j = Math.max(1, i - k); j < i; ++j) {
                    if (d[j] > d[mx]) {
                        mx = j;
                    }
                }
                d[i] = d[mx] + a[i];
                p[i] = mx;
            }
            outFile.println(d[n]);
            int i = n;
            ans.add(i);
            while (i > 1) {
                i = p[i];
                ans.add(i);
            }
            outFile.println(ans.size() - 1);
            Collections.reverse(ans);
            for (int j = 0; j != ans.size(); ++j) {
                outFile.print(ans.get(j) + " ");
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

class FastScanner implements AutoCloseable {

    private BufferedReader br;
    private StringTokenizer st;
    private String curLine;
    private String[] tokens;
    private int pos;

    FastScanner(InputStream is) {
        br = new BufferedReader(new InputStreamReader(is));
    }

    FastScanner(File f, String encodingName) throws FileNotFoundException, UnsupportedEncodingException {
        br = new BufferedReader(new InputStreamReader(new FileInputStream(f), encodingName));
    }

    FastScanner(String s) {
        br = new BufferedReader(new StringReader(s));
    }

    String nextLine() {
        if (curLine == null) {
            String tmp = readLine();
            if (tmp == null) {
                throw new NoSuchElementException();
            }
            return tmp;
        }

        String tmp = curLine;
        curLine = null;
        return tmp;
    }

    boolean hasNextLine() {
        if (curLine == null) {
            curLine = readLine();
            return curLine != null;
        }
        return true;
    }

    int nextInt() {
        if (st == null) {
            updateTokenizer();
        }
        curLine = null;
        if (pos + 1 == tokens.length) {
            st = null;
        }
        try {
            int x = Integer.parseInt(tokens[pos]);
            pos++;
            return x;
        } catch (NumberFormatException e) {
            throw new NoSuchElementException();
        }
    }

    boolean hasNextInt() {
        if (st == null) {
            try {
                updateTokenizer();
            } catch (NoSuchElementException e) {
                return false;
            }
        }
        try {
            Integer.parseInt(tokens[pos]);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }

    public void close() throws IOException {
        br.close();
    }

    private String readLine() {
        try {
            return br.readLine();
        } catch (IOException e) {
            throw new IllegalStateException(e);
        }
    }

    private void updateTokenizer() {
        pos = 0;
        if (curLine == null) {
            curLine = readLine();
        }
        if (curLine == null) {
            throw new NoSuchElementException();
        }
        st = new StringTokenizer(curLine);
        int cnt = st.countTokens();
        tokens = new String[cnt];
        for (int i = 0; i < cnt; i++) {
            tokens[i] = st.nextToken();
        }
    }
}
