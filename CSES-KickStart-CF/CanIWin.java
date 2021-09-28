class Solution {
    Map<Integer, Boolean> memo;
    private boolean solve(int mask, int mx, int desired) {
        if (desired <= 0) {
            return false; // current player will loose
        }

        if (memo.containsKey(mask)) {
            return memo.get(mask);
        }

        boolean res = false;
        for (int i = 0; i < mx && !res; i++) {
            if ((mask & (1 << i)) == 0) continue;
            int newMask = mask & ~(1 << i);
            res = !solve(newMask, mx, desired - i - 1);
        }
        memo.put(mask, res);
        return res;
    }
    public boolean canIWin(int mx, int desired) {
        int sum = ((mx + 1) * mx) / 2;
        if (desired > sum) return false;
        else if (desired <= 0) return true;
        memo = new HashMap<>();
        return solve((1 << mx) - 1, mx, desired);
    }
}