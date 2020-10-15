import java.util.Scanner;
import java.util.LinkedList;
import java.util.Iterator;
class Jumping
{
	public static void main(String args[])
	{
		Scanner scan=new Scanner(System.in);
		System.out.println("Enter the Row and Colounm");
	    int row=scan.nextInt();
		int colounm=scan.nextInt();
		int[] chesBoard[][]=new int[2][row][colounm];
		System.out.println("Enter the launcher value");
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<colounm;j++)
				{
					chesBoard[0][i][j]=scan.nextInt();
				}
		}
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<colounm;j++)
				{
					chesBoard[1][i][j]=scan.nextInt();
				}
		}
		System.out.println("Your entered launcher data is =\n");
		for(int i=0;i<row;i++)
		{
			System.out.print("\n");
			for(int j=0;j<colounm;j++)
			{
				System.out.print(" ( "+chesBoard[0][i][j]+" , "+chesBoard[1][i][j]+" ) ");
			}
		}
		System.out.println("\nEnter Your starting point");
		int source[]=new int[2];
		source[0]=scan.nextInt();
		source[1]=scan.nextInt();
		Graph graph=new Graph(row,colounm);
		for(int i=0;i<row;i++)
		{
			System.out.print("\n");
			for(int j=0;j<colounm;j++)
			{
				int location[]={chesBoard[0][i][j],chesBoard[1][i][j]};
				graph.addEdge(location);
			}
		}
		graph.bfsTraversal(source);
	}
}
class Graph
{
	LinkedList<int[]> adjacentArrayList[][];
	int row;
	int colounm;
	Graph(int row, int colounm)
	{
		this.row=row;
		this.colounm=colounm;
		adjacentArrayList=new LinkedList[row][colounm];
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<colounm;j++)
			{
				adjacentArrayList[i][j]= new LinkedList<int[]>();
			}
		}
	}
	void addEdge(int dest[])
	{
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<colounm;j++)
			{
				int destination[]=new int[2];
				if((j+dest[0])<colounm)
				{
					destination[1]=(j+dest[0]);//In right move we are going to change coloumn
					adjacentArrayList[i][j].add(destination);
				}
				int destination1[]=new int[2];
				destination1[1]=j;//coloumn doesn't change
				if((i+dest[1])<row)
				{
					destination1[0]=(i+dest[1]);//dest[1] says move to down so we are going to move to down
					adjacentArrayList[i][j].add(destination1);
				}				
			}
		}
	}
	void bfsTraversal(int inputSource[])
	{
		boolean visited[][]=new boolean[row][colounm];
		LinkedList<int[]> queue=new LinkedList<int[]>();
		visited[inputSource[0]][inputSource[1]]=true;
		queue.add(inputSource);
		while(queue.size()!=0)
		{
			int source[]=queue.poll();
			System.out.print("( "+source[0]+","+source[1]+" )->");
			if(source[0]==row-1 && source[1]==colounm-1)
			{
				break;
			}
			Iterator<int[]> iterator=adjacentArrayList[source[0]][source[1]].listIterator();
			while(iterator.hasNext())
			{
				int adjacentVertices[]=iterator.next();
				if(!visited[adjacentVertices[0]][adjacentVertices[1]])
				{
					visited[adjacentVertices[0]][adjacentVertices[1]]=true;
					queue.add(adjacentVertices);
				}
			}
		}
	}
}