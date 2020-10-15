#include <iostream>
#include <stdio.h>
using namespace std;
int getMin(int *arr, int n)
{
    int *chocolates=new int[n];
    chocolates[0]=1;
    //first fill chocolate according to left associative
    for(int i=1 ; i<n ; i++)
    {
        if(arr[i]>arr[i-1])
        {
            chocolates[i]=chocolates[i-1]+1;
        }else
        {
            chocolates[i]=1;
        }
    }
    //now fill according right associative
    for(int i=n-2 ; i>=0 ; i--)
    {
        if(arr[i]>arr[i+1]    && chocolates[i]<=chocolates[i+1])
        {
            chocolates[i]=1+chocolates[i+1];
        }
    }
    int ans=0;
    for(int i=0 ; i<n ; i++)
    {
        ans    += chocolates[i];
    }
    delete []chocolates;
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << getMin(arr, n);
    delete []arr;
    return 0;
}

