#include<iostream>
using namespace std;
void merge(int *input , int left , int mid , int right)
{
    int i=left;
    int j=mid+1;
    int temp[right-left];
    int k=0;
    while(i<=mid && j<=right)
    {
        if(input[i]<=input[j])
        {
            temp[k++]=input[i++];
        }else{
            temp[k++]=input[j++];
        }
    }
    while(i<=mid)
    {
          temp[k++]=input[i++];
    }
    while(j<=right)
    {
          temp[k++]=input[j++];
    }
    for(i=left , k=0; i<=right; k++,i++)
    {
          input[i]=temp[k];
    }
}
void merge_sort(int *input , int left , int right)
{
    if(left >= right)
    {
        return;
    }
        int mid=(left+right)/2;
        merge_sort(input , left , mid);
        merge_sort(input , mid +1, right);
        merge(input , left , mid , right);
}
void mergeSort(int input[], int size)
{
    merge_sort(input, 0 , size-1);
}
int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
