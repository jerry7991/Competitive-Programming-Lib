#include <iostream>
#define fon(i , n ) for(int i=0 ; i<n ; i++)
using namespace std;
int getMinCost(int **cost , int n , int person  , int mask)
{
	if (person>=n)
	{
		//all job has assigned
		return 0;
	}
	int minimum=INT_MAX;
	fon(j , n)
	{
		//check weather i-th person assigned job or not
		if (!(mask&(1<<j)))
		{
			//i.e. not assigned
			//so assigned it
			int currCost=getMinCost(cost , n , person+1 , mask | (1<<j))+cost[person][j];
			minimum=(currCost<minimum)?currCost:minimum;
			if (currCost<minimum)
			{
				minimum=currCost;
			}
		}
	}
	return minimum;
}
int main()
{
	int n;
	cin>>n;
	int **cost=new int*[n];
	fon(i , n)
	{
		cost[i]=new int[n];
		fon(j , n)
		{
			cin>>cost[i][j];
		}
	}
	cout<<getMinCost(cost , n ,0,0);
	//release memory
	fon(i ,n )
		delete []cost[i];
	delete []cost;
}
/*
4
10 2 6 5
1 15 12 8
7 8 9 3
15 13 4 10
*/