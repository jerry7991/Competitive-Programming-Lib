#include<bits/stdc++.h>
using namespace std;
int gcd(int a , int b){
	if(b==0) return a;
	if(b>a) return gcd(b,a);
	return gcd(b , a%b);
}
void dfs(unordered_map<int, vector<int>> &adjList , unordered_map<int,int> &visited , int curr , int& len){
	visited[curr]=1;
	len++;
	for(auto y: adjList[curr]){
		if(visited[y]) continue;
		dfs(adjList , visited , y , len);
	}
}
int largestComponentSize(vector<int>& arr) {
    unordered_map<int,vector<int>> adjList;
    for(unsigned int i=0 ; i<arr.size() ; i++){
    	for(unsigned int j=i+1 ; j<arr.size() ; j++){
    		if(gcd(arr[i] , arr[j])>1){
    			adjList[arr[i]].push_back(arr[j]);
    			adjList[arr[j]].push_back(arr[i]);
    		}
    	}
    }
    int ans=0;
    unordered_map<int , int> visited;
    for(unsigned int i=0 ; i<arr.size() ; i++){
    	int currAns=0;
    	if(visited[arr[i]]) continue;
    	dfs(adjList , visited ,arr[i] ,currAns);
    	ans=max(ans , currAns);
    }
    return ans;
}
int main(){
	int n;cin>>n;
	vector<int> v(n);
	for(int i=0 ; i<n ; i++)cin>>v[i];
	cout<<largestComponentSize(v)<<'\n';
 return 0;
}
		