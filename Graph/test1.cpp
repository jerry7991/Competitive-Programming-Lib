
#include <bits/stdc++.h>
using namespace std;

int* fun()
{
    int arr[5];
    for(int i=0;i<5;i++)
    {
        arr[i]=i;
    }
    return arr;
}

int main()
{
    int* arr=fun();
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}