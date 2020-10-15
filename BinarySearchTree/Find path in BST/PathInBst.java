import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;
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
class PathInBst
{
	private static Scanner scan=new Scanner(System.in);
	private static BSTNode<Integer> takeInput()
	{
		int rootData=scan.nextInt();
		if (rootData==-1)	return null;
		BSTNode<Integer> root=new BSTNode<Integer>(rootData);
		Queue<BSTNode<Integer>> queue=new LinkedList<BSTNode<Integer>>();
		queue.add(root);
		while (!queue.isEmpty()) {
			BSTNode<Integer> temp=queue.remove();
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
	private static boolean printPath(BSTNode<Integer> root , int k)
	{
		if (root==null) return false;
		if (root.data==k) {
			System.out.println(root.data);
			return true;
		}
		boolean isFound=false;
		if (root.data>k) {
			isFound=printPath(root.left , k);
		}
		if (root.data<k) {
			isFound=printPath(root.right ,k);
		}
		if(isFound)		System.out.println(root.data);
		return isFound;
	}
	public static void main(String[] args) {
		BSTNode<Integer>root=takeInput();
		int k=scan.nextInt();
		boolean isFound=printPath(root , k);
		if(!isFound)	System.out.println("Not reachable node");
	}
}