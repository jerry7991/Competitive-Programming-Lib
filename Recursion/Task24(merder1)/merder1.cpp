#include<iostream>
using namespace std;
typedef long long ll;
ll merge(int *,int ,int,int);
ll mergeSort(int *,int,int);
int main()
{
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
        int n;
    cin>>n;
    int array[n];
    for(int i=0 ;i<n ; i++)
    {
        cin>>*(array+i);
    }
   ll sum=mergeSort(array , 0 ,n-1);
   cout<<sum<<endl;
   /* for(int i=0 ;i<n ; i++)
    {
        cout<<*(array+i)<<" ";
    }*/
    }
    return 0;
}

ll mergeSort(int *array,int start,int end)
{
    ll sum=0;
    if(start >= end)
        {
            return sum;
        }
    int mid=(end+start)/2;

   ll leftSum=mergeSort(array, start, mid);
   ll rightSum= mergeSort(array, mid+1, end);


  ll mergeSum= merge(array , start , mid , end);
  return leftSum+rightSum+mergeSum;
}
ll merge(int *array, int start, int mid, int end)
{
    int temp[end-start];
    ll sum=0;
    int i=start;
    int j=mid+1;
    int k=0;

    //start merge in temp array
    while(i<=mid && j<=end)
    {
        if(*(array+i)<*(array+j))
        {
            sum=sum+(*(array+i))*(end-j+1);
          *(temp+k)=*(array+i);
          k++;i++;
        }
        else
        {
          *(temp+k)=*(array+j);
          k++;
          j++;
        }
    }
    //check still left side has element or not
    if(i<=mid)
    {
        //copy all rest element as it is
        while(i<=mid)
        {
             *(temp+k)=*(array+i);
            k++;
            i++;
        }
    }
    else if(j<=end)     // check still right side has element or not
    {
        //copy all as it is
        while(j<=end)
        {
            *(temp+k)=*(array+j);
            k++;
            j++;
        }
    }
    //make k=0 for which whole temp can be copied in array;
    k=0;
    //lets copy all those element which we have sorted
    for(int l=start;l<=end;l++)
    {

        *(array+l)=*(temp+k);
        //cout<<*(array+l)<<endl;
        k++;
    }
    return sum;
}
