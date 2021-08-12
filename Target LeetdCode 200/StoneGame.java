class Solution {

    int [][][]dp;
    private boolean solve(int []piles, int i, int j, int sum, int turn) {
        if (i > j) return sum > 0;

        if (dp[i][j][turn] > -1) {
            return dp[i][j][turn] == 1;
        }

        boolean ans = false;

        if (turn == 1) {
            ans |= solve(piles, i + 1, j, sum + piles[i], turn ^ 1);
            ans |= solve(piles, i , j - 1, sum + piles[j], turn ^ 1);
        } else {
            ans |= solve(piles, i + 1, j, sum - piles[i], turn ^ 1);
            ans |= solve(piles, i , j - 1, sum - piles[j], turn ^ 1);
        }
        dp[i][j][turn] = ans ? 1 : 0;
        return ans;
    }

    public boolean stoneGame(int[] piles) {
        int n = piles.length;
        dp = new int[n + 1][n + 1][2];

        for (int [][]rows : dp) {
            for (int []cols : rows) Arrays.fill(cols, -1);
        }

        return solve(piles, 0, piles.length - 1, 0, 1);
    }
}