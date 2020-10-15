#include<bits/stdc++.h>
using namespace std;
class Details {
public:
	int src, dest, weight;
};
class Subset {
public:
	int parent;
	int rank;
};
bool compare(Details dt1 , Details dt2) {
	return dt1.weight < dt2.weight;
}
int find(Subset *subset , int u) {
	//find parent and make as parent of current u i.e. path compression
	if (subset[u].parent != u) {
		return subset[u].parent = find(subset , subset[u].parent);
	}
	return subset[u].parent;
}
void Union(Subset *subset , int u , int v) {
	int uParent = find(subset , u);
	int vParent = find(subset , v);
	//attach smaller rank tree under parent of high rank tree (union by rank)
	if (subset[uParent].rank < subset[vParent].rank) {
		subset[uParent].parent = vParent;
	} else if (subset[vParent].rank < subset[uParent].rank) {
		subset[vParent].parent = uParent;
	} else {
		//if rank is same then make one as a root and increment the rank of that
		subset[uParent].parent = vParent;
		subset[vParent].rank++;
	}
}
void kruskal(Details *dt , int e , int n) {
	sort(dt , dt + e , compare);
	Subset *subset = new Subset[n];
	for (int i = 0 ; i < n ; i++) subset[i].parent = i , subset[i].rank = 0;
	Details *output = new Details[n - 1];
	int mst = 0, edge = 0;
	while (mst < n - 1) {
		int u = dt[edge].src;
		int v = dt[edge].dest;
		int uParent = find(subset , u);
		int vParent = find(subset , v);
		if (uParent != vParent) {
			output[mst++] = dt[edge];
			Union(subset , uParent , vParent);
		}
		edge++;
	}
	for (int i = 0 ; i < n - 1 ; i++) {
		cout << min(output[i].src , output[i].dest) << " " << max(output[i].src , output[i].dest) << " " << output[i].weight << endl;
	}
}
void solve() {
	int n, m;
	cin >> n >> m;
	Details *dt = new Details[m];
	for (int i = 0; i < m; i++) {
		cin >> dt[i].src >> dt[i].dest >> dt[i].weight;
	}
	kruskal(dt , m , n);
}
int main() {
	solve();
	return 0;
}