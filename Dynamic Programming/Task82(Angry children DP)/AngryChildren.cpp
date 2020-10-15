#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int packet,student;
    cin>>packet>>student;
    int * candies=new int[packet];
    for(int i=1 ; i<=packet  ;   i++)
    {
        cin>>*(candies+i);
    }
    sort(candies+1 , candies+packet+1);
    int *candiesSum=new int[packet];
    //add sum  i.e. each i-th of candiesSum will tell the sum of candies from 0-ith packets
    *(candiesSum+1)=    *(candies+1);
    for(int i=2;i<=packet;i++)
    {
        *(candiesSum+i) =   *(candiesSum+(i-1)) +   *(candies+i);
    }
    //let's find cost for student in candies for 0-numberOfStudent
    //int newTarget=0;
    int target=0;
    for(int i=2 ;   i<=student   ;   i++)
    {
        target =target+ (i-1)*candies[i]    -   (candiesSum[i-1]);
    }
    int newCost=0;
    int oldCost=target;
    for(int i=1 ;   i<=(packet-student)  ;   i++)
    {
        int k=student+i;
        newCost    =   oldCost    -   (candiesSum[student]  - candiesSum[i]  )   + i*candies[i] +student*candies[student+1] +  -(candiesSum[student]-candiesSum[i+1])  ;
        if(newCost<oldCost)
        {
            target=newCost;
        }
        oldCost=newCost;
    }
    cout<<target;
}
