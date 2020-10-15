#include <iostream>
#include <string>
using namespace std;
void print(int n , int start , int diff , string str)
{
	if (start==n)
	{
		cout<<str<<endl;
		return ;
	}
	if (diff==0)
	{
		print(n , start+1 , diff+1 , str+"(");
	}else if(diff==(n-start))
	{
		while(diff!=0)
		{
			str+=")";
			diff--;
		}
		print(n , n , 0 ,str);
	}else{
		print( n , start+1 , diff+1 ,str+"(");
		print( n , start+1 , diff-1 ,str+")");
	}
}
void printWellFormedParanthesis(int n)
{
	print(2*n , 0 , 0 , "");
}
int main()
{
	int n;
	cin>>n;
	printWellFormedParanthesis(n);
}