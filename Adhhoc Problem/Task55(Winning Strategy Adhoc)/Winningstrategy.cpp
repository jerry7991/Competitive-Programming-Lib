#include<iostream>
using namespace std;
void swapNumber(int * a , int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void checkWinningPossibility(int * position ,int player)
{
    int totalSwap=0;
    for(int i=player-1 ; i>=0 ; i--)
    {
        if(position[i]!=(i+1))//we need set position for i-th player to win
        {
            if(position[i-1]==(i+1))
            {
                //need to swap i-th and i-1 th player and total swap increment by 1
                swapNumber((position+i) ,(position+(i-1)));
                totalSwap++;
            }
            else if(position[i-2]==(i+1))
            {
                //first swap (i-1)-th and (i-2)-th
                //second swap (i-1)-th and i-th
                swapNumber((position+(i-1)) , (position+(i-2)));
                totalSwap++;
                swapNumber((position+i) , (position+(i-1)));
                totalSwap++;
            }
            else
            {
                // that's means i-th player is too large from their required position and for setting them into their required position
                //we need to swap more than 2 times of those player which is not allowed
                //so winning strategy failed return no;
                cout<<"NO";
                return;
            }
        }
    }
    //if everything was fine so function is still on stack it mean all player positioned to their required winning position
    //so return yes and print min number of swap required
    cout<<"YES"<<endl<<totalSwap;
}
int main()
{
    int player;
    cin>>player;
    int * position=new int[player];
    for(int i=0 ; i<player ; i++)
    {
        cin>>*(position+i);
    }
    checkWinningPossibility(position , player);
    delete position;
    return 0;
}
