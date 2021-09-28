class Solution {
    private static boolean solve(int []nums, int k, int i, int reqSum, int currSum, int mask) {
        if (k == 1) {
            return true;
        }
        boolean ans = false;
        if (currSum == reqSum && i != 0) {
            ans |= solve(nums, k - 1, 0, reqSum, 0, mask);
        } else {
            for (int j = i; j < nums.length && !ans; j++) {
                if ((mask & (1 << j)) != 0) continue;
                mask |= (1 << j);
                ans |= solve(nums, k, j + 1, reqSum, currSum + nums[j], mask);
                mask = mask & (~(1 << j));
            }
        }
        return ans;
    }
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum = 0, n = nums.length;
        for (int i : nums) sum += i;
        if (k > n || sum % k != 0) return false;
        sum /= k;
        return solve(nums, k, 0, sum, 0, 0);
    }
}

public class PartitionToKEqualSumSubsetsOpt {
    public static void main(String[] args) {

    }
}