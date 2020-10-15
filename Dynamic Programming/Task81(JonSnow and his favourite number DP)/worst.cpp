#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,k,x;
    cin>>n>>k>>x;
    int *arr=new int[n];
    for(int i=0  ; i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr , arr+n);
    while(k--)
    {
        for(int i=0;i<n;i+=2)
        {
            arr[i]=arr[i]^x;
        }
        sort(arr , arr+n);
    }
    cout<<arr[n-1]<<" "<<arr[0];
}
