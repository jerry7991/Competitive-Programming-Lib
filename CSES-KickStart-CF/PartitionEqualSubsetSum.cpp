class Solution {
    int n;
    private boolean solve(int []nums, int set1, int set2, int i) {
        if (i == n) {
            return set1 == set2;
        }
        return solve(nums, set1 + nums[i], set2, i + 1) || solve(nums, set1, set2 + nums[i], i + 1);
    }

    public boolean canPartition(int[] nums) {
        n = nums.length;
        return solve(nums, 0, 0, 0);
    }
}