package misc;

public class Util {

    public static int factorial(int n) {
        if(n == 0 || n==1) {
            return 1;
        }
        return n * factorial(n-1);
    }

    // matrix multiplication
    public static Matrix mulMatrix(Matrix a, Matrix b) {
        Matrix resultMatrix = new Matrix(a.n, b.m);

        for (int i = 0; i < a.n; i++) {
            for (int j = 0; j < b.m; j++) {
                for (int k = 0; k < a.n; k++) {
                    resultMatrix.mat[i][j] += a.mat[i][k] * b.mat[k][j];
                }
            }
        }
        return resultMatrix;
    }

    public static void main(String[] args) {
        Matrix m = new Matrix({{1, 2}, {3, 4}});
        Matrix n = new Matrix(10, 10);
        System.out.println(mulMatrix(m, n));
    }
}