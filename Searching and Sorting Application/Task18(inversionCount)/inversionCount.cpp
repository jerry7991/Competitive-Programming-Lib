#include<iostream>
using namespace std;
 long long merge(int *A, int left, int mid , int right)
 {
     long long count=0;
     int i=left;
     int j=mid;
     int k=0;//for temp array
     int temp[right-left+1];
     while(i<mid && j<=right)
     {
            if(A[i] <= A[j])
            {
                /*no inversion count because inversion count will be, when,
                    A[i]>A[j] && i<j
                */
                temp[k++]=A[i++];
            }
            else
            {
                temp[k++]=A[j++];
                count +=mid-i;  //means from i to mid every element is greater that's every element make inversion count
            }
     }
     while(i<mid)
     {
        temp[k++]=A[i++];
     }
     while(j<=right)
     {
        temp[k++]=A[j++];
     }
     //and now let's copy
     for(int i=left , k=0 ; i<=right ; i++ , k++)
     {
         A[i]=temp[k];
     }

     return count;
 }
long long merge_sort(int * A , int left , int right)
{
    long counter=0;
    //base case
    if(left < right)
    {
        int mid=(left+right)/2;
        long long count_left=merge_sort(A , left , mid);
        long long count_right=merge_sort(A, mid+1 , right);
        long long myCount=merge(A , left , mid+1 , right);

        return myCount+count_left+count_right;
    }
    return counter;
}

long long solve(int A[], int n)
{
  long long ans=merge_sort(A,0,n-1);
  return ans;
}

int main()
{
    int _length;
    cin>>_length;
    int _array[_length];
    for(int i=0 ; i<_length ; i++)
    {
        cin>>*(i+_array);
    }
    long long numberOfInversion=solve(_array , _length);
    cout<<numberOfInversion;
}