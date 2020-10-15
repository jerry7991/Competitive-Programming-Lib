#include <iostream>
#include <cstring>
#define fon(i, n) for(int i=0 ; i<n ; i++)
using namespace std;
void zFunction(string str, int *Z)
{
	int n=str.length();
	for(int i=1;i< n;i++)
	{
		int pivot=i;
		while(pivot<n && str[pivot]==str[pivot-i]) pivot++;
		Z[i]=pivot-i;
	}
}
void check(string str ,string pattern)
{
	int m=str.length();
	int n=pattern.length();
	string combined=pattern+"$"+str;
	int *Z=new int[n+m+1]();
	zFunction( combined,Z);
	fon(i , combined.length())
	{
		if(Z[i]==n)
		{
			cout<<i-n-1<<endl;
		}
	}
}
int main()
{
	string str , pattern;
	cin>>str>>pattern;
	check(str , pattern);
}