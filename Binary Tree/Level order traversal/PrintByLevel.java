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
class PrintByLevel
{
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
	public static void printLevelwise(TreeNode<Integer> root)
	{
		//as we have taken the input just like that we will print
		//make a queue of type linked list of data type TreeNode<Integer> cause we 
		//don't know the size of tree so need to use Linked list
		Queue<TreeNode<Integer>> output=new LinkedList<TreeNode<Integer>>();
		//append root to output
		output.add(root);
		//we add a null counter which will tell us that we have printed a level
		//and now we are going to new level
		output.add(null);
		while(output.size()!=0)
		{
			TreeNode<Integer> temp=output.remove();//poll();
			if (temp==null) {
				//that's meanse we are going to print the element of new level
				//so have to print the new line and null because we this null
				//will tell the range of current level
				if (!output.isEmpty()) {
				output.add(null)	;
				}
				System.out.println();
			}else{
				//we are in same level
				//print the data of temp
				System.out.print(temp.data+" ");
				//and append their left and right child to queue
				if(temp.left!=null)
				{
					output.add(temp.left);
				}
				if(temp.right!=null)
				{
					output.add(temp.right);
				}
			}
		}
	}
	public static void main(String[] args) {
		TreeNode<Integer> root=takeInput();
		//root has cunstructed tree so we have to print it in level wise
		printLevelwise(root);
	}
}