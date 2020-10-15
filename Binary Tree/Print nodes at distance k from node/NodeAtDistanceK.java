import java.util.Scanner;
import java.util.LinkedList;
import java.util.Queue;
//create a structre for tree
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
public class NodeAtDistanceK
{
	static int count;
	public static TreeNode<Integer> takeInput()
	{
		//because input are coming in level wise so first come first serve
		int rootData;
		Scanner scan=new Scanner(System.in);
		rootData=scan.nextInt();
		//i.e for empty tree
		if (rootData==-1) {
			return null;
		}
		//now we need to create root
		TreeNode<Integer> root=new TreeNode<Integer>(rootData);
		//so each level has to save so we use queue for that and we don't know about
		//the size of queue so have to take queue of type of linked list
		//since our queue will store the reference of tree so type of queue is TreeNode
		Queue< TreeNode<Integer> > input=new LinkedList< TreeNode<Integer> >();
		//append the newly created root into input 
		input.add(root);
		while(input.size()!=0)
		{
			//until the input size is not equal to 0 i.e. empty
			//we need a temp for store the reference from the queue
			TreeNode<Integer> temp=input.remove();//remove dequeue the queue and also returns the front value
			//now for any particular node we need 2 things
			//1:- their left child and right child data
			//Enter left child
			rootData=scan.nextInt();//i.e. left data
			if (rootData!=-1) {
				//so we need to create a child in the left of temp
				temp.left=new TreeNode<Integer>(rootData);
				//and we have to append left subtree in input queue for which we can 
				// take input leater 
				input.add(temp.left);
			}else{
				//i.e. rootData=-1
				temp.left=null;
				//no need to append cause this subtree now ended;
			}
			//same stepse for right child
			//Enetr right child
			rootData=scan.nextInt();
			if (rootData!=-1) {
				temp.right=new TreeNode<Integer>(rootData);
				//now we have to append this node in queue cause this subtree not ended yet
				input.add(temp.right);
			}else{
				//rootData=-1
				//i.e. we have to terminate i.e. no right child for temp node
				temp.right=null;
				//no need to add it in queue
			}
		}
		//once queue will empty all the node is allocate according to input and return root
		//because we didn't disturb root node.... instead of touching root , we used
		// temp variable for each node to ditermine weather they has right child and left 
		//child or not ........
		//so we can return root...
		return root;
	}
	public static void printNodeAtDepthK(TreeNode<Integer> root  ,int level)
	{
		if (root==null) {
			//nothing has to do
			return;
		}
		if (level==0) {
			//i.e. required level
			System.out.println(root.data);
			return;
		}
		//go left and go right and then print
		printNodeAtDepthK(root.left , level-1);//one level down
		printNodeAtDepthK(root.right , level-1);//one level down
	}
	public static int print(TreeNode<Integer> root , int level , int node)
	{
		if (root==null) {
			//we were not able to find node
			return -1;
		}
		if (root.data==node) {
			//we found the node print the node at k-th depth from current root
			printNodeAtDepthK(root , level);
			return 0;//for distance from root to root
		}
		int leftDistance=print(root.left , level , node);
		if (leftDistance!=-1) {
			//i.e. we were able to print so for each parent we have to
			// print k-(distance of parent to curr node)
			if (leftDistance+1==level) {
				System.out.println(root.data);
			}else{
				//look right parent of curr root,because all left has printed in base case
				printNodeAtDepthK(root.right , level-leftDistance-2);
				return leftDistance+1;//for each parent distance will increase by 1
			}
		}
		int rightDistance=print(root.right , level , node);
		if (rightDistance!=-1) {
			if (rightDistance+1==level) {
				System.out.println(root.data);//i.e. parent is at the level
			}else{
				//look left of parent because right will printed in base case
				printNodeAtDepthK(root.left , level-rightDistance-2);
				return 1+rightDistance;
			}
		}
		return -1;
	}
	public static void main(String[] args) {
		TreeNode<Integer> root=takeInput();
		int node,level;
		Scanner scan=new Scanner(System.in);
		node=scan.nextInt();
		level=scan.nextInt();
		int n=print(root , level , node);
	}
}