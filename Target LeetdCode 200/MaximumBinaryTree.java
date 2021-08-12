class Solution {

    private TreeNode solve(int []nums, int i, int j) {
        if (i > j) return null;
        int k = i, pivot = i;
        while (k <= j) {
            if (nums[pivot] < nums[k]) {
                pivot = k;
            }
            k++;
        }
        TreeNode root = new TreeNode(nums[pivot]);
        root.left = solve(nums, i, pivot - 1);
        root.right = solve(nums, pivot + 1, j);
        return root;
    }

    public TreeNode constructMaximumBinaryTree(int[] nums) {
        return solve(nums, 0, nums.length - 1);
    }
}