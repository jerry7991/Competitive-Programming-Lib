#include <iostream>
using namespace std;
int Max=1e6+1;
int main()
{
	int *seive=new int[Max];
	for (int i = 0; i < Max; ++i)
	{
		seive[i]=0;
	}
	seive[1]=0;
	for (int i = 2; i < Max; ++i)
	{
		if (seive[i]==0)
		{
			//it is prime update
			seive[i]=1;
			//increase all multiple of this prime by one
			for(int j=i+i ; j<Max ; j+=i)
			{
				seive[j]+=1;
			}
		}
	}
	int **nFactor=new int*[11];
	for (int i = 0; i < 11; ++i)
	{
		nFactor[i]=new int[Max];
		for (int j = 0; j < Max; ++j)
		{
			nFactor[i][j]=0;
		}
	}
	//now each i will tell the count of i-th factorful till j-th number
    for(int i=1 ; i<11 ; i++)
    {
        nFactor[i][0]=1;
    }
    for(int i=0 ; i<Max ; i++)
    {
        nFactor[0][i]=1;
    }
	for (int i = 0; i < 11; ++i)
	{
		for(int j=0; j <Max ;j++)
		{
			if (seive[j]==i)
			{
				nFactor[i][j]=1+nFactor[i][j-1];
			}else{
				nFactor[i][j]=nFactor[i][j-1];
			}
		}
	}
 //  cout<<nFactor[0][0]<<endl;
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,n;
		cin>>a>>b>>n;
		cout<<nFactor[n][b]-nFactor[n][a-1]<<endl;
	}
}