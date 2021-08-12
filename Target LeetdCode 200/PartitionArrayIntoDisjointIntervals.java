import java.util.*;


class Solution {
    public int partitionDisjoint(int[] nums) {
        int n = nums.length, idx = 0;
        if (n == 1) return 0;
        int []leftMax = new int[n + 1];
        int []rightMin = new int[n + 1];
        leftMax[0] = Integer.MIN_VALUE; rightMin[n] = Integer.MAX_VALUE;
        for (int i = 1; i <= n; i++) {
            leftMax[i] = Math.max(leftMax[i - 1], nums[i - 1]);
            rightMin[n - i] = Math.min(rightMin[n - i + 1], nums[n - i]);
        }

        for (int i = 1; i < n; i++) {
            if (leftMax[i] <= rightMin[i]) return i;
        }
        return -1;

    }

    public int solve(int []nums) {
        int n = nums.length, idx = 0;
        int leftMax = nums[0], globalMax = nums[0];
        for (int i = 1; i < n; i++) {
            globalMax = Math.max(globalMax, nums[i]);
            if (nums[i] < leftMax) {
                leftMax = globalMax;
                idx = i;
            }
        }
        return idx + 1;
    }
}