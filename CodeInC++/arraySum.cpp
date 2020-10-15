#include<iostream>
using namespace std;
int sum(int [],int);
int main()
{
    int *input,n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin >>*(input+i);
     int s=sum(input ,n);
     cout <<s;
}
int sum(int input[],int n)
{
    if(n==0)
    {
           return 0;
    }
    else
    {
        return input[n-1]+sum(input,n-1);
    }
}
