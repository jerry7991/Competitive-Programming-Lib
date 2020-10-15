import java.util.*;
class BinaryTreeNode<T>
{
	BinaryTreeNode<T> left;
	BinaryTreeNode<T> right;
	T data;
	BinaryTreeNode(T data)
	{
		this.data=data;
	}
}
class solution
{
	public static void  preorder(BinaryTreeNode<Integer> root)
	{
		if (root==null) {
			return;
		}
		System.out.print(root.data+" ");
		preorder(root.left);
		preorder(root.right);
	}
	public static Vector<BinaryTreeNode<Integer>> constructTrees(int start,	int end) 
	{
		Vector<BinaryTreeNode<Integer>>Nodelist=new Vector<BinaryTreeNode<Integer>>();
		if (start>end) {
			//a null bst possible
			Nodelist.add(null);
			return Nodelist;
		}
		//otherwise iterate from start to end and make all possible left subtree and right subtree
		for (int i=start;i<=end ;i++ ) {
			Vector<BinaryTreeNode<Integer>> leftSubtree=constructTrees(start , i-1);
			Vector<BinaryTreeNode<Integer>> rightSubtree=constructTrees(i+1,end);
			//now let's save each combination of leftSubtree and right subtree for particular node.data=i
			for (int j=0;j<leftSubtree.size() ;j++ ) {
				BinaryTreeNode<Integer> left=leftSubtree.get(j);
				for (int k=0 ;k<rightSubtree.size() ;k++ ) {
					BinaryTreeNode<Integer> right=rightSubtree.get(k);
					//and now a make a root of i data and attach left and right as leftsubtree and righsubtree
					BinaryTreeNode<Integer> root=new BinaryTreeNode<Integer>(i);
					root.left=left;
					root.right=right;
					//now save root in list
					Nodelist.add(root);
				}
			}
		}
		return Nodelist;
	}
	public static void main(String[] args) {
		int start,end;
		Scanner scan=new Scanner(System.in);
		start=scan.nextInt();
		end=scan.nextInt();
		Vector<BinaryTreeNode<Integer>>BSTNode=constructTrees(start , end);
		for (int i=0;i<BSTNode.size() ;i++ ) {
			preorder(BSTNode.get(i));
			System.out.println();
		}
	}
}