#include<iostream>
using namespace std;
int findLBS(int *sequence ,int len)
{
    int *incrSubSequence= new int[len];
    int *decrSubSequence=new int[len];
    *(incrSubSequence)=1;
    *(decrSubSequence+len-1)=1;
    for(int i=1 ; i<len;i++)
    {
        *(incrSubSequence+i)    =   (    *(sequence+i) > *(sequence+i-1)   )  ? *(incrSubSequence+i-1)+1  :1;
    }
    for(int i=len-2 ; i>=0 ; i--)
    {
        *(decrSubSequence+i)    =   (     *(sequence+i) > *(sequence+i+1) )   ? *(decrSubSequence+i+1)+1    :1;
    }
    int bestMax=*(incrSubSequence+0)+*(decrSubSequence+0)-1;
    for(int i=1 ; i<len ; i++)
    {
        //cout<<bestMax<<"\t";
        bestMax=    (      (*(incrSubSequence+i)+*(decrSubSequence+i)-1) >bestMax    )  ? (*(incrSubSequence+i)+*(decrSubSequence+i)-1) : bestMax;
      }
      delete []incrSubSequence;
      delete []decrSubSequence;
      return bestMax;
}
int main()
{
    int len;
    cin>>len;
    int *sequence=new int[len];
    for(int i=0 ; i<len ; i++)
    {
        cin>>*(sequence+i);
    }
    cout<<findLBS(sequence , len)<<endl;
    delete[]sequence;
    return 0;
}
