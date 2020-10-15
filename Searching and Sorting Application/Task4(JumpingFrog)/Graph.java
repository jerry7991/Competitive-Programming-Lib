import java.util.*;
class Graph
{ int row=0;int colounm=0;
	int vertices[];
	LinkedList<int[]> adjacentArrayList[][];
	Graph()
	{
		adjacentArrayList=new LinkedList[row][colounm];
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<colounm;j++)
			{
				adjacentArrayList[i][j]=new LinkedList<int[]>();

			}
		}
	}
}