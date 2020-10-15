#include<iostream>
using namespace std;
int main()
{
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
        int i , p;
        cin>>i>>p;
    while(p--)
    {
        i++;
        if(i>11)
        {
            i %=12;
        }
    }
    cout<<i<<endl;
    }
    return 0;
}
