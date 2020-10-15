#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int array[n];
    for(int i=0 ; i<n;i++)
    {
        cin>>array[i];
    }

    int time=0;
    int i=0;
    while(true)
    {
        if(array[i]-time <=0)
        {
            cout<<i+1;
            break;
        }
        i++;
        time++;
        if(i>=n)
        {
            i%=n;
        }
    }
}

