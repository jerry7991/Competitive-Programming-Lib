import java.util.*;

class Solution {
    private static int [][]dp;
    private static int offset;
    private static int solve(int []nums, int target, int i) {
        if (i == nums.length) return target == 0 ? 1 : 0;

        if (dp[i][target + offset] != Integer.MIN_VALUE) {
            return dp[i][target + offset];
        }

        int pos = solve(nums, target - nums[i], i + 1);
        int neg = solve(nums, target + nums[i], i + 1);

        return dp[i][target + offset] = (pos + neg);
    }

    public int findTargetSumWays(int[] nums, int target) {
        int n = nums.length;

        dp = new int[n + 1][3000];
        for (int i = 0; i <= n; i++) Arrays.fill(dp[i], Integer.MIN_VALUE);
        offset = 1000;

        return solve(nums, target, 0);
    }

}