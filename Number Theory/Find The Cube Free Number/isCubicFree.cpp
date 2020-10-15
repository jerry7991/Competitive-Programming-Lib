#include <iostream>
#define Max 1000001
using namespace std;
int main()
{
	bool *seive=new bool[Max];
	for (int i = 0; i <Max; ++i)
	{
		seive[i]=false;
	}
	//fill prime
	for(int i=2; i*i*i<Max ; i++)
	{
		if (!seive[i])
		{
			for(int j=i*i*i ; j<Max ; j+=(i*i*i)) seive[j]=true;
		}
	}
	int count=0;
	int *answer=new int[Max];
	for (int i = 1; i < Max; ++i)
	{
		if (!seive[i])
		{
			count++;
		}
		answer[i]=count;
	}
	// for (int i = 1; i < 100; ++i)
	// {
	// 	cout<<i<<" "<<answer[i]<<endl;
	// }
	int t;
	cin>>t;
	for (int i = 1; i <=t; ++i)
	{
		int n;
		cin>>n;
		if (seive[n])
		{
			cout<<"Case "<<i<<": "<<"Not Cube Free"<<endl;
		}else{
			cout<<"Case "<<i<<": "<<answer[n]<<endl;
		}
	}
}
/*
	//memset(vis, false, sizeof(vis));
    for(int i=0 ; i<mini ; i++) vis[i]=false;
	
  	for(int i=2 ; i*i*i<mini ; i++){
        if(!vis[i]){
			for(int j=i*i*i ; j<mini ; j+=(i*i*i )) vis[j]=true;
        }
    }
*/