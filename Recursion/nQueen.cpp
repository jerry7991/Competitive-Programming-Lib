#include <iostream>
using namespace std;
int arr[11][11];
bool isPossible(int queen , int rows , int col)
{
	//same col
	for (int i = rows-1; i >=0; --i)
	{
		if (arr[i][col])
		{
			return false;
		}
	}
	//left diagonal
	for(int i=rows-1 , j=col-1; i>=0 && j>=0 ;i--,j--)
	{
		if (arr[i][j])
		{
			return false;
		}
	}
	//right diagonal
	for(int i=rows-1,j=col+1;i>=0 && j<queen;i-- ,j++)
	{
		if (arr[i][j])
		{
			return false;
		}
	}
	return true;
}
void print(int queen , int rows)
{
	if (rows==queen)
	{
		for (int i = 0; i < queen; ++i)
		{
			for(int j=0  ; j<queen ; j++)
				cout<<arr[i][j]<<" ";
		}
		cout<<endl;
		return;
	}
	for (int i = 0; i < queen; ++i)
	{
		if (isPossible(queen,rows , i))
		{
			arr[rows][i]=1;
			print(queen , rows+1);
			arr[rows][i]=0;
		}
	}
	return;
}
void placeNQueens(int n)
{
	for (int i = 0; i < 11; ++i)
	 {
	 	for(int j=0 ; j<11;j++)
	 		arr[i][j]=0;
	 } 
	 print(n , 0);
}

int main()
{
	int n;
	cin>>n;
	placeNQueens(n);
}