#include<sys/time.h>
#include<iostream>
#include<conio.h>
using namespace std;
void selectionSort(int *,int);
long getTimeinMicroSeconds()
{
    struct timeval start;
    gettimeofday(&start , NULL);
    return start.tv_sec * 1000000+start.tv_usec;
}
int main()
{
       //cout <<"\n Time in micro second "<<endl;
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
        selectionSort(array,length-1);
        endTime=getTimeinMicroSeconds();
        //cout<<"   end time ="<<endTime<<endl;
        cout <<" Selection sort n = "<<length<<"\t time =  "<<endTime-startTime<<" (in Micro second)\t"<<(double)(endTime-startTime)/1000000<<"(in second)"<<endl;
        startTime=0;
        endTime=0;
    }
    getch();
}
void selectionSort(int *array,int size)
{
    for(int j=0;j<size-1;j++)
    {
        int min=*(array+j);
        int position=j;
        for(int i=j+1;i<size;i++)
        {
        if(*(array+i)<min)
        {
                min=*(array+i);
                position=i;
         }
         //we have found so let's swap them
         int temp=*(array+j);
         *(array+j)=min;
         *(array+position)=temp;
        }
    }
}




















