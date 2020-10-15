import java.util.Scanner;
import java.util.LinkedList;
import java.util.Queue;
class BSTNode<T>
{
	BSTNode<T> left;
	BSTNode<T> right;
	T data;
	BSTNode(T data)
	{
		this.data=data;
	}
}
class K1AndK2
{
	private static Scanner scan=new Scanner(System.in);
	public static BSTNode<Integer> takeInput()
	{
		int rootData;
		rootData=scan.nextInt();
		if (rootData==-1) {
			return null;
		}
		BSTNode<Integer> root=new BSTNode<Integer>(rootData);
		Queue<BSTNode<Integer>> queue=new LinkedList<BSTNode<Integer>>();
		queue.add(root);
		while(!queue.isEmpty())
		{
			BSTNode<Integer>temp=queue.remove();
			rootData=scan.nextInt();
			if (rootData!=-1) {
				temp.left=new BSTNode<Integer>(rootData);
				queue.add(temp.left);
			}else{
				temp.left=null;
			}
			rootData=scan.nextInt();
			if (rootData!=-1) {
				temp.right=new BSTNode<Integer>(rootData);
				queue.add(temp.right);
			}else{
				temp.right=null;
			}
		}
		return root;
	}
	public static void print(BSTNode<Integer> root)
	{
		if (root==null) {
			return;
		}
		Queue<BSTNode<Integer>> queue=new LinkedList<BSTNode<Integer>>();
		queue.add(root);
		queue.add(null);
		while(!queue.isEmpty())
		{
			BSTNode<Integer>temp=queue.remove();
			if (temp==null) {
				if (queue.size()!=0) {
					queue.add(null);
					System.out.println();
				}
			}else{
				System.out.print(temp.data+" ");
				if(temp.left!=null)	queue.add(temp.left);
				if(temp.right!=null) queue.add(temp.right);
			}
		}
	}
	public static void print(BSTNode<Integer> root , int k1,int k2)
	{
		if (root==null) {
			return;
		}
		if (root.data>k2) {
			print(root.left , k1 , k2);
		}
		if (root.data<k1) {
			print(root.right , k1 , k2);
		}
		if (root.data>=k1 && root.data<=k2) {
			print(root.left , k1 , k2);
			System.out.print(root.data+" ");
			print(root.right , k1 , k2);
		}
	}
	public static void main(String[] args) {
		BSTNode<Integer>root=takeInput();
		int k1,k2;
		k1=scan.nextInt();k2=scan.nextInt();
		print(root , k1 , k2);
	}
}