#include <iostream>
#include <queue>
using namespace std;
bool isPrime[20];
void setPrime()
{
	for (int i = 0; i <= 20; ++i)
	{
		isPrime[i]=true;
	}
	for (int p = 2; p*p <= 20; ++p)
	{
		if (isPrime[p])
		{
			//update all multiple of p
			for (int i = p*p; i <= 20; i+=p)
			{
				isPrime[i]=false;
			}
		}
	}
}
int getMinPath(int arr[3][3] , bool isVisited[3][3] , int si , int sj)
{
	isVisited[si][sj]=true;
	int answer=0;
	if ( (si+1)<3 && !isVisited[si+1][sj] && isPrime[ arr[si][sj]+arr[si+1][sj] ] )
	{
		answer = 1+ getMinPath(arr , isVisited , si+1 , sj);
	}
	if ( (sj+1)<3 && !isVisited[si][sj+1] && isPrime[ arr[si][sj]+arr[si][sj+1] ])
	{
		answer = 1+ getMinPath(arr , isVisited , si , sj+1);
	}
	if ( (si-1)>=0 && !isVisited[si-1][sj] && isPrime[ arr[si][sj]+arr[si-1][sj] ] )
	{
		answer = 1+ getMinPath(arr , isVisited , si-1 , sj );
	}
	if ( (sj-1)>=0 && !isVisited[si][sj-1] && isPrime[ arr[si][sj]+ arr[si][sj-1] ])
	{
		answer = 1+ getMinPath(arr , isVisited , si , sj);
	}
	return answer;
}
int main()
{
	int arr[3][3];
	for (int i = 0; i < 3; ++i)
	{
		for(int j=0 ; j<3 ; ++j)
		{
			cin>>arr[i][j];
		}
	}
	int counter=1;
	bool isVisited[3][3];
	for (int i = 0; i < 3; ++i)
	{
		for(int j=0 ; j<3 ; ++j)
		{
			//if currect position
			if (arr[i][j]==counter++)
			{
				isVisited[i][j]=true;
				continue;
			}
			isVisited[i][j]=false;
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		for(int j=0 ; j<3 ; ++j)
		{
			cout<<isVisited[i][j]<<" ";
		}
		cout<<endl;
	}
	setPrime();
	for (int i = 0; i < 3; ++i)
	{
		for(int j=0 ; j<3 ; ++j)
		{
			if ( ! isVisited[i][j])
			{
				int x=getMinPath(arr , isVisited , i , j);
				cout<<x<<endl;
			}
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		for(int j=0 ; j<3 ; ++j)
		{
			cout<<isVisited[i][j]<<" ";
		}
		cout<<endl;
	}
}