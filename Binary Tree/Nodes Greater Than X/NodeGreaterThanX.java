import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;
class TreeNode<T>
{
	TreeNode<T> left;
	TreeNode<T> right;
	T data;
	TreeNode(T data)
	{
		this.data=data;
	}
}
class NodeGreaterThanX
{
	static	int count;
	public static TreeNode<Integer> takeInput()
	{
		Scanner scan=new Scanner(System.in);
		Queue<TreeNode<Integer>> input=new LinkedList<TreeNode<Integer>>();
		int data=scan.nextInt();
		if (data==-1) {
			return null;
		}
		TreeNode<Integer> root=new TreeNode<Integer>(data);
		input.add(root);
		while(input.size()!=0)
		{
			TreeNode<Integer>temp=input.remove();
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
		return  root;
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
	public static void findGreaterToX(TreeNode<Integer> root  ,int X)
	{
		if (root==null) {
			return;
		}
		if (root.data>X) {
			count++;
		}
		findGreaterToX(root.left ,  X);
		findGreaterToX(root.right , X);
	}
	public static void main(String[] args) {
		TreeNode<Integer> root;
		root=takeInput();
		printTree(root);
		System.out.println();
		Scanner scan=new Scanner(System.in);
		int X=scan.nextInt();
		count=0;
		findGreaterToX(root   , X);
		System.out.println(count);
	}
}