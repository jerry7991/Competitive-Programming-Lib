class Solution {
    public int longestIncreasingPath(int[][] matrix) {
        int n = matrix.length, m = matrix[0].length;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        int [][]indegree = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m ; j++ ) {
                for (int k = 0; k < 4; k++) {
                    int r = i + dx[k], c = j + dy[k];
                    if (r < 0 || c < 0 )continue;
                    if (r >= n || c >= m) continue;
                    if (matrix[i][j] >= matrix[r][c]) continue;
                    indegree[r][c]++;
                }
            }
        }

        Queue<int[]> level = new LinkedList<int[]>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (indegree[i][j] == 0) level.add(new int[] {i, j});
            }
        }
        int ans = 0;
        while (level.size() > 0) {
            int l = level.size();
            ans++;
            while (l-- > 0) {
                int [] temp = level.poll();
                int i = temp[0], j = temp[1];
                for (int k = 0; k < 4; k++) {
                    int r = i + dx[k], c = j + dy[k];
                    if (Math.min(r, c) < 0 || r == n || c == m || matrix[i][j] >= matrix[r][c] || --indegree[r][c] > 0) continue;
                    level.add(new int[] {r, c});
                }
            }
        }
        return ans;
    }
}