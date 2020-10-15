import java.util.Scanner;
class Node3 <T>
{
	T data;
	Node3 <T> next;
	Node3(T data)
	{
		this.data=data;
	}

	static Scanner sc=new Scanner(System.in);
	public static Node3 <Integer> takeInput()
	{
		System.out.println("Enter Linked List Element Here:");
		int data=sc.nextInt();
		Node3 <Integer> head=null ,tail=null;
		while(data!=-1)
		{
			Node3<Integer> currentNode=new Node3 <>(data);

			if(head==null)
			{
				head=currentNode;
				tail=currentNode;
			}
			else
			{
				tail.next=currentNode;
				tail=currentNode;
				
			}
			data=sc.nextInt();	
		}
		return head;
	}

	public static void print(Node3 <Integer> head)
	{
		Node3<Integer> temp=head;
		while(temp!=null)
		{
			System.out.print(temp.data +" ");
			temp=temp.next;
		}
		System.out.println();
	}

	public static Node3<Integer> inserNode(Node3 <Integer> head,int element ,int position)
	{
		Node3<Integer> nodeToBeInserted=new Node3 <Integer> (element);
		if(position==0)
		{
			nodeToBeInserted.next=head;
			head=nodeToBeInserted;
		}
		else
		{
			int count=0;
			Node3<Integer> privious=head;
			while(count<position-1 )
			{
				if (privious==null) {
					//i.e. given position out of bound of list
					System.out.println("Position not found");
					System.exit(0);
				}
				count++;
				privious=privious.next;
			}
				nodeToBeInserted.next=privious.next;
				privious.next=nodeToBeInserted;
		}
		//return head becuase we just modified it if we wouldn't return then head of main
		//method use their older address but we have modified it so we have to return...
		return head;
	}

	

	public static void main(String[] args) {
		Node3 <Integer> head=takeInput();
		System.out.println("Enter Element Which You Want To insert : ");
		int element=sc.nextInt();
		System.out.println("Enter Position At Which You want To Insert Element:");
		int position=sc.nextInt();
		head=inserNode(head ,element,position);
		print(head);
		
	}



}