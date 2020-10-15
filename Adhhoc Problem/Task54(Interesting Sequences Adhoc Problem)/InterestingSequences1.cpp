
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int getCost(int * sequence ,int len , int balancedPosition ,int incDecCost , int incCost )
{
    int decrement=0 , increment=0;
    for(int i=0 ; i<len ; i++)
    {
        if(sequence[i] >balancedPosition)
        {
            decrement +=(sequence[i]-balancedPosition);
        }
        if(sequence[i] < balancedPosition)
        {
            //needs to increment
            increment +=(balancedPosition - sequence[i]);
        }
    }
    if(increment >= decrement)
    {
        return decrement*incDecCost+(increment-decrement)*incCost ;
    }
    else
    {
        return INT_MAX ;
    }
}
int main()
{
    int len , costOfChoice1 , costOfChoice2;
    cin>>len>>costOfChoice1>>costOfChoice2;

    int * sequence=new int[len];
    for(int i=0 ; i<len ; i++)
    {
        cin>>*(sequence+i);
    }

    int _min=sequence[0];
    int _max=sequence[0];
    //find max and min element
    for(int i=0 ; i<len ; i++)
    {
        if(sequence[i]>=_max)
        {
            _max=sequence[i];
        }
        if(sequence[i]<=_min)
        {
            _min=sequence[i];
        }
    }
    int totalCost=INT_MAX;
    int i=0;
    for(i=_min ; i<=_max ; i++)
    {
        int tempCost=getCost(sequence ,len, i , costOfChoice1 , costOfChoice2);
        totalCost=min(tempCost , totalCost);
    }
    //cout<<totalCost<<"  "<<i;
    cout<<totalCost;
    return 0;
}
