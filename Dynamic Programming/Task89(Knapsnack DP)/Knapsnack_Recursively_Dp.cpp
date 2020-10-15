#include <iostream>
using namespace std;
int knapsnack(int * weight ,int * value ,int n ,int kWeight ,int** dp)
{
	if(n<0	|| kWeight==0)
		return  0;
	if(dp[n][kWeight]>-1)
		return dp[n][kWeight];
	int currentSolution;
	if(weight[n]<=kWeight)
	{
		int option1=knapsnack(weight , value , n-1 , kWeight , dp);//just ignore n-th item
		int option2=value[n]+knapsnack(weight , value , n-1 , kWeight-weight[n] ,dp);//include n-th item in knapsnack
		currentSolution	=	(	(option1>option2)?option1:option2	);
	}else{
		currentSolution=knapsnack(weight , value , n-1 , kWeight , dp);//we have to ignore n-th element due to less space in knapsnack
	}
	//before returning currentSolution first store for future use
	dp[n][kWeight]=currentSolution;
	return currentSolution;
}
int main()
{
	int n;
	cin>>n;
	int *weight=new int[n];
	int *value=new int[n];
	for (int i = 0; i <n; ++i)
	{
		cin>>weight[i];
	}
	for (int i = 0; i <n; ++i)
	{
		cin>>value[i];
	}
	int kWeight;
	cin>>kWeight;
	int **dp=new int*[n];
	for (int i = 0; i <n; ++i)
	{
		dp[i]=new int[kWeight+1];
		for (int j = 0; j <=kWeight; ++j)
		{
			dp[i][j]=-1;
		}
	}
	cout<<knapsnack(weight , value , n-1 , kWeight , dp)<<endl;
	//release memory
	for (int i = 0; i <n; ++i)
	{
		delete [] dp[i];
	}
	delete []dp;
}