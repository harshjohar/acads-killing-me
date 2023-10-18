package misc;

public class Matrix {
    public int n;
    public int m;
    int mat[][];

    public Matrix(int n, int m) {
        this.n = n;
        this.m = m;
        this.mat = new int[n][m];
    }

    public Matrix(int[][] mat) {
        this.mat = mat;
    }


    @Override
    public String toString() {
        StringBuilder st = new StringBuilder();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                st.append(mat[i][j]);
                st.append(' ');
            }
            st.append('\n');
        }
        return st.toString();
    }
}
