#include <iostream>
#include <algorithm>
#include <vector>
#define pb(n) push_back(n)
using namespace std;
int *LPD;	//Lowese  Prime Divisor
bool *marked;
void maintainLCD(int n)
{
	for (int i = 1; i <=n; ++i)
	{
		LPD[i]=i;
	}
	for (int i = 2; i*i <=n; ++i)
	{
			if (LPD[i]==i)
			{
				for(int j=i*i ; j<=n ; j+=i)
				{
					if(LPD[j]==j) LPD[j]=LPD[i];
				}
			}
	}
}
void printSequence(int  n)
{
	vector<int>output;
	while(n>0)
	{
		if (marked[n])
		{
			n--;
			continue;
		}
		int x=n;
        output.pb(x);
        marked[x]=true;
		while(x>1)
		{
			int primeD=LPD[x];
			for(int i=n ; i>0 ; i-=primeD)
			{
				if (i>0 && !marked[i])//i>0 for valid memory accessing
				{
					output.pb(i);
					marked[i]=true;
				}
			}
			while(x%primeD==0)	x/=primeD;
		}
	//sort the output
	if(output.size()) sort(output.begin(), output.end() , greater<int>());
	for (unsigned int i = 0; i < output.size(); ++i)
	{
		cout<<output[i]<<" ";
	}
	output.clear();
	n--;
	}
}
int main()
{
	int n;
	cin>>n;
	LPD=new int[n];
	marked=new bool[n];
	maintainLCD(n);
	for (int i = 1; i <=n; ++i)
	{
		marked[i]=false;
	}
	printSequence(n);
}