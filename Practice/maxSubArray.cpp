#include <iostream>
#include <vector>
using namespace std;
vector<int> maxset(int *arr, int n) 
{
	vector<int> olderSet;
	int olderSum=0;
	int currSum=0;
	vector<int> currSet;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i]>=0){
			currSum+=arr[i];
			currSet.push_back(arr[i]);
		}
		else
		{
			if(olderSum<currSum)
			{
				olderSum=currSum;
				unsigned int k=0;
				olderSet.clear();
				while(k<currSet.size()) olderSet.push_back(currSet[k++]);
			}else if(olderSum==currSum)
			{
				if(currSet.size()>olderSet.size())
				{
					unsigned int k=0;
					olderSet.clear();
					while(k<currSet.size()) olderSet.push_back(currSet[k++]);
				}
			}
			currSum=0;
			currSet.clear();
		}
	}
	if(olderSum<currSum)
			{
				olderSum=currSum;
				unsigned int k=0;
				olderSet.clear();
				while(k<currSet.size()) olderSet.push_back(currSet[k++]);
			}else if(olderSum==currSum)
			{
				if(currSet.size()>olderSet.size())
				{
					unsigned int k=0;
					olderSet.clear();
					while(k<currSet.size()) olderSet.push_back(currSet[k++]);
				}
			}
	return olderSet;
}
int main()
{
	int n;
	cin>>n;
	int *arr=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	vector<int>output=maxset(arr , n);
	for (unsigned int i = 0; i < output.size(); ++i)
	{
		cout<<output[i]<<" ";
	}
}