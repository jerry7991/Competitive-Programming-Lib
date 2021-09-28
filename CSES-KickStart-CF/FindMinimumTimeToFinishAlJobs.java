class Solution {
    int totalTime[];
    int n;
    private int solve(int []jobs, int i, int k) {
        if (i == n) {
            int res = 0;
            for (int j : totalTime) {
                res = Math.max(res, j);
            }
            return res;
        }
        int res = Integer.MAX_VALUE;
        for (int j = 0; j < k; j++) {
            totalTime[j] += jobs[i];
            res = Math.min(res, solve(jobs, i + 1, k));
            totalTime[j] -= jobs[i];
        }
        return res;
    }
    public int minimumTimeRequired(int[] jobs, int k) {
        n = jobs.length;
        totalTime = new int[n];
        return solve(jobs, 0, k);
    }
}