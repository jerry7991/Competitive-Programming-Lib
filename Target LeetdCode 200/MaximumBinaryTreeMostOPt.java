class Solution {

    public TreeNode constructMaximumBinaryTree(int[] nums) {
        Stack<TreeNode> stack = new Stack<>();
        for (int i : nums) {
            TreeNode curr = new TreeNode(i);
            while (!stack.isEmpty() && stack.peek().val < i) {
                curr.left = stack.peek();
                stack.pop();
            }

            if (!stack.isEmpty()) {
                stack.peek().right = curr;
            }
            stack.push(curr);
        }
        return stack.peek();
    }
}