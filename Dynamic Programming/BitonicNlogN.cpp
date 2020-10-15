#include<iostream>
using namespace std;
int ceilIndex(int *arr ,int left,int right,int value)
{
  int mid;
  if(arr[left]<=value)
    return left;
  if(arr[right]<value)
    return -1;
  mid=(left+right)/2;
  if(arr[mid]==value)
    return mid;
  else if(arr[mid]<value)
  {
    if(mid+1<=right && value<=arr[mid+1])
      return mid+1;
    else
      return ceilIndex(arr , mid+1,right , value);
  }else{
    if(mid-1>=left && value>arr[mid-1])
      return mid;
    else
      return ceilIndex(arr , left , mid-1 ,value);
  }
}
void reverse(int *arr , int n)
{
  int i=0 ,j=n-1;
  while(i<j)
  {
    swap(arr[i++] , arr[j--]);
  }
}
int LBS(int *arr , int n)
{
  //we need four array
  //for increasing subsquence
  int *increasing=new int[n];
  //tail1 tells the length of longest increasing subsquence till i-th
  int *tail1=new int[n];

  //for decreasing subsquence
  int *decreasing=new int[n];
  //tail2 tells the length of longest decreasing subsquence till i-th
  int *tail2=new int[n];

  //now lets first cal the longest increasing subsquence
  int len=1;
  tail1[0]=0;
  increasing[0]=arr[0];
  for(int i=1; i<n;i++)
  {
    //if the current element is less then the 0-th element of increasing[0]
    if (arr[i]<increasing[0]) {
      increasing[0]=arr[i];
      //now the length of longest increasing subsquence for current index will be 0
      tail1[i]=0;
    }
    //if the current element is greater then the last element of increasing
    else if (arr[i]>increasing[len-1]) {
      increasing[len++]=arr[i];
      //now length of longest increasing subsquence till i
      tail1[i]=len-1;
    }else{
      int index=ceilIndex(increasing , -1,len-1,arr[i]);
      increasing[index]=arr[i];
      index=ceilIndex(increasing , -1,len-1,arr[i]);
      tail1[i]=index;
    }
  }
  //now re-intialize the len for decreasing subsquence
  len=1;
  //first reverse the array
  reverse(arr , n);
  decreasing[0]=arr[0];
  tail2[0]=0;
  for(int i=1;i<n ; i++)
  {
    if(decreasing[0]>arr[i])
    {
      decreasing[0]=arr[i];
      //and length will be 0;
      tail2[i]=0;
    }else if(decreasing[len-1]<arr[i]){
        decreasing[len]=arr[i];
        tail2[i]=len;
        len++;
    }else{
      int index=ceilIndex(decreasing , -1, len-1,arr[i]);
      decreasing[index]=arr[i];
      index=ceilIndex(decreasing , -1,len-1 , arr[i]);
      tail2[i]=index;
    }
  }
  //now have to reverse tail2 arr to get largest decreasing subsquence till each i-th
  reverse(tail2,n);
  int ans=0;
  for(int i=0 ; i<n ; i++)
  {
      ans=max(ans , tail1[i]+tail2[i]+1);
  }
  return ans;
}
int main()
{
  int n;cin>>n;
  int *arr=new int[n];
  for(int i=0  ; i<n ; i++)
  {
    cin>>arr[i];
  }
  cout<<LBS(arr , n);
  return 0;
}
