#include<bits/stdc++.h>
using namespace std;
int board[11][11];//because max size of queen <=10 given
bool isPossible(int queen , int rows, int column)
{
    //check weather new queens are in same column of older once or not
    for(int i=rows-1 ; i>=0 ; i--)
    {
        if(board[i][column]==1){
            return false;
            }
    }
    //check weather queens are in left diagonal of older once or not
    for(int i=rows-1 , j=column-1 ; i>=0 && j>=0 ; i-- , j--)
    {
        if(board[i][j]==1){
            return false;
            }
    }
    //check weather queens are in right diagonal of older once or not
    for(int i=rows-1 , j=column+1 ; i>=0 && j<queen ; i-- , j++)
    {
        if(board[i][j]==1){
            return false;
            }
    }
    //other wise queen was a safe place
    return true;
}
void nQueenHelper(int queen , int rows)
{
    if(rows == queen)//that's means all the queen have filled successfully
    {
        //print the position of queen that's means print the board all 1-represent the position of queen on board
        for(int i=0 ; i<queen ; i++)
        {
            for(int j=0;j<queen;j++)
            {
                cout<<board[i][j]<<"    ";
            }
           cout<<"\n"<<endl;
        }
        cout<<"\n other ways is \n"<<endl;
        cout<<endl;
        return;
    }
    //if rows < queen that's means we will have to allocate all the queen to their possible position
    //place all the possible position and move to smaller problem
    for(int j=0; j<queen ; j++)
    {
        if(isPossible(queen , rows , j))
        {
            //make current position as visited
            board[rows][j]=1;
            nQueenHelper(queen , rows+1);
            //if solution found then it has been submitted..
            //now let's backtrack and make current position as unvisited
            board[rows][j]=0;
        }
    }
    return;
}
void placeNQueens(int n)
{
    memset(board , 0 , 11*11*sizeof(int));
    nQueenHelper(n,0);//in starting it will be at 0-th row
}
int main(){
  int n;
  cin >> n ;
  placeNQueens(n);
}
