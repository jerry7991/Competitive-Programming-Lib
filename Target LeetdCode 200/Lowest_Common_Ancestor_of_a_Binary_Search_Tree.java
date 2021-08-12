import TreeNode;
import java.util.ArrayList;

class Solution {
	private TreeNode solve(TreeNode root, TreeNode p, TreeNode q) {
		if (root == null) return  root;
		if (root.equals(p) || root.equals(q)) return root;
		TreeNode left = solve(root->left, p, q);
		TreeNode right = solve(root->right, p, q);

		if (left == null) return right;
		if (right == null) return left;
		return root;
	}

	public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
		return solve(root, p, q);
	}
}