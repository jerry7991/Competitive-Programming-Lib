import java.util.*;

class Solution {
	public int maxSumAfterPartitioning(int[] arr, int k) {
		int n = arr.length;
		int []dp = new int[n + 1];
		dp[0] = 0;

		for (int i = 1; i <= n; i++) {
			int max = 0;
			for (int j = 1; j <= k && i - j >= 0; j++) {
				max = Math.max(max, arr[i - j]);
				dp[i] = Math.max(dp[i - j] + max * j, dp[i]);
			}
		}
		return dp[n];
	}
}

