import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;
class TreeNode<T>
{
	public TreeNode<T> left;
	public TreeNode<T> right;
	public T data;
	TreeNode(T data)
	{
		this.data=data;
	}
}
class IsNodePresent
{
	public static TreeNode<Integer> takeInput()
	{
		Scanner scan=new Scanner(System.in);
		Queue<TreeNode<Integer> > input=new LinkedList<TreeNode<Integer>>();
		TreeNode<Integer>root;
		int data=scan.nextInt();
		root=new TreeNode<Integer>(data);
		input.add(root);
		while(!input.isEmpty())
		{
			TreeNode<Integer> temp=input.remove();
			//root of left subtree
			data=scan.nextInt();
			if (data!=-1) {
				temp.left=new TreeNode<Integer>(data);
				input.add(temp.left);
			}else{
				temp.left=null;
			}
			data=scan.nextInt();
			if (data!=-1) {
				temp.right=new TreeNode<Integer>(data);
				input.add(temp.right);
			}else{
				temp.right=null;
			}
		}
		return root;
	}
	public static boolean checkPresent(TreeNode<Integer> root , int data)
	{
		if (root==null) {
			return false;
		}
		if (root.data==data) {
			return true;
		}
		return (checkPresent(root.left , data) || checkPresent(root.right , data));
	}
	public static void printTree(TreeNode<Integer> root)
	{
		if (root==null) {
			return;
		}
		System.out.print(root.data+" : ");
		if (root.left!=null) {
			System.out.print(" L "+root.left.data+" , ");
		}
		if (root.right!=null) {
			System.out.print(" R "+root.right.data);
		}
		System.out.println();
		printTree(root.left);
		printTree(root.right);
	}
	public static void main(String[] args) {
		TreeNode<Integer> root=takeInput();
		printTree(root);
		Scanner scan=new Scanner(System.in);
		int data=scan.nextInt();
		boolean isPresent=checkPresent(root , data);
		if (isPresent) {
			System.out.println("true");
		}else{
			System.out.println("false");
		}
	}
}