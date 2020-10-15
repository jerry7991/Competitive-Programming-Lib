#include <iostream>
using namespace std;
int n=10e6+1;
void eulerOperation(int *phi)
{
	for (int i = 0; i < n; ++i)
	{
		phi[i]=i;//because in eulers function n will come for all
		//i.e. n*(1-(1/p1))*(1-(1/p2))*(1-(1/p3)).............(1-(1/pk)) i.e. n  is common
	}
	for (int i = 2; i < n; ++i)
	{
		if (phi[i]!=i)
		{
			continue;
		}
		for(int j=2*i ; j<n ; j+=i)
		{
			double ans=(double)(phi[j]*(phi[i]-1))/(double)(phi[i]);
			phi[j]=(int)ans;
		}
		phi[i]=i-1;
	}
}
int main()
{
	int *phi=new int[n];
	eulerOperation(phi);
	int n;
	cin>>n;
	cout<<"total "<<phi[n]<<" co-prime possible for "<<n<<endl;
	delete []phi;
}