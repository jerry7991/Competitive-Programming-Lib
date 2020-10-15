#include <iostream>
using namespace std;
//int countx;
int getConnected1(int **arr , bool **visited , int n , int m , int si,int sj , int count)
{
	//countx++;
	visited[si][sj]=true;
	//right
	int ans=0;
	if ((si+1)<n && arr[si+1][sj] && !visited[si+1][sj])
	{
		ans+= 1+getConnected1(arr , visited , n , m , si+1 , sj , count+1);
	}
	//left
	if ((si-1)>=0 && arr[si-1][sj] && !visited[si-1][sj])
	{
		ans+= 1+getConnected1(arr , visited , n , m , si-1 , sj , count+1);
	}
	//up
	if ((sj-1)>0 && arr[si][sj-1] && !visited[si][sj-1])
	{
		ans+= 1+getConnected1(arr , visited , n , m , si , sj-1 , count+1);
	}
	//down
	if ((sj+1)<m && arr[si][sj+1] && !visited[si][sj+1])
	{
		ans+= 1+getConnected1(arr , visited , n , m , si , sj+1 , count+1);
	}
	if((si+1)<n && (sj+1)<m && arr[si+1][sj+1] && !visited[si+1][sj+1])
	{
		ans+= 1+getConnected1(arr , visited , n , m ,si+1 , sj+1 , count+1);
	}
	if((si-1)>=0 && (sj-1)>=0 && arr[si-1][sj-1] && !visited[si-1][sj-1])
	{
		ans+= 1+getConnected1(arr , visited , n , m ,si-1 , sj-1 , count+1);
	}
	if((si+1)<n && (sj-1)>=0 && arr[si+1][sj-1] && !visited[si+1][sj-1])
	{
		ans+= 1+getConnected1(arr , visited , n , m ,si+1 , sj-1 , count+1);
	}
	if((si-1)>=0 && (sj+1)<m && arr[si-1][sj+1] && !visited[si-1][sj+1])
	{
		ans+= 1+getConnected1(arr , visited , n , m ,si-1 , sj+1 , count+1);
	}
	return ans;
}
int getMaxOnes(int **arr,int n,int m)
{
    bool **visited=new bool*[n];
    for (int i = 0; i < n; ++i)
    {
    	visited[i]=new bool[m];
    	for(int j=0 ; j<m ; j++)
    	{
    		visited[i][j]=false;
    	}
    }
    int currMax=0;
    for (int i = 0; i < n; ++i)
    {
    	for(int j=0 ; j<m ; j++)
    	{
    		if(!visited[i][j] && arr[i][j])
    		{
    			int ans=1+getConnected1(arr , visited , n , m , i , j,0);
    			if(ans>currMax)
    			{
    				currMax=ans;
    			}
    		}
    	}
    }
    return currMax;
}
int main()
{
	int n,m;
	cin>>n>>m;
	int **arr=new int*[n];
	for (int i = 0; i < n; ++i)
	{
		arr[i]=new int[m];
		for(int j=0 ; j<m;j++)
			cin>>arr[i][j];
	}
	cout<<getMaxOnes(arr ,n , m);
}