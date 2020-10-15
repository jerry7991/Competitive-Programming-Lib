#include <iostream>
using namespace std;
long answer(long time , int coperM)
{
	long n=(long)(time/coperM);
	long x=(long)(time%coperM);
	long fact=1;
	while(x)
	{
		long ans=(long)fact*x;
		fact=(long)(ans%coperM);
		x--;
	}
	if ((n&1))
	{
		long ans=fact*(coperM-1);
        fact=(long)(ans%coperM);
		return fact%coperM;
	}else{
		return fact;
	}
}
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		long time;
		cin>>time;	
		int coperM;
		cin>>coperM;
		cout<<answer(time,coperM)<<endl;
	}
}