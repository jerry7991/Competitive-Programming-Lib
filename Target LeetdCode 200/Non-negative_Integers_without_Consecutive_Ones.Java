class Solution {
    int solve(int n, int i, int last) {
        if (i == n) {
            return 1;
        }
        int ans = 0;
        if (last == 0) {
            ans =  solve(n, i + 1, 0);
            ans  +=  solve(n, i + 1, 1);
        } else {
            ans = solve(n, i + 1, 0);
        }
        return ans;
    }

    public int findIntegers(int n) {
        int []f = new int[32];
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < 32; i++) f[i]  = f[i - 1] + f[i - 2];

        int i = 30, sum = 0, prevBit = 0;
        while (i >= 0) {
            if ((n & (1 << i)) != 0) {
                sum += f[i];
                if (prevBit == 1) {
                    sum--;
                    break;
                }
                prevBit = 1;
            } else {
                prevBit = 0;
            }
            i--;
        }
        return sum + 1;
    }
}