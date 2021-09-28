class Solution {
    int side[];
    private boolean allEqual() {
        for (int i = 0; i < 3; i++) {
            if (side[i] != side[i + 1] || side[i] == 0 || side[i + 1] == 0) return false;
        }
        return true;
    }

    private boolean solve(int [] nums, int i) {
        if (i == nums.length) {
            return allEqual();
        }

        boolean ans = false;

        for (int j = 0; j < 4 && !ans; j++) {
            side[j] += nums[i];
            ans |= solve(nums, i + 1);
            side[j] -= nums[i];
        }
        return ans;
    }

    public boolean makesquare(int[] stick) {
        side = new int[4];
        Arrays.fill(side, 0);
        return solve(stick, 0);
    }
}