#include <iostream>
#include <vector>
#define KpF KprimeFactor
#define CpF CurrentPrimeFactor
using namespace std;
std::vector<pair<int,int>> KpF;
std::vector<pair<int , int>> CpF;
void intit(int n)
{
	int N=n;
	for (int i = 2; i*i <= N; ++i)
	{
		int count=0;
		while(n%i==0)
		{
			count++;
			n/=i;
		}
		if(count)
		{
			KpF.push_back(make_pair(i ,  count));
			CpF.push_back(make_pair(i , 0));
		}
	}
	if (n!=1)
	{
		//n was the prime
		KpF.push_back(make_pair(n , 1));
		CpF.push_back(make_pair(n , 0));
	}
}
void setPrimeFactor(int n)
{
	for (unsigned int i = 0; i < KpF.size(); ++i)
	{
		int x=KpF[i].first;
		int count=0;
		while(n%x==0)
		{
			n/=x;
			count++;
		}
		CpF[x].second+=count;
	}
}
void resetPrimeFactor(int n)
{
	for (unsigned int i = 0; i < KpF.size(); ++i)
	{
		int x=KpF[i].first;
		int count=0;
		while(n%x==0)
		{
			n/=x;
			count++;
		}
		CpF[x].second-=count;
	}
}
bool isValidSet()
{
	std::vector<pair<int,int>> ::iterator itr=KpF.begin();
	while(itr!=KpF.end())
	{
		if ((itr->second)>(CpF[itr->first].second))
		{
			return false;
		}
		itr++;
	}
	return true;
}
void print()
{
	cout<<"\n"<<"NOW"<<endl;
	std::vector<pair<int,int>> ::iterator itr=KpF.begin();
	while(itr!=KpF.end())
	{
		cout<<itr->first<<" "<<itr->second<<endl;
		cout<<CpF[itr->first].second<<endl;
		itr++;
	}
}
int getAns(int *arr ,int n)
{
	int count=0,i=0,j=0;
	while(i<n)
	{
		while(j<n && !isValidSet())
		{
			setPrimeFactor(arr[j]);
			j++;
		}
		print();
		if(isValidSet())
			count+=(n-j+1);
		resetPrimeFactor(arr[i]);
		print();
		i++;
	}
	return count;
}
int main()
{
	int n,k;
	cin>>n>>k;
	intit(k);
	int *arr=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	cout<<getAns(arr , n);
}