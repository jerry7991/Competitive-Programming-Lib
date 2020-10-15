#include<iostream>
using namespace std;
int findMinHealth(int ** grid    ,  int row ,  int col ,  int row_start   , int col_start , int **output)
{
    //base case
    //cout<<row_start<<"\t"<<col_start<<endl;
    if( row_start==row-1 && col_start==col-1)
    {
        return 1;
    }
    if(row_start>row || col_start >col)
    {
        return INT_MAX;
    }
    if(output[row_start , col_start]!=0)
    {
        return output[row_start][col_start];
    }
    int moveRight=findMinHealth(    grid , row , col , row_start , col_start+1,output)-grid[row_start][col_start+1];
    int moveDown=findMinHealth(    grid , row ,col , row_start+1 , col_start ,output)-grid[row_start+1][col_start];
    int ans=min(moveRight , moveDown);
    ans=(ans<1)?1:ans;
    output[row_start][col_start]=ans;
    return output[row_start][col_start];
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
        int ** memoTable=new int*[row];
        for(int i=0 ;i<row ; i++)
        {
            memoTable[i]=new int[col]();
        }
        cout<<findMinHealth(grid    ,   row ,   col ,   0   ,   0,memoTable)<<endl;
         for(int i=0 ;i<row ; i++)
        {
            for(int j=0 ; j<col ; j++)
            {
                cout<<grid[i][j]<<"\t";
            }
            cout<<endl;
        }
        //release memory
        for(int i=0 ; i<row ;i++)
        {
            delete [] grid[i];
        }
        delete []grid;
    }
    return 0;
}
