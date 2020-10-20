import java.io.*;
import java.util.NoSuchElementException;
import java.util.StringTokenizer;

//FastScanner implemented by me for faster input reading
public class FastScanner implements AutoCloseable {

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
