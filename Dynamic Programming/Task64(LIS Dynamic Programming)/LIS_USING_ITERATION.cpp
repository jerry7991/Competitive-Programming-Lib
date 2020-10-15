#include<iostream>
using namespace std;
int LIS_ITERATION(int *sequence , int len)
{
    int *output=new  int[len];
    *(output)=1;    // at worst case at least 1 increasing subsequence will be possible
    for(int i=1 ;i<len ; i++)
    {
        //at worst case at least 1 increasing subsequence will be possible for each i-th element
        *(output+i)=1;
        for(int j=i-1 ; j>=0 ; j--)
        {
            if(    *(sequence+j) >= *(sequence+i)  )
            {
                //nothing gonna happen
                continue;
            }
            //else happen
            int possibleAnswer=*(output+j) +1;

            *(output+i)= (    possibleAnswer > *(output+i)  )   ?  possibleAnswer : *(output+i) ;
        }
    }
    int bestMax=0;
    for(int i=0 ; i<len  ; i++)
    {
        bestMax =   (     bestMax< *(output+i)  )   ? *(output+i) : bestMax;
    }
    delete []output;
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
    cout<<LIS_ITERATION(sequence , len);
    delete []sequence;
    return 0;
}
