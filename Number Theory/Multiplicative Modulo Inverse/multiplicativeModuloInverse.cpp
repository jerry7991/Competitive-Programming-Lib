#include <iostream>
using namespace std;
class Triplet
{
public:
	int x,y,gcd;
};
Triplet extendedEuclid(int a,int b)
{
	if (b==0)
	{
		Triplet ans;
		ans.x=1;
		ans.y=0;
		ans.gcd=a;
		return ans;
	}
	
	Triplet smallAns=extendedEuclid(b,a%b);
	Triplet ans;
	ans.gcd=smallAns.gcd;
	ans.x=smallAns.y;
	ans.y=smallAns.x-(a/b)*smallAns.y;
	return ans;
}
int mmInverse(int a,int b)
{
	Triplet ans=extendedEuclid(a,b);
	return ans.x;
}
int main()
{
	int a,b;
	cin>>a>>b;
	cout<<" Multiplicative Inverse is "<<mmInverse(a,b);
	return 0;
}