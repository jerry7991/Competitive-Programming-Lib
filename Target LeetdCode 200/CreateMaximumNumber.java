class Solution {
    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
        int n = nums1.length, m = nums2.length;

        Stack<Integer> stack = new Stack<>();
        int i = 0, j = 0;

        while (i < n || j < m) {
            int max = Math.max(i < n ? nums1[i] : -1, j < m ? nums2[j] : -1);
            while (!stack.isEmpty() && (k - stack.size()) < (n - i + m - j) && stack.peek() < max) stack.pop();
            stack.push(max);
            if (i < n && nums1[i] == max) {
                while ((k - stack.size()) < (n - i + m - j) && nums2[j] < max)j++;
                i++;
            } else {
                while ((k - stack.size()) < (n - i + m - j) && nums1[i] < max)i++;
                j++;
            }
        }

        int []ans = new int[k];

        while (!stack.isEmpty()) {
            ans[--k] = stack.peek();
            stack.pop();
        }
        return ans;
    }
}