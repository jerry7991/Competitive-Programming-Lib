#include <bits/stdc++.h>
using namespace std;

#define LEFT 0
#define RIGHT 1

bool is_bipartite(vector<vector<int> > &adj_list)
{
	int num_nodes = adj_list.size() - 1;
	unordered_set<int> partition[2];
	queue<int> pending_nodes;
	vector<bool> visited(num_nodes + 1, false);
	for ( int i = 1 ; i <= num_nodes ; i++ )
	{
		if (visited[i]) continue;
		visited[i] = true;
		partition[LEFT].insert(i);
		pending_nodes.push(i);

		int current;
		while(!pending_nodes.empty())
		{
			int node = pending_nodes.front();
			pending_nodes.pop();
            visited[node] = true;
			vector<int> adj_nodes = adj_list[node];
			current = (partition[LEFT].count(node) == 0)?RIGHT:LEFT;
			for (int neighbour : adj_nodes)
			{
                visited[neighbour] = true;
				if(partition[current].count(neighbour) > 0) return false;
				assert(partition[current].count(neighbour) == 0);
				if(partition[1 - current].count(neighbour) ==  0)
				{
					partition[1 - current].insert(neighbour);	
					pending_nodes.push(neighbour);
				}
			}
			current = 1 - current;
		}
	}
	return true;
}

void solve()
{
	int nodes;scanf("%d", &nodes);

	int edges;scanf("%d", &edges);
	
	vector<vector<int> > adj_list(nodes + 1);//, adj_list_transpose(nodes + 1);
	for (int edge = 1; edge <= edges ; edge += 1)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}
	bool bipartite = is_bipartite(adj_list);

	if(bipartite) printf("No suspicious bugs found!\n");
	else printf("Suspicious bugs found!\n");
	
}

int main(int argc, char const *argv[])
{
	int tests;
	scanf("%d", &tests);
	for (int t = 1 ;t <= tests ; t += 1)
	{
		printf("Scenario #%d:\n",t);
		solve();
	}
	return 0;
}