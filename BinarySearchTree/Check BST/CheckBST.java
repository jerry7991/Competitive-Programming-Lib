import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;
class BSTNode<T>
{
	public BSTNode<T> left;
	public BSTNode<T> right;
	public T data;
	BSTNode(T data)
	{
		this.data=data;
	}
};
class CheckBST
{
	private static Scanner scan=new Scanner(System.in);
	private static BSTNode<Integer> takeInput()
	{
		int data=scan.nextInt();
		if (data==-1) {
			return null;
		}
		BSTNode<Integer> root=new BSTNode<Integer>(data);
		Queue<BSTNode<Integer>> pending=new LinkedList<BSTNode<Integer>>();
		pending.add(root);
		while(!pending.isEmpty())
		{
			BSTNode<Integer> temp=pending.remove();
			data=scan.nextInt();
			if (data!=-1) {
				temp.left=new BSTNode<Integer>(data);
				pending.add(temp.left);
			}else{
				temp.left=null;
			}
			data=scan.nextInt();
			if (data!=-1) {
				temp.right=new BSTNode<Integer>(data);
				pending.add(temp.right);
			}else{
				temp.right=null;
			}
		}
		return root;
	}
	private static int findMin(BSTNode<Integer> root)
	{
		if (root==null) {
			return Integer.MAX_VALUE;
		}
		int leftMin=findMin(root.left);
		int rightMin=findMin(root.right);
		return Math.min(root.data , Math.min(leftMin , rightMin));
	}
	private static int findMax(BSTNode<Integer> root)
	{
		if (root==null) {
			return Integer.MIN_VALUE;
		}
		int leftMax=findMax(root.left);
		int rightMAx=findMax(root.right);
		return Math.max(root.data , Math.max(leftMax , rightMAx));
	}
	private static boolean isBSt(BSTNode<Integer> root)
	{
		if (root==null) {
			return true;
		}
		int min=findMin(root.right);
		int max=findMax(root.left);
		if (root.data>min) {
			return false;
		}
		if (root.data<=max) {
			return false;
		}
		boolean leftAns=isBSt(root.left);
		boolean rightAns=isBSt(root.right);
		return (leftAns && rightAns);
	}
	public static void main(String[] args) {
		BSTNode<Integer> root=takeInput();
		boolean isBSt=isBSt(root);
		System.out.println(isBSt);
	}
}