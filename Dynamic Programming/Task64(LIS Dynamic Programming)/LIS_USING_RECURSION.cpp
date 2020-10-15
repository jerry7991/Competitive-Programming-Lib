#include<iostream>
using namespace std;
int findMax(int *input , int len)
{
    int _max=0;
    for(int i=0 ; i<len ; i++)
    {
        _max=max(input[i] , _max);
    }
    return _max;
}
void LIS_Recursion(int * sequence  ,  int start, int len , int *output)
{
    if(start==len)
        return ;
    output[start]=1;
    for(int j=start-1 ; j>=0 ; j--)
    {
        if(sequence[j]  >= sequence[start])
        {
            continue;
        }
        int possibleAnswer=output[j]+1;
        output[start]= (possibleAnswer >output[start])? possibleAnswer : output[start];
    }
    LIS_Recursion(sequence ,start+1 , len , output);
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
    int *memoTable=new int[len]();
    memoTable[0]=1;
    LIS_Recursion(sequence , 1 ,len , memoTable);
   /* for(int i=0 ; i<len+1 ; i++)
    {
        cout<<*(memoTable+i)<<"\t";
    }
    */
    cout<<"Longest Increasing Subsequence is="<<findMax(memoTable , len)<<endl;
    delete []memoTable;
    delete []sequence;
    return 0;
}
