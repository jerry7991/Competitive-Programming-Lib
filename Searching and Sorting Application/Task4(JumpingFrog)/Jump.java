import java.util.Scanner;
import java.util.LinkedList;
import java.util.Iterator;
class Jump
{
	public static void main(String args[])
	{
		Scanner scan=new Scanner(System.in);
		int length=scan.nextInt();
		int node[]=new int[length];
		for (int i=0;i<length ;i++ ) {
			node[i]=scan.nextInt();
		}
		Process process=new Process(node);
		process.makeAdjacentList();
		process.bfs();
	}
}
class Process
{
	LinkedList <Integer> adjacentList[];
	int node[];
	Process(int []node)
	{
		adjacentList=new LinkedList[node.length];
		this.node=node;
	}
	void makeAdjacentList()
	{
		for (int i=0;i<node.length ;i++ ) {
			adjacentList[i]=new LinkedList<Integer>();
		}
		for(int i=0;i<node.length;i++)
		{
			int source=1;
			while(source<=node[i])
			{
				try
				{
					adjacentList[i].add(node[i+source]);
				}
				catch(Exception e)
				{
					break;
				}
				source++;
			}
			System.out.println(adjacentList[i]);
		}
		// for display ;:-
		// for(int i=0;i<node.length;i++)
		// {
		// 	//System.out.println(i+"->");
		// 	Iterator <Integer> iterator=adjacentList[i].listIterator();
		// 	while(iterator.hasNext())
		// 	{
		// 		int temp=iterator.next();
		// 		//System.out.print(temp+"->");
		// 	}
		// }
	}
	void bfs()
	{
		boolean visited[]=new boolean[node.length];
		visited[0]=true;
		//make a queue
		LinkedList<Integer> queue=new LinkedList<Integer>();
		queue.add(0);
		// while(queue.size()!=0)
		// {
		// 	//System.out.println(node[1]+"->");
		// 	int source=queue.poll();
		// 	Iterator <Integer> iterator=adjacentList[0].listIterator();
		// 	while(iterator.hasNext())
		// 	{
		// 		int n=iterator.next();
		// 		if(!visited[n])
		// 		{
		// 			visited[n]=true;
		// 			System.out.println(n+"-");
		// 			queue.add(n);
		// 		}
		// 	}
		// }
	}
}