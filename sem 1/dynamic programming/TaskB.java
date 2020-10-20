import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class TaskB {
    public static void main(String[] args) {
        try (PrintWriter outFile = new PrintWriter(new OutputStreamWriter(
                new FileOutputStream("output.txt"), StandardCharsets.UTF_8.name()));
             FastScanner fs = new FastScanner(new File("input.txt"), StandardCharsets.UTF_8.name())) {
            int n = fs.nextInt();
            int m = fs.nextInt();
            int[][] a = new int[n][m], w = new int[n][m];
            String[][] p = new String[n][m];
            List<String> actions = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a[i][j] = fs.nextInt();
                }
            }
            w[0][0] = a[0][0];
            for (int i = 1; i < n; i++) {
                w[i][0] = w[i - 1][0] + a[i][0];
                p[i][0] = "D";
            }
            for (int j = 1; j < m; j++) {
                w[0][j] = w[0][j - 1] + a[0][j];
                p[0][j] = "R";
            }
            for (int i = 1; i < n; i++) {
                for (int j = 1; j < m; j++) {
                    if (w[i - 1][j] > w[i][j - 1]) {
                        w[i][j] = w[i - 1][j] + a[i][j];
                        p[i][j] = "D";
                    } else {
                        w[i][j] = w[i][j - 1] + a[i][j];
                        p[i][j] = "R";
                    }
                }
            }

            outFile.println(w[n - 1][m - 1]);
            int i = n - 1, j = m - 1;
            while (i != 0 || j != 0) {
                if (p[i][j].equals("D")) {
                    actions.add("D");
                    i--;
                } else {
                    actions.add("R");
                    j--;
                }
            }
            Collections.reverse(actions);
            for (String action : actions) {
                outFile.print(action);
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

