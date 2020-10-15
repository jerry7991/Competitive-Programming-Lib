#include <iostream>
#include <algorithm>
using namespace std;
struct Activity
{
	int startTime;
	int finishTime;
};
bool compare(Activity job1 , Activity job2)
{
	return (job1.finishTime <job2.finishTime);
}
int main()
{
	int n;
	cin>>n;
	Activity * job=new Activity[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>job[i].startTime;
		cin>>(*(job+i)).finishTime;
	}
	//sort the job according to their finish time
	sort(job , job+n , compare);
	int nJob=1;
	int previousJob=0;
	for (int i = 1; i <= n; ++i)
	{
		cout<<job[i-1].startTime<<"  "<<job[i-1].finishTime<<endl;
		if (job[previousJob].finishTime < job[i].startTime)
		{
			previousJob=i;
			nJob +=1;
		}
	}
	cout<<nJob;
}