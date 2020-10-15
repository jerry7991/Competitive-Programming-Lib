#include<bits/stdc++.h>
using namespace std;
void display( int * array , int len)
{
    cout<<endl;
for(int i=1 ; i<=len ; i++)
    {
        cout<<*(array+i)<<" ";
    }
    cout<<endl;
}
int main()
{
    int len;
    cin>>len;
    int * array=new int[len];
    for(int i=1 ; i<=len ; i++)
    {
        cin>>*(array+i);
    }
    int temp=array[1];
    int count=0;
    cout<<endl;
    while(count<=len)
        {
           if(array[temp]!=temp)
           {
            cout<<temp<<"\t";
            int base=array[temp];
            //no need to check about element because each element is distinct
            array[temp]=temp;
            temp=base;
           }
           else{
                //it means array[temp] has right value so search just next of it
                temp=array[temp];
           }
            count++;
            display(array , len);
        }
        cout<<endl;

    return 0;
}
