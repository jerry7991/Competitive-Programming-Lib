import java.util.*;
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
class Answer<T>
{
	 T min;
	 T max;
}
class MinAndMax
{
	public static TreeNode<Integer> takeInput()
	{
		int rData;
		Scanner scan=new Scanner(System.in);
		rData=scan.nextInt();
		if (rData==-1) {
			return null;
		}
		TreeNode<Integer> root=new TreeNode<Integer>(rData);
		Queue<TreeNode<Integer>> input=new LinkedList<TreeNode<Integer>>();
		input.add(root);
		while(!input.isEmpty())
		{
			TreeNode<Integer> temp=input.remove();//just like pull()
			//enter left root data 
			rData=scan.nextInt();
			if (rData!=-1) {
				temp.left=new TreeNode<Integer>(rData);
				input.add(temp.left);
			}else{
				temp.left=null;
			}
			//enter right root data
			rData=scan.nextInt();
			if (rData!=-1) {
				temp.right=new TreeNode<Integer>(rData);
				input.add(temp.right);
			}else{
				temp.right=null;
			}
		}
		return root;
	}
	public static void print(TreeNode<Integer> root)
	{
		Queue<TreeNode<Integer>> output=new LinkedList<TreeNode<Integer>>();
		output.add(root);
		output.add(null);//null will tell me that a new level arived
		while(!output.isEmpty())
		{
			TreeNode<Integer>temp=output.remove();
			if (temp==null) {
				if (output.size()!=0) {
					//if size==0, nothing have to print , we don't add null otherwise we stuck
					//in infinite loop
					//but size !=0 here
					output.add(null);//will tell the arival of new level
					System.out.println();
				}
			}else{
				System.out.print(temp.data+" ");
				//add left and right in queue
				if (temp.left!=null) {
					output.add(temp.left);
				}
				if (temp.right!=null) {
					output.add(temp.right);
				}
			}
		}
	}
	public static void getAnswer(TreeNode<Integer> root , Answer<Integer> ans)
	{
		if (root==null) {
			return;
		}
		ans.min=Math.min(ans.min , root.data);
		ans.max=Math.max(ans.max , root.data);
		getAnswer(root.left ,ans);
		getAnswer(root.right ,ans);
	}
	public static void main(String[] args) {
		TreeNode<Integer> root=takeInput();
		print(root);
		Answer<Integer> ans=new Answer<Integer>();
		ans.min=Integer.MAX_VALUE;
		ans.max=Integer.MIN_VALUE;
		getAnswer(root,ans);
		System.out.println("\nTree has min value= "+ans.min+" and max value= "+ans.max);
	}
}