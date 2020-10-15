#include<iostream>
using namespace std;
//complexity would be O(N) where N=min(rows , cols)
int fillMemoSum(int **matrix , int rows ,int cols , int si , int sj , int **memoSum)
{
    //cout<<si<<"\t"<<sj<<endl;
    if(si==rows && sj==cols)
    {
        return matrix[rows][cols];
    }
    if(si >rows || sj>rows)
    {
        return 0;
    }
    if(memoSum[si][sj]!=0)
    {
        return memoSum[si][sj];
    }
    int answer=fillMemoSum(matrix , rows , cols , si+1 , sj+1,memoSum);
    int rectangleSum=matrix[si][sj]+answer;
    //for column
    for(int i=si+1 ; i<=rows ; i++)
    {
        //column remain same rows will change
        rectangleSum    +=matrix[i][sj];
    }
    //for rows
    for(int i=sj+1 ;i<=cols ; i++ )
    {
        //rows remains same and column will change
        rectangleSum    += matrix[si][i];
    }
    memoSum[si][sj]=rectangleSum;
    return memoSum[si][sj];
}
void fillMemo(int ** matrix , int rows , int cols  ,int ** memoSum)
{
    //let's feel first base case
    memoSum[rows-1][cols-1]=matrix[rows-1][cols-1];
    //fill bottum most rows
    for(int i=cols-2 ; i>=0 ; i--)
    {
        memoSum[rows-1][i]=matrix[rows-1][i]+memoSum[rows-1][i+1];
    }
    //fill right most column
    for(int i=rows-2 ; i>=0 ;i--)
    {
        memoSum[i][cols-1]=matrix[i][cols-1]+memoSum[i+1][cols-1];
    }
    for(int i=0 ; i<rows ; i++)
    {
        for(int j=0 ; j<cols ; j++)
        {
            if(memoSum[i][j]!=0)
            {
                continue;
            }
            int ans=fillMemoSum(matrix , rows-1 , cols-1 ,i , j,memoSum);
        }
    }
}
int maxSubRectangle(int ** matrix , int rows , int cols)
{
   int **memoSum=new int*[rows];
    for(int i=0 ; i<rows ; i++)
    {
        memoSum[i]=new int[cols]();
    }
    fillMemo(  matrix ,  rows ,  cols  , memoSum);
    //now our memo size has filled
    //memoSum[i][j] represent the rectangle sum from (i->rows , j->cols)
    //now let's find the maximum maximum sum rectangle
    int maxSum=INT_MIN;
    int r1=0,c1=0,r2=0,c2=0;
    for(int i=0 ; i<rows-1 ; i++)
    {
        for(int j=0 ; j<cols-1 ;j++)
        {
            for(int k=i+1 ; k <rows ; k++)
            {
                for(int l=j+1 ; l<cols ;l++ )
                {
                    int x=k+1,y=l+1;
                    int removeArea1=0;
                    int removeArea2=0;
                    int addArea1=0;
                    if(x!=rows)
                    {
                        removeArea2=memoSum[x][j];
                    }if(y!=cols)
                    {
                        removeArea1=memoSum[i][y];
                    }
                    if(x!=rows && y!=cols)
                    {
                        addArea1=memoSum[x][y];
                    }
                    int currentSum=memoSum[i][j]-removeArea1-removeArea2+addArea1;
                    //maxSum  =   (maxSum<currentSum) ?   currentSum : maxSum;
                    if(maxSum < currentSum)
                    {
                        maxSum=currentSum;
                        r1=i;c1=j;r2=k;c2=l;
                    }
                }
            }
        }
    }
    /*for(int i=0 ; i<rows ; i++)
    {
        for(int j=0 ; j<cols ; j++)
        {
            cout<<memoSum[i][j]<<"  ";
        }cout<<endl<<endl;
    }*/
    //memory release
     for(int i=0 ; i<rows ; i++)
    {
        delete  []  memoSum[i];
    }
    delete [] memoSum;
    //cout<<"( "<<r1<<" ,"<<c1<<" ) \t ( "<<r2<<" , "<<c2<<" )"<<endl;
    if(maxSum<0)
        return -1;
    return maxSum;
}
int main()
{
    int rows,cols;
    cin>>rows>>cols;
    int **matrix=new int*[rows];
    for(int i=0 ; i<rows ; i++)
    {
        matrix[i]=new int[cols];
        for(int j=0 ; j<cols ; j++)
        {
            cin>>matrix[i][j];
        }
    }
    cout<<maxSubRectangle(matrix , rows , cols)<<endl;
    cout<<endl<<"At all algorithm took O(N^4) where n=rows*cols ; we can optimize it little bit Look next algorithm"<<endl;
    for(int i=0 ; i<rows ; i++)
    {
        delete [] matrix[i];
    }
    delete []matrix;
    return 0;
}
