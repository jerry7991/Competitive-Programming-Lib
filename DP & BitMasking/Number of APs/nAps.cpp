#include <bits/stdc++.h>
#define MAX 1000001 
using namespace std;
int numofAP(int *arr , int n)
{
	//initialize the min and max value for the arr
	int minArr=INT_MAX,maxArr=INT_MIN;
	//find min and max value for arr
	for (int i = 0; i < n; ++i)
	{
		minArr=min(arr[i] , minArr);
		maxArr=max(arr[i] , maxArr);
	}
	//dp is going to store the count of ap's ending with arr[i]
	//sum[j] is going to sum of all dp[]'s with j and ap element
	int dp[n] , sum[MAX];

	//answer is n+1 cause single element and none element is a AP
	int answer=n+1;
	for(int d=(minArr-maxArr); d<=(maxArr-minArr) ; d++)
	{
		memset(sum , 0 ,sizeof sum);
		//traversing all the element of givena array
		for (int i = 0; i < n; ++i)
		{
			dp[i]=1;
			//adding counts of AP's with given differences
			if (arr[i]-d>=1 && arr[i]-d<=1000000 )
			{
				dp[i]+=sum[arr[i]-d];
			}
				answer+=dp[i]-1;
				sum[arr[i]] +=dp[i];
		}
	}
	return answer;
}
int main(){

    int N;
    cin >> N;

    int *arr = new int[N+1];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cout << numofAP(arr, N) << endl;

    return 0;
}
