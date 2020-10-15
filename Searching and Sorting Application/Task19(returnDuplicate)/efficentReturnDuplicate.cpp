#include<iostream>
#include<set>
using namespace std;
int MissingNumber(int arr[], int size)
{
    //find some of n=size natural number
    int sum=(size-1)*(size-2)/2;

    //now find sum of given array
    int newSum=0;
    for(int i=0 ; i< size ; i++)
    {
        newSum+=arr[i];
    }
    if(sum-newSum > 0)//it returns the duplicate element
        return sum-newSum;
    else
        return newSum-sum;
}
int main()
{
    int _size;
    cin>>_size;
    int arr[_size];
    for(int i=0 ; i<_size ; i++)
    {
        cin>>*(i+arr);
    }
    int missing=MissingNumber(arr , _size);
    cout<<missing;
}

