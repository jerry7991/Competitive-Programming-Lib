#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
class Event
{
public:
	int left;
	int right;
	int index;
	ll value;
};
bool compare(Event e1 , Event e2)
{
	if (e1.value==e2.value)
	{
		return e1.left>e2.left;
	}
	return e1.value>e2.value;
}
void updateBIT(int * BIT,int value ,int nMax)
{
	for(;value<=nMax;value+=(value&(-value)))
	{
		BIT[value]++;
	}
}
int getQuery(int value , int *BIT)
{
	int count=0;
	for(;value>0;value -=(value&(-value)))
	{
		count +=BIT[value];
	}
	return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	int *arr=new int[n+1];
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	int nQuery;
	cin>>nQuery;
	Event *query=new Event[nQuery+1];
	for(int i=1 ; i<=nQuery;i++)
	{
		cin>>query[i].left>>query[i].right>>query[i].value;
		query[i].index=i;
	}
	Event *finalQuery=new Event[n+nQuery+1];
	for(int i=1 ; i<=n ; i++)
	{
		finalQuery[i].value=arr[i];
		finalQuery[i].left=0;
		finalQuery[i].right=i;
		finalQuery[i].index=0;
	}
	//store all query too
	for(int i=n+1 ; i<=(nQuery+n);i++)
	{
		finalQuery[i].value=query[i-n].value;
		finalQuery[i].left=query[i-n].left;
		finalQuery[i].right=query[i-n].right;
		finalQuery[i].index=query[i-n].index;
	}
	sort(finalQuery+1 , finalQuery+n+1+nQuery , compare);
	int *output=new int[nQuery+1];
	int *BIT=new int[n+1]();
	for(int i=1; i<=(n+nQuery) ; i++)
	{
		if(finalQuery[i].index!=0)
		{
			output[finalQuery[i].index]=( getQuery(finalQuery[i].right,BIT)-getQuery(finalQuery[i].left-1 , BIT) );
		}else{
			int right=finalQuery[i].right;
			updateBIT(BIT ,right , n);
		}
	}
	for(int i=1;i<=nQuery;i++)
	{
		cout<<output[i]<<endl;
	}
}
