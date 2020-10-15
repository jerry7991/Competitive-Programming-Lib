#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *arr=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	int rSum;
	cin>>rSum;
	bool **dp=new bool*[2];
	for (int i = 0; i <2; ++i)
	{
		dp[i]=new bool[rSum+1];
	}
	//base case
		//base case 1:-if we have no element then we can't make subset
		for (int i = 0; i <=rSum; ++i)
		{
			dp[0][i]=false;
		}
		dp[0][0]=true;//we have 0 sum then our null subset {} full fill the condition
	int flag=1;
	for (int i = 0; i <=n; ++i)
	{
		for (int j = 0; j <=rSum; ++j)
		{
			dp[flag][j]=dp[flag^1][j];
			if(j>=arr[i-1])
			{
				dp[flag][j]= dp[flag][j] || dp[flag^1][j-arr[i-1]];
			}
		}
		flag=flag^1;
	}
	bool isValid=dp[flag^1][rSum];
	//release memory
	 for(int i=0 ; i<2 ;i++)
    {
        delete [] dp[i];
    }
    delete []dp;
	if(isValid)
	{
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}