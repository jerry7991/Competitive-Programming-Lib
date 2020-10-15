#include<sys/time.h>
#include<iostream>
#include<conio.h>
using namespace std;
void merge(int *,int ,int,int);
void mergeSort(int *,int,int);
long getTimeinMicroSeconds()
{
    struct timeval start;
    gettimeofday(&start , NULL);
    return start.tv_sec * 1000000+start.tv_usec;
}
int main()
{
       cout <<"\n Time in micro second "<<endl;
    for(int length=10; length<=1000000; length*=10)
    {
        int *array=new int[length];
        long startTime,endTime;
        for(int i=0;i<length;i++)
        {
            *(array+i)=length-i;
        }
        startTime=getTimeinMicroSeconds();
        //cout <<"\n start time " <<startTime;
        mergeSort(array,0,length-1);
        endTime=getTimeinMicroSeconds();
        //cout<<"   end time ="<<endTime<<endl;
         cout <<" Merge sort n = "<<length<<"\t time =  "<<endTime-startTime<<" (in Micro second)\t"<<(double)(endTime-startTime)/1000000<<"(in second)"<<endl;
        startTime=0;
        endTime=0;
    }
    getch();
}

void mergeSort(int *array,int start,int end)
{
    if(start >= end)
        {
            return;
        }
    int mid=(end+start)/2;

    mergeSort(array, start, mid);
    mergeSort(array, mid+1, end);

    merge(array , start , mid , end);
}
void merge(int *array, int start, int mid, int end)
{
    int temp[end-start];
    int i=start;
    int j=mid+1;
    int k=0;

    //start merge in temp array
    while(i<=mid && j<=end)
    {
        if(*(array+i)<*(array+j))
        {
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
}






















