#include<iostream>
using namespace std;
bool checkWinningStep(int *,int );
int steps=0;
int main()
{
    int *array,size;
    cin >>size;
    for(int i=0;i<size;i++)
    {
        cin >>array[i];
    }
    if(checkWinningStep(array,size))
    {
        cout <<"Won in "<< steps<<" step";
    }else{
        cout <<"Defeated and total "<<steps <<" jumped";
    }
    return 0;
}
bool checkWinningStep(int *array,int size)
{
    if(size==1) //that's means , frog reached their last position
    {
        return true;
    }
    else if(*array==0 && size>1)
    {
        cout <<"Can't jump further"<<endl<<"0 jump steps found"<<endl;
        return false;
    }
    else if(size<1)
    {
        cout << "defeated"<<endl;
        return false;
    }
    else
    {
        steps++;
         return checkWinningStep(array+*array,size-*array);
    }
}
