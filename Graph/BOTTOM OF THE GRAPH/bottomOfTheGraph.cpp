#include<iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <algorithm>
#define uos unordered_set
using namespace std;
#define fon(i , n) for (int i = 0; i < n; ++i)
void dfs2( vector<int>* edges  ,uos<int> & visited ,uos<int> * component ,int start)
{
	//make start visited
	visited.insert(start);
	//start will be scc
	component->insert(start);
	//pick one by one neighbour and explore it till the end
	fon(i , edges[start].size())
	{
		int adjacent=edges[start][i];
		if (visited.count(adjacent)==0)
		{
			dfs2(edges  , visited , component , adjacent);
		}
	}
}
void dfs(vector<int> * edges ,uos<int>& visited ,stack<int> & finishedVertices , int start)
{
	//make start as visited
	visited.insert(start);
	//pick one neighbour and explore them till the end
	fon( i , edges[start].size())
	{
		int adjacent=edges[start][i];
		if (visited.count(adjacent)==0)//not yet visited
		{
			dfs(edges , visited , finishedVertices , adjacent);
		}
	}
	//once we have done with one vertex we can store in finishedVertex stack
	finishedVertices.push(start);
}
uos<uos<int>*>* getSCC(vector<int>* edges ,vector<int> * transposEdges ,int nVertices)
{
	//let's implement KosaRaju's algorithm
	uos<int> visited;
	//we need an stack which store the vertices as their finish time
	stack<int> finishedVertices;
	fon(i , nVertices)
	{
		if (visited.count(i)==0)
		{
			dfs(edges , visited , finishedVertices , i);
		}
	}
	//now we have a stack which has been filled according to vertices finishe time
	//reset visited becuast it need here again
	visited.clear();
	uos<uos<int>*>* output=new uos<uos<int>*>();
	//now pick top element of the stack and perform dfs on the top and store all visited element that element will be scc
	while(! finishedVertices.empty() )
	{
		int currentElement=finishedVertices.top();
		finishedVertices.pop();
		if (visited.count(currentElement)==0)//i.e. not yet visited
		{
			uos<int> *component=new uos<int>();
			dfs2(transposEdges  , visited , component , currentElement);
			output->insert(component);
		}
	}
	return output;
}
int main()
{
	while(true)
	{
        cout<<endl;
		int nVertices , nEdges;
	cin>>nVertices;
	if (nVertices==0)
	{
		return 0;
	}
	vector<int> *edges=new vector<int>[nVertices];
	vector<int> *transposEdges=new vector<int>[nVertices];
	cin>>nEdges;
	fon(i , nEdges)
	{
		int source,destination;
		cin>>source>>destination;
		edges[source-1].push_back(destination-1);
		//store the transpose as well
		transposEdges[destination-1].push_back(source-1);
	}
	uos<uos<int>*>* scc=getSCC(edges , transposEdges , nVertices);
	
	//print the bottom of the graph
	uos<uos<int>*>:: iterator itr=scc->begin();
        vector<int>finalBottom;
	while(itr != scc->end())
	{
		uos<int >*component=*itr;
		uos<int> :: iterator it=component->begin();
		bool flag=false;
		vector<int> bottom;
		while(it != component->end())
		{
			bottom.push_back(*it);
            //cout<<*it+1<<" ";
			it++;
		}
       // cout<<endl;
       it=component->begin();
        while(it!=component->end())
        {
            int i;
			for( i=0 ; i<edges[*it].size() ; i++)
            {
				int dest=edges[*it][i];int k;
                for( k=0 ; k<bottom.size() ; k++)
                {
                    if(dest==bottom[k])
                    {
                        break;
                    }
                }
                if(k==bottom.size())
                {
                    break;
                }
            }
            if(i!=edges[*it].size())
            {
                break;
            }
            it++;
        }
        if(it==component->end())
        {
           // sort(bottom.begin() , bottom.end());
           fon(i , bottom.size())
            finalBottom.push_back(bottom[i]+1);
        }
        itr++;
	}
        sort(finalBottom.begin() , finalBottom.end());
        fon(i , finalBottom.size())
        {
            cout<<finalBottom[i]<<" ";
        }
    }
}