#include <iostream>
using namespace std;
int gcd(int a , int b)
{
	if (b==0)
	{
		return a;
	}
	if (b>a)
	{
		return gcd(b,a);//swap
	}
	return gcd(b  , a%b);
}
int main()
{
	int t;
    cin>>t;
    while(t--)
    {
        int a;
        char b[251];
        cin>>a;
        cin>>b;
        if(a==0)//if a==0 then greatest common divisor is b
        {
            cout<<b<<endl;
            continue;
        }
        int bModA=0;
        for (int i = 0; b[i]!='\0'; ++i)
        {
            bModA=( (bModA*10)%a + (b[i]-'0')%a )%a;
        }
        cout<<gcd(a,bModA)<<endl;
        //cout<<a<<" "<<bModA;
    }
}