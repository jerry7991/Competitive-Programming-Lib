#include <iostream>
#include <algorithm>
#define fon(i,n) for(int i=0; i<n ; i++)
using namespace std;
struct WeightMatrix
{
	int src,dest,weight;
};
bool compare(WeightMatrix w1 ,WeightMatrix w2)
{
	return w1.weight<w2.weight;
}
int getParent(int *parent ,int s)
{
	if (parent[s]==s)
	{
		return s;
	}
	return getParent(parent , parent[s]);
}
void getMST(WeightMatrix* edges ,int n ,int m , WeightMatrix *mst)
{
	int *parent=new int[n];
	fon(i , n) parent[i]=i ;
	int count=0;
	int i=0;
	while(count<n-1)
	{
		int s=edges[i].src;
		int d=edges[i].dest;
		int sParent=getParent(parent , s);
		int dParent=getParent(parent , d);
		if (sParent!=dParent)
		{
			mst[count]=edges[i];
			count++;
			parent[sParent]=dParent;
		}
		i++;
	}
}
int main()
{
	int n,m ,nQuery;
	cin>>n>>m>>nQuery;
	WeightMatrix *edges=new WeightMatrix[2*m];
	fon(i , m)
	{
		int source,destination,wt;
		cin>>source>>destination>>wt;
		edges[i].src=source-1;
		edges[i].dest=destination-1;
		edges[i].weight=wt;
		edges[i+1].src=destination-1;
		edges[i+1].dest=source-1;
		edges[i+1].weight=wt;i++;
	}
	//first of all short the WeightMatrix
	sort(edges , edges+m , compare);
	WeightMatrix *mst=new WeightMatrix[n-1]();
	getMST(edges , n , m, mst);
	while(nQuery--)
	{
		int s,d;
		cin>>s>>d;
		s--,d--;
		int i=0;
		int w=0;
		while(mst[i].src!=s) i++;
		while(i<n-1 && mst[i].dest!=d) w +=mst[i].weight , i++;
		if(i==n-1)
		{
			cout<<-1<<endl;
		}else{
			cout<<w+mst[i].weight<<endl;
		}
	}
}