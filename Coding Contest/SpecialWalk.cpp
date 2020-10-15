#include <iostream>
#include <vector>
using namespace std;
int n,m;
void printWalk(vector<int>*edge )
{
  bool *visited=new bool[n];
  bool *specialWalk=new bool[n];
  for(int i=0 ; i<n ;i++) visited[i]=specialWalk[i]=false;
  for(int i=0 ; i<n ; i++)
  {

  }
}
int main()
{
  cin>>n>>m;
  vector<int>*edge=new vector<int>[n];
  for(int i=0 ; i<n ; i++)
  {
    int src,dest;
    cin>>src>>dest;
    edge[src-1].push_back(dest-1);
  }
  printWalk(edge);
}
