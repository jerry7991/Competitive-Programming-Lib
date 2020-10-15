import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;
import java.util.ArrayList;
import java.util.HashMap;
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
class Replace
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
	private static void getInOrder(BSTNode<Integer> root , ArrayList<Integer> inorder)
	{
		if (root==null) return;
		getInOrder(root.left , inorder);
		inorder.add(root.data);
		getInOrder(root.right , inorder);
	}
	private static void print(BSTNode<Integer> root)
	{
		Queue<BSTNode<Integer>>pending=new LinkedList<BSTNode<Integer>>();
		pending.add(root);
		pending.add(null);
		while(!pending.isEmpty())
		{
			BSTNode<Integer> temp=pending.remove();
			if (temp==null) {
				if (!pending.isEmpty()) {
					pending.add(null);
					System.out.println();
				}
			}else{
				System.out.print(temp.data+" ");
				if (temp.left!=null)	pending.add(temp.left);
				if (temp.right!=null)	pending.add(temp.right);
			}
		}
	}
	private static void replaceTree(BSTNode<Integer> root , HashMap<Integer,Integer> hm)
	{
		if (root==null) return;
		root.data=hm.get(root.data);
		replaceTree(root.left , hm);
		replaceTree(root.right , hm);
	}
	public static void main(String[] args) {
		BSTNode<Integer> root=takeInput();
		print(root);
		ArrayList<Integer> inorder=new ArrayList<Integer>();
		getInOrder(root,inorder);
		int dp[]=new int[inorder.size()];
		int n=inorder.size();
		for (int i=0 ;i<n ;i++ ) dp[i]=0;
			dp[n-1]=inorder.get(n-1);
		for (int i=n-2;i>=0 ;i-- ) {
			dp[i]=dp[i+1]+inorder.get(i);
		}
		HashMap<Integer,Integer> hm=new HashMap<Integer,Integer>();
		for (int i=0;i<n ;i++ ) {
			hm.put(inorder.get(i) , dp[i]);
		}
		System.out.println();
		replaceTree(root , hm);
		print(root);
	}
}