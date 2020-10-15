#include<iostream>
using namespace std;
int findMaxSquareWithAllZeros(int** matrix, int row, int col)
{
    int **outputMatrix=new int*[row];
    for(int i=0 ; i<row ; i++)
    {
        outputMatrix[i]=new int[col]();
    }
    //let's feel base case
    //first base case
    if(matrix[0][0]==0)
    {
        outputMatrix[0][0]=1;
    }
    //second base case :-let's feel top most row
        //row remains same and column changes for traveling in any row
    for(int i=1;i<col;i++)
    {
        outputMatrix[0][i]= (  matrix[0][i]==0 )?   1 : 0;  //means at least one square can be made using one 0
    }
    //col remains same and row changes for traveling in any column
    for(int i=1 ; i<row ; i++)
    {
        outputMatrix[i][0]  =   (  matrix[i][0]==0 )?   1:0;    //means at least one square can be made using one 0
    }
    int maxSquare=0;
    //check for each row and col
    for(int i=1 ; i<row ;i++)
    {
        for(int j=1 ; j<col ; j++)
        {
            if(matrix[i][j]!=0)
            {
                outputMatrix[i][j]=0;
                continue;
            }
            outputMatrix[i][j]=min(outputMatrix[i-1][j-1] , min( outputMatrix[i][j-1] , outputMatrix[i-1][j]))  +1;
            //whenever we modify the outputMatrix for any i and j we check weather this modified i and j give a better solution then previous
            maxSquare=max(maxSquare ,   outputMatrix[i][j]);
        }
    }
   /* int maxSquare=0;
    for(int i=0 ; i<row ; i++)
    {
        for(int j=0;j<col ;j++)
        {
            maxSquare=  (maxSquare  <   outputMatrix[i][j])?outputMatrix[i][j]  : maxSquare;
        }
    }
    */
    //release memory
    for(int i=0 ; i<row ;i++)
    {
        delete [] outputMatrix[i];
    }
    delete [] outputMatrix;
    return maxSquare;
}
int main()
{
    int row, col;
    cin>>row>>col;
    int **matrix=new int*[row];
    for(int i=0 ; i<row ; i++)
    {
        matrix[i]=new int[col];
        for(int j=0 ; j<col ; j++)
        {
            cin>>matrix[i][j];
        }
    }
    cout<<findMaxSquareWithAllZeros(matrix,  row,  col)<<endl;
    //release memory
    for(int i=0 ; i<row ;i++)
    {
        delete [] matrix[i];
    }
    delete [] matrix;
    return 0;
}
