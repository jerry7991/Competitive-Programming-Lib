#include<iostream>
#define LEN 1024
using namespace std;
void findMaxEntry(int * arr,int * bestMax , int * bestMin)
{
    for(int i=0;i<LEN;i++)
    {
        *bestMax    =   (arr[i] > *bestMax) ? arr[i] : *bestMax;
        *bestMin    =   (arr[i] <   *bestMin  ) ?   arr[i]  : *bestMin;
    }
}
int main()
{
    int n,k,x;
    cin>>n>>k>>x;
    int *frequency=new int[LEN];
    for(int i=0 ;i< LEN ; i++)
    {
        *(frequency+i)=0;
    }
    while(n--)
    {
        int temp;
        cin>>temp;
        *(frequency+temp)   +=1;
    }
    int *entries=new int[LEN];
     for(int i=0 ;i< LEN ; i++)
    {
        *(entries+i)=0;
    }
    while(k--)
    {
        int totalEntries=0;
      for(int i=0 ;i<LEN  ;   i++)
        {
            if(frequency[i]==0)
                continue;
            int current=   *(frequency+i)  -   *(frequency+i)/2;;

            current =   (totalEntries & 1 ==0)  ?   current :   current+1;

            int index= i^x;

            *(entries   +index) +=current;
            *(entries   +i) =   *(frequency+i)-current;

            totalEntries    +=  *(frequency+i);
        }
    }
    for(int i=0 ; i<LEN ; i++)
    {
        if(entries[i]>0)
        {
            cout<<entries[i]<<"  ";
        }
    }
    int maxEntry=INT_MIN,minEntry=INT_MAX;
    findMaxEntry(entries    , &maxEntry,    &minEntry);
    cout<<maxEntry<<" "<<minEntry;
    return 0;
}
