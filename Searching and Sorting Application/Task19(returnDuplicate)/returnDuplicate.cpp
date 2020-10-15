#include<iostream>
#include<set>
using namespace std;
int MissingNumber(int arr[], int size)
{
    set<int> distinctNumber;
    for(int i=0 ; i<size ; i++)
    {
        if(distinctNumber.find(arr[i]) != distinctNumber.end())
            return arr[i];
        else{
            distinctNumber.insert(arr[i]);
        }
    }
    return -1;
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
//but not efficient let's look an efficient code

