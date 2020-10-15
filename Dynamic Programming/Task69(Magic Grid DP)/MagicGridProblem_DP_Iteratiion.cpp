#include<iostream>
using namespace std;
int findMinHealth(int ** healthGrid    , int  row ,  int col)
{
    int **memoTable=new int*[row];
    //create a memo table
    for(int i=0 ;i<row ; i++)
        {
            memoTable[i]=new int[col]();
        }
    //base case
    memoTable[row-1][col-1]=1;
    //let's feel right most col using base case
    for(int i=row-2 ; i>=0 ; i--)
    {
        //column will be same  but row differ in each iteration
        memoTable[i][col-1] =   memoTable[i+1][col-1]-healthGrid[i][col-1];
    }
    //let's feel bottom most row
    for(int i=col-2 ; i>=0  ;   i--)
    {
        //row will be same but column changes
        memoTable[row-1][i] =   memoTable[row-1][i+1]-healthGrid[row-1][i];
    }
    //now we have right most column and bottom most row filled now let's fill whole memo table
    for(int i=row-2 ; i>=0 ; i--)
    {
        for(int j=col-2 ; j>=0 ; j--)
        {
            int moveDown=memoTable[i+1][j]-healthGrid[i][j];
            int moveRight=memoTable[i][j+1]-healthGrid[i][j];
            int ans=min(moveDown , moveRight);
            ans=(ans<1)?1:ans;
            memoTable[i][j]=ans;
        }
    }
    int finalAnswer=memoTable[0][0];
    //release memory
        for(int i=0 ; i<row ;i++)
        {
            delete [] healthGrid[i];
        }
        delete []healthGrid;
    return finalAnswer;
}
int main()
{
    int totalTest;
    cin>>totalTest;
    while(totalTest--)
    {
        int row , col;
        cin>>row>>col;
        int ** grid=new int*[row];
        for(int i=0 ;i<row ; i++)
        {
            grid[i]=new int[col];
            for(int j=0 ; j<col ; j++)
            {
                cin>>grid[i][j];
            }
        }
        cout<<findMinHealth(grid    ,   row ,   col )<<endl;
        //release memory
        for(int i=0 ; i<row ;i++)
        {
            delete [] grid[i];
        }
        delete []grid;
    }
    return 0;
}
