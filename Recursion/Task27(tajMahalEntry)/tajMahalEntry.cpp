#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int * array=new int[n];
    for(int i=0 ; i<n;i++)
    {
        cin>>*(array+i);
    }

    //for each i+t*n==array[i]; ahad will come again on i-th window so let's coming time for getting window ticket
    int * getTime=new int[n];
    for(int i=0; i<n; i++)
    {
        int ans=(array[i]-i)/(n-1);
        //ans=(( *(array+i)-i)%n==0)? ans : (ans+1);
        if((array[i]-i)%(n)!=0))
        {
            ans=ans+1;
        }
        *(getTime+i)=i+ans*(n-1);
    }
     for(int i=0 ; i<n;i++)
    {
        cout<<*(getTime+i)<<" ";
    }
    int minTime=INT_MAX;
    int windowNumber=0;
    for(int i=0;i<n;i++)
    {
        if( *(getTime+i) < minTime)
        {
            minTime= *(getTime+i) ;
            windowNumber=i;
        }
    }
    cout<<windowNumber+1<<endl;
    return 0;
}
