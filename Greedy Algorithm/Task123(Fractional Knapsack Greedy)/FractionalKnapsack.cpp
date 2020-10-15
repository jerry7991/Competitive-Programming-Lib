#include <bits/stdc++.h>
using namespace std;
struct  Activity
{
	double value;
	double weight;
};
bool compare(Activity job1 , Activity job2)
{
	return (	(job1.value/job1.weight)>(job2.value/job2.weight)	);
}
double getMaxValue(Activity * job ,int  n ,int maxWeight)
{
	double maxValue=0.00;int i=0;
	//let's sort ther job according to (value/weight);i.e. weight is min and value become max
	sort(job , job+n , compare);
	for ( i = 0; i < n; ++i)
	{
		if(job[i].weight >maxWeight)
			{
				maxValue += ( (job[i].value)/(job[i].weight) )*maxWeight;
				return maxValue;
			}
			maxValue +=job[i].value;
			maxWeight	-=job[i].weight;
	}
	return maxValue;
}
int main()
{
	int testCase;
	cin>>testCase;
	while(testCase--)
	{
		int n , maxWeight;
		cin>>n>>maxWeight;
		Activity *job=new Activity[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>job[i].value >>job[i].weight;
		}
		cout<<setprecision(3)<<getMaxValue(job , n , maxWeight)<<endl;
	}
}