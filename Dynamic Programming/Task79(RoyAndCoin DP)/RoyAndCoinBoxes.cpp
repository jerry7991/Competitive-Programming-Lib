#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int * start=new int[n];
    int * end=new int[n];
    for(int i=1; i<=m ; i++)
    {
        *(start+i)=0;*(end+i)=0;
    }
    for(int i=1; i<=m ; i++)
    {
        int si,ei;
        cin>>si>>ei;
        *(start+si) +=1;
        *(end+ei)   +=1;
    }
    int q;
    cin>>q;
    int *query=new int[q];
    for(int i=0 ; i<q;i++)
    {
        cin>>*(query+i);
    }
    //now we have data that which index came how many times;
    //so let's maintain coin
    int *coin=new int[n];
    *(coin+1)=*(start+1);
    int maxCoin=0;
    for(int i=2 ;   i<=n ;   i++)
    {
        *(coin + i)=    *( start+i  )   -   *(end+i-1)  +   *(coin+i-1);
    }
    //now we have to give output of queries within constant time so let's reverse coin with their index
    //let's store which coin comes how many times
    maxCoin=1000000;
    int *arr=new int[maxCoin];
    for(int i=1 ; i<=maxCoin;i++)
        arr[i]=0;
    for(int i=1 ; i<=n;i++)
    {
        *(arr  +  *(coin+i) )  +=1;
    }
    //let's make coin array as each i-th index tell that number of coins at least i-th coins
    for(int i=maxCoin-1   ;   i>0    ;   i--)
    {
        *(arr+i)   +=  *(arr+i+1);
    }
    for(int i=0 ;i<q;i++)
    {
       cout<<*(arr+query[i])<<endl;
    }
    delete []start;
    delete []end;
    delete []query;
    delete []coin;
    delete  []arr;
    return 0;
}