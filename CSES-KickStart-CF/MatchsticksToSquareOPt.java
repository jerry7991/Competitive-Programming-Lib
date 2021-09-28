class Solution {
    int side[];
    int sum;
    private boolean allEqual() {
        for (int i = 0; i < 4; i++) {
            if (side[i] != sum) return false;
        }
        return true;
    }

    private boolean solve(int [] nums, int i) {
        if (i == nums.length) {
            return allEqual();
        }

        boolean ans = false;

        for (int j = 0; j < 4 && !ans; j++) {
            if (nums[i] + side[j] > sum) continue;
            side[j] += nums[i];
            ans |= solve(nums, i + 1);
            side[j] -= nums[i];
        }
        return ans;
    }

    public boolean makesquare(int[] stick) {
        side = new int[4];
        Arrays.fill(side, 0);
        Arrays.sort(stick);
        int j = 0, k = stick.length - 1;
        while (j < k) {
            int t = stick[j];
            stick[j] = stick[k];
            stick[k] = t;
            j++;
            k--;
        }
        sum = 0;
        for (int i : stick) sum += i;
        if (sum % 4 != 0) return false;
        sum /= 4;
        return solve(stick, 0);
    }
}