import java.util.LinkedList;
import java.util.Scanner;
import java.util.Iterator;
class Graph
{
	//this store the adjacent list for every particular node
	LinkedList<Integer> adjacentArrayList[];
	int numberOfVertices;
	Graph(int numberOfVertices)
	{
		this.numberOfVertices=numberOfVertices;
		//below statement create a array of size numberOfVertices which are going to store adjacent vertices in
		//Linked List
		adjacentArrayList=new LinkedList[numberOfVertices];

		//let's create all element of adjacentArrayList array as a Linked List
		for (int i=0;i<numberOfVertices;i++ )
		 {
			adjacentArrayList[i]=new LinkedList<>();
		}
	}
	void addEdge(int source,int destination)
	{
		adjacentArrayList[source].add(destination);
        adjacentArrayList[destination].add(source);//becasue undirected graph
	}
	void bfsTraversal(int inputSource)
	{
		//we are going to set all vertices intially not visited
		boolean visited[]=new boolean[numberOfVertices];//by default boolean value will be false

		//we are going to create a queue for bfs
		LinkedList<Integer> queue=new LinkedList<Integer>();

		//mark the node which given by user to traversal as visited
		visited[inputSource]=true;
		//now let's add this source into our queue
		queue.add(inputSource);

		while(queue.size()!=0)
		{
			//let's dequeue first/front element from queue(q) and search for it's adjacent vertices
			int source=queue.poll();//poll is method which dequeue very first element and return that elemnt
			System.out.print(source+"-> ");

			//let's search all element which is adjacent element of given source...
			Iterator<Integer> iterator= adjacentArrayList[source].listIterator();
			while(iterator.hasNext())
			{
				int adjacentVertices=iterator.next();
				//check destination is visited or not,..if not visited before then set as visited becasue 
				//now it's visited
				if(!visited[adjacentVertices])
				{
					visited[adjacentVertices]=true;
					//this vertices is visited so let's add it in queue and find it's adjacent vertices
					queue.add(adjacentVertices);
				}
			}
		}
	}
}
public class GraphTraversal
{
	public static void main(String args[])
	{
		Scanner scan=new Scanner(System.in);
		System.out.println("Enter the number of vertices");
		int numberOfVertices=scan.nextInt();
		Graph graph=new Graph(numberOfVertices);
		System.out.println("Enter the number of edges");
		int edges=scan.nextInt();
		int counter=0;
		System.out.println("Enter the source and destination \nsource destination");
		while(counter++<edges)
		{
			int source=scan.nextInt();
			int destination=scan.nextInt();
			graph.addEdge(source,destination);
		}
		System.out.println("Enter Starting Vertices for traversal in Graph =");
		int source=scan.nextInt();
		graph.bfsTraversal(source);
	}
}