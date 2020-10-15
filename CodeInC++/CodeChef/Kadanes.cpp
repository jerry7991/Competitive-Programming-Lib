#include<bits/stdc++.h>
using namespace std;
int kadanes(int *,int);
int main()
{
    int n;
    cin >>n;
    int * array=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>*(array+i);
    }
    cout <<kadanes(array,n)<<endl;
}
int kadanes(int *array,int size)
{
    int current_sum=0,best_sum=INT_MIN;
    for(int i=0;i<size;i++)
    {
        current_sum+=*(array+i);
        if(best_sum<current_sum)
            best_sum=current_sum;
        if(current_sum<0)
            current_sum=0;
    }
    return best_sum;
}

