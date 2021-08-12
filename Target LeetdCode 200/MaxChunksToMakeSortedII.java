class Solution {
    public int maxChunksToSorted(int[] arr) {
        int n = arr.length;

        int []max = new int[n];
        int []min = new int[n];

        max[0] = arr[0];
        min[n - 1] = arr[n - 1];

        for (int i = 1; i < n; i++) {
            max[i] = Math.max(max[i - 1], arr[i]);
            min[n - i - 1] = Math.min(min[n - i], arr[n - i - 1]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (max[i] <= min[i + 1]) ans++;
        }
        return ans;
    }
}