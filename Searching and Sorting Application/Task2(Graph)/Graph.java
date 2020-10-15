import java.util.LinkedList;
import java.util.Scanner;
class EnableGraph
{
	//we are going to create an array which have data type linked list
	LinkedList <Integer> adjacentArrayList[];
	/*above line means; adjacentArrayList is array which store data of type of linked
	 list and the Linked List containts the data of type integer
	*/
	 int numberOfVertices;
	EnableGraph(int numberOfVertices)
	{
		this.numberOfVertices=numberOfVertices;
		//define the size of arrayList i.e. give the knowledge of about what is the size of vertices
		adjacentArrayList=new LinkedList[numberOfVertices];

		//and now we have to create linkedList for each element of adjacentArrayList..
		for(int i=0;i<numberOfVertices;i++) 
		{
			adjacentArrayList[i]=new LinkedList<>();
		}
	}
}
class OperationOnGraph
{

	//we are going to give functionality for creating new node
	void addEdge(EnableGraph graphEnable,int source,int destination)
	{
		//add an edge from source to destination
		graphEnable.adjacentArrayList[source].add(destination);

		//graph is undirected so we have to create an edge from destination to source also
		graphEnable.adjacentArrayList[destination].add(source);
	}
	void displayGraph(EnableGraph graphEnable)
	{
		for(int v=0;v<graphEnable.numberOfVertices;v++)
		{
		  System.out.println("Adjacency List of Vertex "+v);
		  System.out.println("Head");
		  for(Integer iterator : graphEnable.adjacentArrayList[v])
		  {
		  	System.out.println("->"+iterator);
		  }
		  System.out.println("\n");
		}
	}
}
public class Graph
{
 public static void main(String arguments[])
 {
 	Scanner scan=new Scanner(System.in);
 	System.out.println("Enter the number of Vertices");
 	int vertices=scan.nextInt();
 	System.out.println("Enter the number of edges");
 	int edges=scan.nextInt();
 	EnableGraph graphEnable=new EnableGraph(vertices);
 	OperationOnGraph ong=new OperationOnGraph();
 	int counter=0;
 	System.out.println("Enter source and destination without repeatition of edges as \n\n{ source -> destination }");
 	while(counter<=edges)
 	{
 		int source=scan.nextInt();
 		int destination=scan.nextInt();
 		ong.addEdge(graphEnable,source,destination);
 		counter++;
 	}
 	ong.displayGraph(graphEnable);
 }
}