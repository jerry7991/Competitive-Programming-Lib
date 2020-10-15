#include<bits/stdc++.h>
using namespace std;
bool isSorted(int *skills , int len)
{
    if(len==0 || len==1)
        return true;
    if(skills[0] >skills[1])//for all length if any a[0] >a[1] that's means not sorted in ascending order
        return false;
        return isSorted(skills+1 , len-1);
}
bool checkPossibility(int *skills , int len)
{
    for(int i=0 ; i<len-1 ; i++)
    {
        if(skills[i+1]==skills[i]-1)
        {
            swap(skills[i+1] , skills[i]);
        }
    }
    /*for(int i=0 ; i<len ; i++)
    {
        cout<<skills[i]<<"  ";
    }
    */
    return isSorted(skills , len);
}
int main()
{
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
        int len;
        cin>>len;
        int * skills=new int[len];
        for(int i=0 ; i<len ; i++)
        {
            cin>>skills[i];
        }
        if(checkPossibility(skills , len))
        cout<<"true"<<endl;
        else
            cout<<"false"<<endl;
    }
    return 0;
}
