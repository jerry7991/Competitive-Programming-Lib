#include<bits/stdc++.h>
using namespace std;
#define N 9
bool isSafeInRow(int grid[N][N ] , int row , int num)
{
    for(int i=0 ; i<N ; i++)
    {
        if(grid[row][i]==num)
        {
            return false;
        }
    }
    //other wise num will be safe in given row
    return true;
}
bool isSafeInColumn(int grid[N][N] , int col , int num)
{
    for(int i=0 ;i<N ;i++)
    {
        if(grid[i][col]==num)
        {
            return false;
        }
    }
    //other wise num will be safe in given column
    return true;
}
bool isSafeInSameGrid(int grid[N][N] , int row , int col , int num)
{
    //we have to find where (row,col) lies in which grid of 3*3
    //so let's find rowFactor and colFactor
    int rowFactor=row-(row%3);
    int colFactor=col-(col%3);
     for(int i=0 ;i<3 ;i++)
    {
       for(int j=0 ; j<3 ; j++)
       {
            if(grid[i+rowFactor][j+colFactor]==num)
        {
            return false;
        }
       }
    }
    //other wise num is safe in same grid
    return true;
}
bool isSafe(int  grid[N][N] , int  row , int col , int num)
{
    //check validation for num in row
    bool safeInRow=isSafeInRow(grid , row , num);
    //check validation for num in column
    bool safeInColumn=isSafeInColumn(grid,col,num);
    //check validation for num in same grid
    bool safeInSameGrid=isSafeInSameGrid(grid , row , col, num);
    if( safeInRow && safeInColumn && safeInSameGrid )
    {
        return true;
    }
    return false;
}
bool findEmptyLocation(int grid[N][N] , int &row , int &col)//store reference so that it will use to solve  Sudoku;
{
    for(int i=0 ; i<N ; i++)
    {
        for(int j=0 ; j<N ; j++)
        {
            if(grid[i][j]==0)
            {
                //save location in row col and return true
                row=i;
                col=j;
                return true;
            }
        }
    }
    //other wise no space left
    return false;
}
bool solveSudoku(int grid[N][N])
{
    int row ,  col;
    //first we will have to find empty space in each row
    if(  ! findEmptyLocation(grid , row , col) )
    {
        //if no empty location are.........  sudoku solved
        return true;
    }

    /*now so for we have found the empty location so let's check possibility of number from
        1-9 and fill them
    */
    for(int i=1 ; i<=9 ; i++)
    {
        if(isSafe(grid , row , col , i))
        {
            //if i is safe then put i into grid; i.e. fill sudoku
            grid[row][col]=i;
            //start exploring  next  empty location if all location filled then solveSudoku return true
            if(solveSudoku(grid))
            {
                return true;//every space has filled with right value
            }
            //other wise the number which we inserted was wrong because on that number we couldn't achieve final answer
            //so let's back track
            grid[row][col]=0;//and check further new i which will be done by for loop
        }
    }
    //if no solution found return false;
    return false;
}
int main()
{
    int grid[9][9];
    //input is in string
    for(int i=0 ; i<N ; i++)
    {
        string row;
        cin>>row;
        for(int j=0 ; j<row.length() ; j++)
        {
            grid[i][j]=row[j]-'0';
        }
    }
    if(solveSudoku(grid))
    {
        for(int i=0 ; i<9 ; i++)
        {
            for(int j=0 ; j<9 ; j++)
            {
                cout <<grid[i][j]<<"    ";
            }
            cout<<endl;
        }
    }
    return 0;
}
//if number will be in int
/*
int n, board[9][9];
    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<9;j++) {
            for(int k=0;k<9;k++) {
                board[j][k] = 0;
                cin >> board[j][k];
            }
        }
*/
