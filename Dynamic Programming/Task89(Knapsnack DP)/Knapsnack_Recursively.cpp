#include <iostream>
using namespace std;
int knapsnack(int *weight ,int *value , int n ,int kWeight)
{
	//base case:-
	if(n<0)
		return 0;
	if(kWeight==0)
		return 0;
	//now we have to check weather for n-th element,knapsnack has capacity or not 
	//if has capacity
	if(weight[n]<=kWeight)
	{
	//now we have two option for each n-th item 
	//option 1:-	Either we can put n-th item into knapsnack and decrease available size of knapsnacl i.e. kWeight
		 int option1=	value[n]+knapsnack(weight , value , n-1 , kWeight-weight[n]);
	//option 2:- or we can just ingore nth item and save our knapsnack capacity for future use
		 int option2=	knapsnack(weight , value , n-1 , kWeight);	
		 return (	(option1>option2)?option1:option2	);
	}else{
		//if knapsnack has not enough space for n-th item then just we have to ignore this n-th element and move further
		return knapsnack(weight , value , n-1 , kWeight);
	}
}
int main()
{
	int n;
	cin>>n;
	int *weight=new int[n];
	int *value=new int[n];
	for (int i = 0; i <n; ++i)
	{
		cin>>weight[i];
	}
	for (int i = 0; i <n; ++i)
	{
		cin>>value[i];
	}
	int kWeight;
	cin>>kWeight;
	cout<<knapsnack(weight , value , n-1 , kWeight)<<endl;
	cout<<"\n But the time complexity would be O(2^N) due to hug duplicate call.. Only N call will be unique \n";
	return 0;
}