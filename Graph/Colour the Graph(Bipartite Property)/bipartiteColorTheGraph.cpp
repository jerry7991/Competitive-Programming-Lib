#include <iostream>
#include <vector>
#include<unordered_set>
#define uos unordered_set
#define fon(i , n) for(unsigned int i=0 ; i< n ; i++)
using namespace std;
bool isBipartable(vector<int>* edges ,int nVertices)
{
	if (nVertices==0)
	{
		return false;
	}
	//we need to set one for red color and other for black
	//so instead of making 2 set 
	//we are making the array of set of size 2..
	//0-th set tells about black color and 1-th set tells about red color
	uos<int> colorSets[2];
	//we will use vector instead of queue becuase order doesn't matter
	vector<int> pendingVertex;
	colorSets[0].insert(0);//insert first node as a black
	//append it and explore it till the end
	pendingVertex.push_back(0);
	while(pendingVertex.size()>0)
	{
		int currentNode=pendingVertex.back();
		pendingVertex.pop_back();
		//store the color of current node
		int currentColor=colorSets[0].count(currentNode)>0 ? 0 : 1;//if current node is in black set then color black else color red
		//explore all the neighbour of currentNode and put them in opposite color and if any of neighbour is in same color the return false
		fon( i , edges[currentNode].size())
		{
			int neighbour=edges[currentNode][i];
			//case 1 neighbour is neither in black nor red i.e. not visited yet
			if (colorSets[0].count(neighbour)==0 && colorSets[1].count(neighbour)==0 )
			{
				//simply put this neighbour in opposite of color of currentNode
				colorSets[1-currentColor].insert(neighbour);
				//append this neighbour in pendingVertex
				pendingVertex.push_back(neighbour);
			}
			//case 2 if neighbour is in same color as currentNode
			else if (colorSets[currentColor].count(neighbour)>0)
			{
				//we can't do bicolor
				return false;
			}
			//case 3:- if neighbour is in opposite color then we don't have to do any thing cause it's their right position			
		}
	}
	//if return not invoked i.e. all node colored successfully
	return true;
}
int main()
{
	int nVertices,nEdges;
	cin>>nVertices>>nEdges;
	vector<int> * edges=new vector<int>[nVertices];
	fon(i , nEdges)
	{
		int source,destination;
		cin>>source>>destination;
		edges[source-1].push_back(destination-1);
		edges[destination-1].push_back(source-1);
	}
	bool answer=isBipartable(edges , nVertices);
	if (answer)
	{
		cout<<"YES";
	}else{
		cout<<"NO";
	}
}