#include<iostream>
using  namespace std;
bool checkNumber(int [],int ,int);
int main()
{
    int n,x,*input;
    cin >>n;
    for(int i=0;i<n;i++)
        cin >>*(input+i);
    cin >>x;
    if(checkNumber(input,n,x))
        cout <<"given number found"<<endl;
    else
        cout <<"not found"<<endl;
}
bool checkNumber(int *input,int size,int x)
{
    if(size==0)
        return false;
    if(*input==x)
        return true;
    return (checkNumber(input+1,size-1,x));
}
