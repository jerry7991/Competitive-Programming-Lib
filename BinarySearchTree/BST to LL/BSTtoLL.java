import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;
class List<T>
{
	List<T> next;
	T data;
	List(T data)
	{
		this.data=data;
		this.next=null;
	}
	List()
	{
		this.next=null;
	}
}
class BST<T>
{
	BST<T> left;
	BST<T> right;
	T data;
	BST(T data)
	{
		this.data=data;
	}
}
class BSTtoLL
{
	public static Scanner scan=new Scanner(System.in);
	public static Queue< BST<Integer> >pending=new LinkedList< BST<Integer> >();
	public static List<Integer> list=new List<Integer>();
	public static void add(int data)
	{
		List<Integer>temp=list;
		while(temp.next!=null)
		{
			temp=temp.next;
		}
		temp.next=new List(data);
	}
	public static void takeInput(BST<Integer> root)
	{
		pending.add(root);
		while(!pending.isEmpty())
		{
			BST<Integer>temp=pending.remove();
			int data=scan.nextInt();
			if (data!=-1) {
				temp.left=new BST<Integer>(data);
				pending.add(temp.left);
			}else{
				temp.left=null;
			}
			data=scan.nextInt();
			if (data!=-1) {
				temp.right=new BST<Integer>(data);
				pending.add(temp.right);
			}else{
				temp.right=null;
			}
		}
	}
	public static void print(BST<Integer> root)
	{
		pending.add(root);
		pending.add(null);
		while(!pending.isEmpty())
		{
			BST<Integer>temp=pending.remove();
			if (temp==null) {
				if (!pending.isEmpty()) {
					pending.add(null);
					System.out.println();
				}
			}else{
				System.out.print(temp.data+" ");
				if (temp.left!=null) {
					pending.add(temp.left);
				}
				if (temp.right!=null) {
					pending.add(temp.right);
				}
			}
		}
	}
	public static void println(BST<Integer> root)
	{
		if (root==null) {
			return;
		}
		println(root.left);
		add(root.data);
		//System.out.print(root.data+" ");
		println(root.right);
	}
	public static void main(String[] args) {
		BST<Integer>root=new BST<Integer>(scan.nextInt());
		takeInput(root);
		print(root);
		System.out.println("\n increasing order");
		println(root);
		list=list.next;
		while(list!=null)
		{
			System.out.print(list.data+" ");
			list=list.next;
		}
	}
}