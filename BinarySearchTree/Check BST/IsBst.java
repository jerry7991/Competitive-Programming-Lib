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
class IsBst
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
	private static boolean isBSt(BSTNode<Integer> root , int minRange , int maxRange)
	{
		if (root==null) {
			return true;
		}
		if (root.data<=minRange) {
			return false;
		}
		if (root.data>maxRange) {
			return false;
		}
		boolean leftAns=isBSt(root.left , minRange , root.data-1);
		boolean rightAns=isBSt(root.right , root.data , maxRange);
		return (leftAns && rightAns);
	}
	public static void main(String[] args) {
		BSTNode<Integer> root=takeInput();
		boolean isBSt=isBSt(root , Integer.MIN_VALUE , Integer.MAX_VALUE);
		System.out.println(isBSt);
	}
}