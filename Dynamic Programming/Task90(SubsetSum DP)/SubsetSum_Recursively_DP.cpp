#include <iostream>
using namespace std;
int isValidSubSetSum(int *arr ,int n ,int subsetSum ,int **dp)
{
	//base case
	if(subsetSum==0)
	{
		return 1;
	}
	if(n<0 || subsetSum<0)
	{
		return 0;
	}
	if(dp[n][subsetSum]!=-1)
		return dp[n][subsetSum];
	//now we have two option
	//option 1:- we can skip n-th element for subset
	int option1=isValidSubSetSum(arr , n-1 , subsetSum , dp);
	//option 2:- we can take into in subset to n-th element
	//but before it we have to check weather n-th element is valid or not
	int option2;
	if(subsetSum >=arr[n])
	{
		option2=isValidSubSetSum(arr , n-1 ,subsetSum-arr[n] ,dp);
	}
	dp[n][subsetSum]=(option1 || option2);
	return (option1 || option2);
}
int main()
{
	int n;
	cin>>n;
	int * arr=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>*(arr+i);
	}
	int subsetSum;
	cin>>subsetSum;
	int **dp=new int*[n+1];
	for (int i = 0; i <=n; ++i)
	{
		dp[i]=new int[subsetSum+1];
		for (int j = 0; j <=subsetSum; ++j)
		{
			dp[i][j]=-1;
		}
	}
	int isValid=isValidSubSetSum(arr ,n , subsetSum ,dp);
	if(isValid==1)
	{
		cout<<"Yes";
	}else{
		cout<<"No";
	}
}