#include <iostream>
#define MOD 1000000007
using namespace std;
long countArray(int n, int k, int x) 
{
	long oneCount=1;
	long nonOneCount=0;
	for (int i = 1; i < n; i++)
	{
		long previousOneCount=oneCount;
		oneCount=(nonOneCount*(k-1))%MOD;
		nonOneCount=	( previousOneCount + ((nonOneCount)*(k-2))%MOD	)%MOD;
	}
	if(x==1)
		return oneCount;
	else
		return nonOneCount;
}
int main()
{
	int n,k,x;
	cin>>n>>k>>x;
	cout<<countArray(n , k ,x);
	return 0;
}