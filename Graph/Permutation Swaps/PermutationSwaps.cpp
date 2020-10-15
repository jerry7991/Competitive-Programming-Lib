#include <iostream>
#include<vector>
#include <unordered_set>
using namespace std;
bool checkPossibilities(unordered_set<unordered_set<int>*>* conncetedComponent , vector<int> pi , vector<int> qi)
{
	unordered_set<unordered_set<int>*> :: iterator itr = conncetedComponent->begin();
	while (itr != conncetedComponent->end())
	{
		unordered_set<int>* component = *itr;
		itr++;
		unordered_set<int> ::iterator it = component->begin();
		while (it != component->end())
		{
			int index = *it;
			it++;
			int pElement = pi[index];
			unordered_set<int> ::iterator i = component->begin();
			while (i != component->end())
			{
				int qIndex = *i;
				if (pElement == qi[qIndex])
				{
					break;
				}
				i++;
			}
			if (i == component->end())
			{
				return false;
			}
		}
	}
	return true;
}
void dfs(vector<int>* edges , bool * visited   , unordered_set<int>* component , int start)
{
	//make start as visited
	visited[start] = true;
	component->insert(start);
	for (unsigned int i = 0; i < edges[start].size(); ++i)
	{
		int next = edges[start][i];
		if (!visited[next])
		{
			dfs(edges , visited   , component  , next);
		}
	}
}
bool isPossiblePermutation(vector<int> * edges , vector<int> pi, vector<int> qi , int n , int m )
{
	unordered_set< unordered_set<int>* > * conncetedComponent = new unordered_set< unordered_set<int> *>();
	//we need an visited array
	bool *visited = new bool[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = false;
	}
	//we need to traverse all the edge and make a dfs on each non-visited node
	for (int i = 0; i < n; ++i)
	{
		if (!visited[i])
		{
			//we will call the dfs for each non-visited element
			//and each dfs will give me the all the vertices that can be reached by current i
			//so we need to store each connected component
			unordered_set<int >* currConnectComp = new unordered_set<int>();
			dfs(edges , visited   , currConnectComp , i);
			conncetedComponent->insert(currConnectComp);
		}
	}
	return checkPossibilities(conncetedComponent , pi , qi);
}
int main()
{
	int testCase;
	cin >> testCase;
	while (testCase--)
	{
		int n, m;
		cin >> n >> m;
		std::vector<int> pi;
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin >> x;
			pi.push_back(x);
		}
		std::vector<int> qi;
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin >> x;
			qi.push_back(x);
		}
		std::vector<int> * edges = new std::vector<int> [n];
		for (int i = 0; i < m; ++i)
		{
			int src, dest;
			cin >> src >> dest;
			edges[src - 1].push_back(dest - 1);
			edges[dest - 1].push_back(src - 1); //undirceted
		}
		bool asnwer = isPossiblePermutation(edges , pi, qi , n , m );
		if (asnwer)
		{
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}