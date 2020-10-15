#include <iostream>
#define fon(i, k,n) for(int i=k;i<n;i++)
#define MOD 1000000007
using namespace std;
int N=7.5e5+1;
//int MOD=10e9+7;
inline void init(int *arr , int s,int e)
{
	fon(i,s,e) arr[i]=0;
}
int main()
{
	int *seive=new int[N];
	init(seive,0 , N);
	int test;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		int Min=INT_MAX,Max=INT_MIN;
		while(n--)
		{
			int x;
			cin>>x;
			seive[x]=1;
			Min=min(x,Min),Max=max(x,Max);
		}
		fon(i , Min , Max+1)
		{
			if (seive[i]>0)
			{
				for(int j=2*i ;j<=Max ; j+=i)
				{
					if(seive[j]>0)
					{
						long ans=seive[i]+seive[j];
						seive[j]=(int)(ans%MOD);
					}
				}
			}
		}
		int sum=0;
		fon(i , Min , Max+1) sum+=seive[i];
		cout<<sum<<endl;
		init(seive , Min , Max+1);
	}
}