#include <iostream>
#include<algorithm>
using namespace std;
struct Worker
{
	long long int cTime, cost,speed;
};
bool compare(struct Worker w1 ,struct Worker w2)
{
if(w1.cTime==w2.cTime)
{
	if(w1.speed==w2.speed)
	{
		return (w1.cost < w2.cost);
	}else
	{
		return (w1.speed > w2.speed);
	}
}else{
	return (w1.cTime < w2.cTime);	
}
}
int main()
{
	long long int n,k;
	cin>>n>>k;
	Worker * worker=new Worker[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>worker[i].cTime;
		cin>>worker[i].cost;
		cin>>worker[i].speed;
	}
	sort(worker , worker+n ,compare);
    long long int currArea = 0, bestSpeed = 0, cost = 0;
    for(int i = 0; i < n; i++){
        currArea += bestSpeed;
        if(currArea >= k){
            break;
        }
        if(worker[i].speed > bestSpeed){
            bestSpeed = worker[i].speed;
            cost = cost + worker[i].cost;
        }
	}
    cout << cost << endl;
}