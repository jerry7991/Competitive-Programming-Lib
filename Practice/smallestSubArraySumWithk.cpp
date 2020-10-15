#include <iostream>
#include <vector>
using namespace std;
vector<int> smallestSubarray(unsigned int sum, vector<int> input) 
{
	vector<int>subArr;
	unsigned int lRange=0,rRange=0,currSum=0;//lRange=left range and rRange rightRange
	while(rRange<input.size())
	{
		if(currSum<=sum)
			currSum+=input[rRange++];
		else{
			while(currSum>sum)
			{
				currSum-=input[lRange++];
			}
			lRange--;
			if((rRange-lRange)<subArr.size() || !subArr.size())
			{
				subArr.clear();
				for(unsigned int i=lRange ; i<rRange ; i++)	subArr.push_back(input[i]);
			}
		lRange++;
		}
		//cout<<currSum<<endl;
	}
	//cout<<endl;
	return subArr;
}
int main()
{
	int n;
	cin>>n;
	vector<int>input;
	while(n--)
	{
		int x;
		cin>>x;
		input.push_back(x);
	}
	int sum;
	cin>>sum;
	vector<int>output=smallestSubarray(sum , input);
	for (int i = 0; i < output.size(); ++i)
	{
		cout<<output[i]<<" ";
	}
	return 0;
}