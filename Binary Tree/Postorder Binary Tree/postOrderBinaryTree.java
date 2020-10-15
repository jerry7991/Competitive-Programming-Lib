import java.util.Scanner;
class TreeNode<T>
{
	public TreeNode <T> left;
	public TreeNode <T> right;
	public T data;
	TreeNode(T data)
	{
		this.data=data;
	}
}
class PostOrderBinaryTree
{
	public static TreeNode<Integer> takeInput(boolean isRoot,int parent , boolean isLeft )
	{
		Scanner scan=new Scanner(System.in);
		if (isRoot) {
			System.out.print("Enter Root Data :  ");
		}else{
			if(isLeft)
			{
				System.out.print("Enter left node of  "+parent+"  : ");
			}else{
				System.out.print("Enter right node of :  "+parent+"  : ");
			}
		}
		int data=scan.nextInt();
		if(data==-1)
		{
			return null;
		}
		TreeNode<Integer> root=new TreeNode<Integer>(data);
		TreeNode<Integer> leftSubTree=takeInput(false , data , true);
		TreeNode<Integer> rightSubTree=takeInput(false , data , false);
		root.left=leftSubTree;
		root.right=rightSubTree;
		return root;
	}
	public static void printPostOrder(TreeNode<Integer> root)
	{
		if(root==null)
		{
			return;
		}
		printPostOrder(root.left);
		printPostOrder(root.right);
		System.out.print(root.data+" ");
	}
	public static void printTree(TreeNode<Integer> root)
	{
		if (root==null) {
			return;
		}
		System.out.println(root.data+":");
		if (root.left!=null) {
			System.out.println(" L "+root.left.data+" ,");
		}
		if (root.right!=null) {
			System.out.println(" R "+root.data);
		}
		printTree(root.left);
		printTree(root.right);
	}
	public static void main(String args[])
	{
		TreeNode<Integer> root=takeInput(true , -1 , false);
		printTree(root);
		printPostOrder(root);
	}
}