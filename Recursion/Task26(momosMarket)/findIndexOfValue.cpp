#include<bits/stdc++.h>
using namespace std;
int findNearestIndex(int *array , int value , int left , int right)
{
    int mid=0;
    if(left <= right)
    {
         mid=(left+right)/2;
         if(array[mid]==value)
         {
             return mid;
         }
        else if(array[mid] < value && array[mid+1] >value)
            return mid;
        else if(array[mid] > value)
        {
            //need to left search
            return findNearestIndex(array , value , left , mid-1);
        }
        else
        {
            //need to right search
            return findNearestIndex(array , value ,mid+1 , right);
        }
        return mid;
    }
}
int main()
{
  int array[10]={1,2,3,4,5,7,9,10,11,12};
  int shopNumber=findNearestIndex(array , 12 ,0, 9 );
  cout<<shopNumber;
}
