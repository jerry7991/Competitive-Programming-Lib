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
class Height
{
	public static TreeNode<Integer> takeInput()
	{
		TreeNode<Integer> root;
		Scanner scan=new Scanner(System.in);
		int rdata=scan.nextInt();
		root=new TreeNode<Integer>(rdata);
		Queue< TreeNode<Integer> > input=new LinkedList<TreeNode<Integer>>();
		input.add(root);
		while(input.size()!=0)
		{
			TreeNode<Integer> temp=input.remove();
			int data=scan.nextInt();
			//left sub tree's root
			if (data!=-1) {
				temp.left=new TreeNode<Integer>(data);
				input.add(temp.left);
			}else{
				temp.left=null;
			}
			//right subtree's root
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
	public static int getHeight(TreeNode<Integer> root)
	{
		if (root==null) {
			return 0;
		}
		int L_S_T_H=1+getHeight(root.left);
		int R_S_T_H=1+getHeight(root.right);
		return (L_S_T_H<R_S_T_H)?R_S_T_H : L_S_T_H;
	}
	public static void printTree(TreeNode<Integer> root)
	{
		if (root==null) {
			return;			
		}
		System.out.print(root.data+" : ");
		if (root.left!=null) {
			System.out.print("  L "+root.left.data+" , ");
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
		int h=getHeight(root);
		System.out.println("Height of tree is :"+h);
	}
}