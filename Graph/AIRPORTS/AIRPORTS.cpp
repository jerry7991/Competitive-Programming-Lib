#include<iostream>
#include <algorithm>
#define fon(i,n) for(int i=0 ; i<n ; i++)
using namespace std;
struct Path
{
	int src,dest,roadCost;
};
bool compare(Path p1 , Path p2)
{
	return p1.roadCost<p2.roadCost;
}
int getParent(int *parent , int src)
{
	if(parent[src]==src)
		return src;
	return getParent(parent , parent[src]);
}
void getMinCost(Path * path ,int n ,int m , int airPCost,int p)
{
	//first sort the given path data accordingly to their cost
	sort(path , path+m , compare);
	//need a parent :-
	int *parent=new int[n];
	int currWeight=0;
	fon(i , n)
	{
		parent[i]=i;
	}
	fon(i , m)
	{
		int srcParent=getParent(parent , path[i].src);
		int destParent=getParent(parent , path[i].dest);
		if (srcParent==destParent)//no need to add road because they are in same cycle
		{
			continue;
		}
		//need to add a component
		if ( path[i].roadCost < airPCost)
		{
			currWeight +=path[i].roadCost;
			//cout<<currWeight<<endl;
			//make destination in same component
			parent[srcParent]=destParent;
		}
		//cout<<currWeight<<" ";
	}
	int totalCost=0;
	int nAir=0;
	fon(i , n)
	{
		nAir = (parent[i]==i)?nAir+1 : nAir;
        //cout<<parent[i]<<" ";
	}
	totalCost=currWeight+nAir*airPCost;
	cout<<"Case #"<<p+1<<": "<<totalCost<<" "<<nAir<<endl;
}
int main()
{
	int t;
	cin>>t;
	int p=0;
	fon(p , t)
	{
		int n,m,airPCost;
		cin>>n>>m>>airPCost;
		Path *path=new Path[m];
		fon(i, m)
		{
			int s,d,c;
			cin>>s>>d>>c;
		 	path[i].src=s-1;
		 	path[i].dest=d-1;
		 	path[i].roadCost=c;
		}
		getMinCost(path , n , m ,airPCost,p);
		//p++;
	}
	return 0;
}