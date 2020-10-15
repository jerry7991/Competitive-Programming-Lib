#include<iostream>
using namespace std;
int findMinCost(int ** grid ,int i_start , int j_start , int i_end , int  j_end, int** output)
{
    //base case
    if(   i_start == i_end && j_start==j_end  )
    {
        return grid[i_end][j_end];
    }
    if(  i_start >i_end ||  j_start >j_end  )       //crossed the boundry
    {
        return INT_MAX;
    }
    //else check for current i_start and j_start weather i have solved or not if solved then return ;avoid duplicate calls
    if(   output[i_start][j_start]!=0  )
    {
        return output[i_start][j_start];
    }
    //else we have to solve for current i_start and j_start because we haven't solved
    //now we have three choice to solved and will have to choose one choice which give min cost ok!!!!!!!!
    int moveBottom=findMinCost(  grid , i_start+1  ,    j_start ,   i_end   ,   j_end   ,   output  );\
    //second option move right
    int moveRight=findMinCost(  grid , i_start  ,    j_start+1 ,   i_end   ,   j_end   ,   output  );
    //third option move diagonally
    int moveDiagonal=findMinCost(  grid , i_start+1  ,    j_start+1 ,   i_end   ,   j_end   ,   output  );

    int ans=    grid[i_start][j_start]  +   min(   moveBottom , min( moveRight , moveDiagonal ) );
    //once i solved then store for further use
    output[i_start][j_start]=ans;
    return ans;
    //or return output[i_start][j_start] think why
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
    //let's make a memoTable of row*col size and store solved problem for which no duplicate call will take place
    int **memoTable=new int*[row];
    for(int i=0 ; i<row ; i++)
    {
        memoTable[i]=new int[col]();
    }
    cout<<findMinCost(grid , i_start , j_start , i_end , j_end, memoTable)<<endl;

    //release memory
    for(int i= 0 ; i<row ; i++)
    {
        delete [] grid[i];
        delete [] memoTable [i];
    }
    delete [] grid;
    delete []memoTable;
    cout<<"\nUsing Dynamic programming and implementation with recursion , time complexity O(2*N) where n=row*column ; we can do much better it in iterative manner in O(N)\n"<<endl;
    return 0;
}

