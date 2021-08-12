class Solution {
    public boolean stoneGame(int[] piles) {
        int n = piles.length;

        int [][]dp = new int[n][n];
        for (int i = 0; i < n; i++) dp[i][i] = piles[i];

        for (int i = 0; i < n - 1; i++) {
            for (int j = 1; j < n - i; j++) {
                dp[i][i + j] = Math.max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] > 0;
    }
}