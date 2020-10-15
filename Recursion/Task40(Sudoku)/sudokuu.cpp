#define k 9
bool bsafe(int board[][k],int row,int col,int num)
{
    int rf=row-row%3;
    int cf=col-col%3;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i+rf][j+cf]==num)
                return 0;
        }
    }
    return 1;
}
bool csafe(int board[][k],int col,int num)
{
    for(int i=0;i<k;i++)
    {
        if(board[i][col]==num)
        {
            return 0;
        }
    }
    return 1;
}
bool rsafe(int board[][k],int row,int num)
{
    for(int j=0;j<k;j++)
    {
        if(board[row][j]==num)
            return 0;
    }
    return 1;
}
bool safe(int board[][k],int row,int col,int num)
{
    if(rsafe(board,row,num)&&csafe(board,col,num)&&bsafe(board,row,col,num))
    {
        return 1;
    }
    return 0;
    
}
bool emptyplace(int board[][k],int &row,int &col)
{
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            if(board[i][j]==0)
            {
                row=i;
                col=j;
                return true;
            }
        }
    }
    return false;
}

bool sudokuSolver(int board[][9]){

    int row,col;
if(!emptyplace(board,row,col))
    return true;
for(int i=1;i<=k;i++)
{
    if(safe(board,row,col,i))
    {
        board[row][col]=i;
        if(sudokuSolver(board))
        {
            return true;
        }
        board[row][col]=0;
    }
}
return 0;
}