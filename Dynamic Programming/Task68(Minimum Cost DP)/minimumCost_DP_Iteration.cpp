#include<iostream>
using namespace std;
int findMinCost(int **grid ,int i_start ,int j_start ,int i_end ,int j_end)
{
    int row=i_end - i_start+1;
    int col=j_end - j_start+1;
    //let's make a memoTable of row*col size and store solved problem for which no duplicate call will take place
    int **memoTable=new int*[row];
    for(int i=0 ; i<row ; i++)
    {
        memoTable[i]=new int[col]();
    }
    //base case
    memoTable[row-1][col-1]=grid[row-1][col-1];
    //let's feel right most col using base case
    for(int i=row-2   ;   i>=i_start  ;   i--)    //in max case i_start would be 0
    {
        //row will change and col remains same
        memoTable[i][col-1]=    memoTable[i+1][col-1]+grid[i][col-1];
    }
    //let's bottom most row using base case
    for(int i=col-2 ;   i>=j_start ; i--)
    {
        //col change but row will remain same
        memoTable[row-1][i]=    memoTable[col-1][i+1]+grid[row-1][i];
    }
    //now we have base case = we have answer of right most col and bottom most row so we can solve it
    for(int i=row-2 ; i>=i_start    ;i--)
    {
        for(int j=col-2 ; j>=j_start    ;  j--)
        {
            memoTable[i][j]=    grid[i][j] +  min(  memoTable[i+1][j]   ,min( memoTable[i][j+1] ,memoTable[i+1][j+1]));
            //memoTable[i+1][j] =   =   is first option move right
            //memoTable[i+1][j+1]== is second option move diagonally
            //memoTable[i][j+1]===is third option move down
        }
    }
    int ans=memoTable[i_start][j_start];
    //release memory
    for(int i= 0 ; i<row ; i++)
    {
        delete [] memoTable [i];
    }
    delete []memoTable;
    return ans;
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
    cout<<findMinCost(grid , i_start , j_start , i_end , j_end )<<endl;
    //release memory
    for(int i= 0 ; i<row ; i++)
    {
        delete [] grid[i];
    }
    delete [] grid;
    cout<<"\nThis is the most efficient code using dynamic programming and implementation with iteration with time complexity O(N) where N=row*column \n"<<endl;
    return 0;
}


