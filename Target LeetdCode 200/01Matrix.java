class Solution {
    public int[][] updateMatrix(int[][] mat) {

        Queue<int[]> level = new LinkedList <int[]> ();
        int dist = 0, n = 0;

        int []dx = { -1, 1, 0, 0};
        int []dy = {0, 0, 1, -1};

        boolean [][]seen = new boolean[mat.length][mat[0].length];

        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[i].length; j++) {
                if (mat[i][j] == 0) {
                    level.add(new int[] {i, j});
                    seen[i][j] = true;
                }
            }
        }

        while ((n = level.size()) != 0) {
            dist++;
            while (n-- > 0) {
                int []temp = level.poll();
                int x = temp[0], y = temp[1];
                for (int i = 0; i < 4; i++) {
                    int r = x + dx[i], c = y + dy[i];
                    if (Math.min(r, c) < 0)continue;
                    if (r == mat.length || c == mat[0].length || seen[r][c]) continue;
                    level.push(new int[] {r, c});
                    mat[r][c] = dist;
                }
            }
        }
        return mat;
    }
}