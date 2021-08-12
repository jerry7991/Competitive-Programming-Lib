import java.util.*;

class Solution {
    private int solve(int []nums, int i, int n) {
        int []dp = new int [n + 1];
        Arrays.fill(dp, 0);

        while (i < n) {
            if (i < 2) {
                dp[i] = Math.max(nums[i], i > 0 ? dp[i - 1] : 0);
            } else {
                dp[i] = Math.max(nums[i] + dp[i - 2], dp[i - 1]);
            }
            i++;
        }
        return dp[n - 1];
    }

    public int rob(int[] nums) {
        if (nums.length == 1) return nums[0];
        return Math.max(solve(nums, 0, nums.length - 1) , solve(nums, 1, nums.length));
    }
}