#include<iostream>
using namespace std;
long staircase(int n)
{
    //base case
    if(n==0 || n==1)
        return 1;
    if(n==2)
        return 2;
    long includeOneStep=staircase(n-1);
    long includeTwoStep=staircase(n-2);
    long includeThreeStep=staircase(n-3);
    return (includeOneStep+includeTwoStep+includeThreeStep);
}
long staircase_Using_Dp(int n , long * output)
{
    if(n==0 || n==1)
        return 1;
    if(n==2)
        return 2;
    long includeOneStep=staircase(n-1);
    long includeTwoStep=staircase(n-2);
    long includeThreeStep=staircase(n-3);
    long answer=includeOneStep+includeTwoStep+includeThreeStep;
    output[n]=answer;
    return output[n];
}
long staircase_Using_DP_Iteration(int n)
{
    long *output=new long[n+1];
    //base case=
    output[0]=1;
    output[1]=1;
    output[2]=2;
    for(int i=3 ; i<=n ;i++)
    {
        output[i]=output[i-1]+output[i-2]+output[i-3];
    }
    long ans=output[n];
    delete [] output;
    return ans;
}
int main()
{
  int n;
  cin >> n ;
  cout << staircase(n) << endl;
  //but in staircase() their is many duplicate call was happening

    //let's do recursion using dp
    long * memoTable=new long[n];
    cout<<staircase_Using_Dp(n , memoTable)<<endl;
    delete []memoTable;
    //but in staircase_Using_Dp Time complexity=O(2*N) and space complexity O(N)
    cout<<staircase_Using_DP_Iteration(n)<<endl;
    //let's do dp using iteration and instead of filling from end to start and then go to end and return value , we fill array from start to end and return end
}



