#include <iostream>
using namespace std;
void multiply(int a[2][2] , int m[2][2])
{
	int fValue=a[0][0]*m[0][0]+a[0][1]*m[1][0];
	int sValue=a[0][0]*m[0][1]+a[0][1]*m[1][1];
	int tValue=a[1][0]*m[0][0]+a[1][1]*m[1][0];
	int lValue=a[1][0]*m[0][1]+a[1][1]*m[1][1];
	a[0][0]=fValue;
	a[0][1]=sValue;
	a[1][0]=tValue;
	a[1][1]=lValue;
}
void power(int m[2][2] ,int n)
{
	//base case
	if (n==0 || n==1)
	{
		return;
	}
	power(m , n/2);
	//multiplying  A^N/2 with A^N/2
	multiply(m ,m);
	if (n%2!=0)
	{
		int a[2][2]={{1,1},{1,0}};
		multiply(m,a);
	}
}
int fib(int n)
{
	if(n==0)	return 0;
	int m[2][2]={{1,1},{1,0}};//our m matrix with the help of recurance relation
	power(m , n-1);
	return m[0][0];
}
int main()
{
	int n;
	cin>>n;
	cout<<fib(n);
}