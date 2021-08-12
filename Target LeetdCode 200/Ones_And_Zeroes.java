import java.util.*;


class Solution {
    private int [][][]dp;

    private int solve(int [][]arr, int i, int m, int n, int len) {
        if (m == 0 && n == 0) {
            return 0;
        }

        if (i == len) {
            return 0;
        }

        if (dp[i][m][n] >= 0) return dp[i][m][n];

        int include = 0, exclude = 0;
        if (m >= arr[i][0] && n >= arr[i][1])
            include = 1 + solve(arr, i + 1, m - arr[i][0], n - arr[i][1], len);
        exclude  = solve(arr, i + 1, m, n, len);
        return dp[i][m][n] = Math.max(include, exclude);
    }

    public int findMaxForm(String[] strs, int m, int n) {
        int len = strs.length;
        int [][]arr = new int[len][2];
        dp = new int[len + 1][m + 1][n + 1];

        for (int [][]rows : dp)
            for (int []row : rows)Arrays.fill(row, -1);

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < strs[i].length(); j++) {
                arr[i][strs[i].charAt(j) - '0']++;
            }
        }
        return solve(arr, 0, m, n, len);
    }
}