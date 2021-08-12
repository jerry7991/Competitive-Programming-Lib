class Solution {

    private void buildTree(int [][]tree, int[] nums, int i, int j, int itree) {
        if (i > j) return;

        if (i == j) {
            tree[itree][0] = i;
            tree[itree][1] = nums[i];
            return;
        }
        int m = (i + j) / 2;

        // Go for left subtree
        buildTree(tree, nums, i, m, itree * 2);

        // Go for right subtree
        buildTree(tree, nums, m + 1, j, itree * 2 + 1);

        //  Store the index and value of which subtree has greater element
        if (tree[2 * itree][1] > tree[2 * itree + 1][1]) {
            tree[itree][1] = tree[2 * itree][1];
            tree[itree][0] = tree[2 * itree][0];
        } else {
            tree[itree][1] = tree[2 * itree + 1][1];
            tree[itree][0] = tree[2 * itree + 1][0];
        }
    }

    private int[] getMax(int [][]tree, int i, int j, int ir, int jr, int itree) {

        //  OutSide or invalid interval
        if (i > j || i > jr || j < ir) {
            return new int[] { Integer.MIN_VALUE, Integer.MIN_VALUE};
        }


        //  Completely Inside
        if (i >= ir && j <= jr) {
            return tree[itree];
        }

        int m = (i + j) / 2;

        int []left = {Integer.MIN_VALUE, Integer.MIN_VALUE};
        int []right = {Integer.MIN_VALUE, Integer.MIN_VALUE};

        if (m > jr) {
            // Need to go only left subtree
            left = getMax(tree, i, m, ir, jr, itree * 2);
        } else if (m < ir) {
            //  Need to go only right subtree
            right = getMax(tree, m + 1, j, ir, jr, itree * 2 + 1);
        } else {
            // Need to go both subtree due to overlapping
            left = getMax(tree, i, m, ir, jr, itree * 2);
            right = getMax(tree, m + 1, j, ir, jr, itree * 2 + 1);
        }

        //  return the max value and their indices
        int []ans = {Integer.MIN_VALUE, Integer.MIN_VALUE};
        if (left[1] > right[1]) {
            ans[1] = left[1];
            ans[0] = left[0];
        } else {
            ans[1] = right[1];
            ans[0] = right[0];
        }
        return ans;
    }

    private TreeNode solve(int [][]tree, int []nums, int i, int j) {
        if (i > j) return null;

        //  Get the index of max value in the interval [i,j]
        int pivot = getMax(tree, 0, nums.length - 1, i, j, 1)[0];

        //  In case of invalid
        if (pivot < 0) return null;

        TreeNode root = new TreeNode(nums[pivot]);

        //  Go for left subtree
        root.left = solve(tree, nums, i, pivot - 1);

        //  Go for right subtree
        root.right  = solve(tree, nums, pivot + 1, j);
        return root;
    }

    public TreeNode constructMaximumBinaryTree(int[] nums) {
        int n = nums.length;
        int [][]tree = new int[4 * n][2];// 0 ->index, 1->value

        // Let's build tree
        buildTree(tree, nums, 0, n - 1, 1);
        return solve(tree, nums, 0, n - 1);
    }
}