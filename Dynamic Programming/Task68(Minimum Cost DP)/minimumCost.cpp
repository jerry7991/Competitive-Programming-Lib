#include<iostream>
using namespace std;
int findMinCost(int ** grid ,int i_start ,int  j_start ,int i_end ,int j_end)
{
    //base case
    if( i_start==i_end  && j_start==i_end)
    {
        return grid[i_end][j_end];
    }
    if(i_start >i_end || j_start>j_end) //if i_start go beyond the limit
    {
        return INT_MAX;
    }
    //otherwise we have three option to move
    //first option  move bottom--------------
    int moveBottom=findMinCost(grid , i_start+1 , j_start , i_end , j_end);
    //second option is move right------------
    int moveRight=findMinCost(grid , i_start , j_start+1 , i_end , j_end);
    //third option is move diagonal
    int moveDiagonal=findMinCost(grid , i_start+1 , j_start+1 , i_end , j_end);

    return (    grid[i_start][j_start]+min(moveBottom    , min(moveRight , moveDiagonal)   )    );
}
int main()
{
    int row , col;
    cin>>row>>col;
    int ** grid=new int*[row];
    for(int i=0 ; i<row ; i++)
    {
        grid[i]=new int[col];
    }
    for(int i=0 ; i<row ; i++)
    {
        for(int j=0 ; j<row ;j++)
        {
            cin>>grid[i][j];
        }
    }
    int i_start , j_start;
    cin>>i_start>>j_start;
    int i_end , j_end;
    cin>>i_end>>j_end;
    cout<<findMinCost(grid , i_start , j_start , i_end , j_end)<<endl;
    for(int i= 0 ; i<row ; i++)
    {
        delete [] grid[i];
    }
    delete [] grid;
    cout<<"But this is not best complexity would be O(3^N) that is at worst as possible due to common call  \n look next code to see efficient code \n";<<endl;
    return 0;
}
