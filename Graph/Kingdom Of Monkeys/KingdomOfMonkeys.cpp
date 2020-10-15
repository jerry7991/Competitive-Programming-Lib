#include <iostream>
#include <vector>
#include <unordered_set>
#define fon(i , n) for(int i=0 ; i<n ; i++)
#define uos unordered_set
#define pb(n) push_back(n)
#define ll long long
using namespace std;
void addGroup(vector<int>* group ,uos<int>* component ,bool * grouped , int start)
{
	//make start monkey as grouped
	grouped[start]=true;
	//add start moneky in current comppnent
	component->insert(start);
	//look all the way for which current monkey can make group
	fon(i , group[start].size())
	{
		int curr=group[start][i];
		//if this current monkey is not yet grouped in any group compenent
		if (!grouped[curr])
		{
			//then do recursively same thing what i have done currently for start
			addGroup(group , component , grouped , curr);//now start replaced by curr cause of allready added in group component
		}
	}
}
ll getMaxGold(vector<int> * group ,int nMonkey , ll *banana)
{
	bool * grouped=new bool[nMonkey];
	fon(i , nMonkey)
		grouped[i]=false;
	uos<uos<int>*>* totalGroup=new uos<uos<int>*>();
	fon(i , nMonkey)
	{
		if (!grouped[i])
		{
			uos<int>*component=new uos<int>();
			addGroup(group , component , grouped ,i);
			//add this new group component into totalGroup
			totalGroup->insert(component);
		}
	}
	//now we have all monkey within their group and which group has max banana that will be gold coin
	ll maxGold=0;
	uos<uos<int>*> ::iterator itr=totalGroup->begin();
	while(itr!=totalGroup->end())
	{
		uos<int>*component=*itr;
		uos<int> :: iterator it=component->begin();
		ll currGold=0;
		while(it!= component->end())
		{
			currGold+= *(banana+(*it));
			it++;
		}
		maxGold = (maxGold < currGold)? currGold :maxGold;
		itr++;
		//now we have done with current component of group so we can delete it
		delete component;
	}
	delete [] grouped;
	return maxGold;
}
int main()
{
	int testCase;
	cin>>testCase;
	while(testCase--)
	{
		int nMonkey,mGroup;
		cin>>nMonkey>>mGroup;
		vector<int> * group=new vector<int>[nMonkey];
		fon(i , mGroup)
		{
			int x,y;	
			cin>>x>>y;
			group[x-1].pb(y-1);
			group[y-1].pb(x-1);
		}
		ll *banana=new ll[nMonkey];
		for(int i=0 ;i< nMonkey ; i++)
		{
			cin>>*(banana+i);
		}
		ll answer=getMaxGold(group , nMonkey , banana);
		cout<<answer<<endl;
		//we are done so clear heap memory
		delete [] group;
		delete [] banana;
	}
}