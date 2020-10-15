#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	bool *seive=new bool[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		seive[i]=true;
	}
	for(int i=2;i*i*i<=n ; i++)
	{
		if(seive[i])
		{
		 int x=i*i*i;
		 for(int j=x;j<=n;j+=x) seive[j]=false;
		}
	}
	unordered_map<int ,int> cubeFree;
	int count=0;
	for (int i = 0; i <=n; ++i)
	{
		if(seive[i])
		{
			cubeFree[i]=count++;
			//cout<<i<<" "<<cubeFree[i]<<endl;
		}
	}
	if(seive[n])
		cout<<cubeFree[n];
	else
		cout<<"Not Cube Free";
}