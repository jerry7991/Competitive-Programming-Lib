/* Signature of four required functions is given in the code. You can create other functions as well if you need.
*  Also you should submit your code even if you are not done with all the functions.
*/

public class mat {
    int [][] matrix;

    mat(int [][] mat) {
        matrix = mat;
    }


    public static mat add(mat a, mat b) {
        for (int i = 0; i < a.matrix.length; i++) {
            for (int j = 0; j < a.matrix[i].length; j++) {
                a.matrix[i][j] += b.matrix[i][j];
            }
        }
    }

    public static mat multiply(mat a, mat b) {
        int ra = a.matrix.length, cb = b.matrix[0].length;

        int [][] mul = new int[ra][cb];

        for (int i = 0; i < ra; i++) {
            for (int j = 0; j < rb; j++) {
                for (int k = 0; k < a.matrix[0].length; k++) {
                    for (int l = 0; l < b.matrix.length; l++) {
                        mal[i][j] += (a.matrix[i][k] * b.matrix[l][j]);
                    }
                }
            }
        }

        mat mt = new mat(mul);
        return mt;
    }

    public static mat transpose(mat m) {
        int r = m.matrix.length, c = m.matrix[0].length;
        int [][]trans = new int[c][r];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                trans[i][j] = m.matrix[j][i];
            }
        }
        m.matrix = trans;
        return m;
    }

    public static mat rotate(mat m) {
        int r = m.matrix.length, c = m.matrix[0].length;
        for (int i = 0; i < r / 2; i++) {
            for (int j = 0; j < c / 2; j++) {
                int x = m.matrix[i][j];
                m.matrix[i][j] = m.matrix[i][c - 1 - j];
                m.matrix[i][c - 1 - j] = m.matrix[r - 1 - i][c - 1 - j];
                m.matrix[r - 1 - i][c - 1 - j] = m.matrix[r - i - 1][j];
                m.matrix[r - i - 1][j] = x;
            }
        }
        return m;
    }

    public  void print() {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}