import java.util.*;
class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { val = x; this.left = null; this.right = null; }
};
class Codec {
	// Encodes a tree to a single string.
	public String serialize(TreeNode root) {
		String data="";
		if (root == null) {
			return data;
		}
		Queue<TreeNode> q = new LinkedList<>();
		data += Integer.toString(root.val);
		q.add(root);
		while (q.size() != 0) {
			TreeNode temp = q.remove();
			if (temp.left != null) {
				q.add(temp.left);
				data += "," + Integer.toString(temp.left.val);
			} else {
				data += "," + Integer.toString(-1);
			}
			if (temp.right != null) {
				q.add(temp.right);
				data += "," + Integer.toString(temp.right.val);
			} else {
				data += "," + Integer.toString(-1);
			}
		}
		return data;
	}

	// Decodes your encoded data to tree.
	public TreeNode deserialize(String data) {
		if (data.length() == 0) {
			return null;
		}
		int val = 0, i = 0;
		while (i < data.length() && data.charAt(i) != ',') {
			val = val * 10 + (data.charAt(i) - '0');
			i++;
		}
		TreeNode root = new TreeNode(val);
		Queue<TreeNode> q = new LinkedList<>();
		q.add(root);
		while (q.size() != 0) {
			TreeNode temp = q.remove();
			// for left subtree
			for (val = -2, i += 1; i < data.length() && data.charAt(i) != ','; i++) {
				val = (val == -2) ? 0 : val;
				val = val * 10 + (data.charAt(i) - '0');
			}
			if (val >= 0) {
				temp.left = new TreeNode(val);
				q.add(temp.left);
			}
			//	For right subtree
			for (val = -2, i += 1; i < data.length() && data.charAt(i) != ','; i++) {
				val = (val == -2) ? 0 : val;
				val = val * 10 + (data.charAt(i) - '0');
			}
			if (val >= 0) {
				temp.right = new TreeNode(val);
				q.add(temp.right);
			}
		}
		return root;
	}
};
class Solution {
	private static TreeNode takeInput() {
		Scanner scan = new Scanner(System.in);
		int data = scan.nextInt();
		if (data == -1) {
			return null;
		}
		TreeNode root = new TreeNode(data);
		Queue<TreeNode> q = new LinkedList<>();
		q.add(root);
		while (q.size() != 0) {
			TreeNode temp = q.remove();
			//left data
			data = scan.nextInt();
			if (data != -1) {
				temp.left = new TreeNode(data);
				q.add(temp.left);
			}
			// right data
			data = scan.nextInt();
			if (data != -1) {
				temp.right = new TreeNode(data);
				q.add(temp.right);
			}
		}
		return root;
	}
	private static void inorder(TreeNode root) {
		if (root == null) return;
		inorder(root.left);
		System.out.print(root.val+" ");
		inorder(root.right);
	}
	public static void main(String[] args) {
		TreeNode root = takeInput();
		inorder(root);
		Codec  ser = new Codec();
		Codec  deser = new Codec();
		String tree = ser.serialize(root);
		TreeNode ans = deser.deserialize(tree);
		System.out.println();
		inorder(ans);
	}
};