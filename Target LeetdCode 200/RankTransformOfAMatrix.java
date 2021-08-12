class Solution {
    private static int rankRow(int [][]mat, int i, int M, int x) {
        int ans = 0;
        for (int j = 0; j < M; j++) {
            if (mat[i][j] < x) ans++;
        }
        return ans;
    }

    private static int rankCol(int [][]mat, int i, int n, int x) {
        int ans = 0;
        for (int j = 0; j < n; j++) {
            if (mat[j][i] < x) ans++;
        }
        return ans;
    }

    public int[][] matrixRankTransform(int[][] mat) {

        int n = mat.length, m = mat[0].length;

        int [][]matrix = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                matrix[i][j] = rankRow(mat, i, m, mat[i][j]) + rankCol(mat, j, n, mat[i][j]) + 1;
            }
        }
        return matrix;
    }
}