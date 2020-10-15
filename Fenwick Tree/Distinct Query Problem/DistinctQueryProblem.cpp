#include <iostream>
#include <algorithm>
using namespace std;
class Event{
public:
	int first,second,index;
};
bool comapre(Event e1,Event e2)
{
	return (e1.second<e2.second);
}
void update(int index ,int value, int *BIT ,int n)
{
	for(;index<n; index+=(index&(-index)))
	{
		BIT[index]+=value;
	}
}
int getQuery(int index , int *BIT)
{
	int count=0;
	for(;index>0 ; index-=(index&(-index)))
	{
		count+=BIT[index];
	}
	return count;
}
int main()
{
	int n;
	cin>>n;
	int *arr=new int[n+1];
	int nMax=0;
	for (int i = 1; i <=n; ++i)
	{
		cin>>arr[i];
		nMax=max(nMax , arr[i]);
	}
	int nQuery;
	cin>>nQuery;
	Event * query=new Event[nQuery+1];
	for (int i = 1; i <=nQuery; ++i)
	{
		cin>>query[i].first>>query[i].second;
		query[i].index=i;
	}
	//first sort the query according their end time(greedy aproach)
	sort(query, query+nQuery+1 , comapre);
	int *BIT=new int[n+1]();
	//we need an array which store that where the current element is visited?
	// and if visited then what was his index
	//initially all unvisited and index=-1;
	int *visitIndex=new int[nMax+1];
	for (int i = 0; i <=nMax; ++i)
	{
		visitIndex[i]=-1;
	}
	//we need an output with which we can store the output
	int *output=new int[nQuery+1];
	int total=0;
	int k=0;
	for (int i = 1; i <=n; ++i)
	{
		if( visitIndex[arr[i]]!=-1 )
		{
			//that's means arr[i] index is already visited so we have to remove it from 
			//the BIT with their stored index... No need of this right now
			int index=visitIndex[arr[i]];
			update(index , -1 , BIT ,n);
		}else{
			//not visited i.e. distinct
			total++;
		}
		//now have to update the BIT i.e. current arr[i] has came as distinct 
		//cause if it was in BIT then it has been marked as -1
		update(i , 1 ,BIT, n);
		//now store the current index to currospond to arr[i] in visitIndex[]
		//for further use
		visitIndex[arr[i]]=i;
		//now we are done with query which has second==i
		while(k<nQuery && query[k].second==i)
		{
			output[query[k].index]=total-getQuery(query[k].first-1 , BIT);
			k++;
		}
	}
	//now we have output with solution;
	for (int i = 1; i <=nQuery; ++i)
	{
		cout<<output[i]<<endl;
	}
}