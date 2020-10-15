#include<iostream>
using namespace std;
int findCost(char *a , char *b , int len)
{
    int cost=0;
    for(int i=0; i <len ; )
    {
        if(a[i]!=b[i])
        {
            //we need to make it equal
            //first look for swapping and in swapping we will be allowed in between consecutive bit which is not equal
            if(a[i]!=a[i+1] && a[i+1]!=b[i+1])  //a[i+1]!=b[i+1] because if we swap then it violate the for i+1 bit because it's equal
            {
                //swap a[i] and a[i+1]
                char temp=a[i+1];   //because 0 and 1 stored in char array so we can use can char variable to swap
                a[i+1]=a[i];
                a[i]=temp;

                i +=2;  //because by swapping we set two consecutive non-equal into equal
                cost++;
            }
            //look for flip
            else
            {
                //just flip a[i];
                a[i]=b[i];
                cost++;
                i++;
            }
        }else
        {
            i++;
        }
    }
    return cost;
}
int main()
{
    int len;
    cin>>len;
    char * a=new char[len];
    char *b=new char [len];
    for(int i=0;i<len;i++)
    {
        cin>>*(a+i);
    }
    for(int i=0;i<len;i++)
    {
        cin>>*(b+i);
    }
    cout<<findCost(a , b, len);
    /*for(int i=0;i<len;i++)
    {
        cout<<*(a+i)<<endl;
    }
    for(int i=0;i<len;i++)
    {
        cout<<*(a+i)<<endl;
    }
    */
    delete a;
    delete b;
    return 0;
}
