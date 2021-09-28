class Solution {
    int totalTime[];
    int n, res;
    private int solve(int []jobs, int i, int k, int curr) {
        if (curr >= res) {
            return res;
        }

        if (i == jobs.length) {
            return res = curr;
        }

        for (int j = 0; j < k; j++) {
            totalTime[j] += jobs[i];
            res = Math.min(res, solve(jobs, i + 1, k, Math.max(curr, totalTime[i])));
            totalTime[j] -= jobs[i];
        }
        return res;
    }
    public int minimumTimeRequired(int[] jobs, int k) {
        n = jobs.length;
        res = 0;
        for (int i : jobs) res += i;
        Arrays.sort(jobs);
        totalTime = new int[n];
        return solve(jobs, 0, k, 0);
    }
}