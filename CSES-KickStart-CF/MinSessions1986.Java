class Solution {
    int [][]dp = new int[16][1 << 15];
    private int solve(int []nums, int sesstionTime, int remainTime, int mask) {
        if (mask == 0) {
            return 0;
        }

        if (dp[remainTime][mask] != -1) {
            return dp[remainTime][mask];
        }

        int ans = nums.length + 1;
        for (int i = 0; i < nums.length; i++) {
            if (((mask >> i) & 1) == 0) continue;
            int newMask = ~(1 << i) & mask;
            if (nums[i] <= remainTime) {
                ans = Math.min(ans, solve(nums, sesstionTime, remainTime - nums[i], newMask));
            } else {
                ans = Math.min(ans, solve(nums, sesstionTime, sesstionTime - nums[i], newMask) + 1);
            }
        }
        return dp[remainTime][mask] = ans;
    }

    public int minSessions(int[] tasks, int st) {
        int n = tasks.length;
        for (int []row : dp) {
            Arrays.fill(row, -1);
        }
        return solve(tasks, st, 0, (1 << n) - 1);
    }
}