#include <bits/stdc++.h>
using namespace std;
int getParent(unordered_map<int , int> &parent , int src){
	if(parent.find(src)==parent.end()) return parent[src]=src;
	if(parent[src]==src) return src;
	return parent[src]=getParent(parent,parent[src]);
}
int largestComponentSize(vector<int> &arr){
	unordered_map<int,int> parent;
	for(int i=0 ; i<arr.size() ;i++) parent[arr[i]]=arr[i];
	for(int i=0 ; i<arr.size() ; i++){
		for(int j=2 ; j<=sqrt(arr[i]) ; j++){
			if(arr[i]%j==0){
					parent[getParent(parent , arr[i])]=parent[getParent(parent ,j)];
					parent[getParent(parent , arr[i])]=parent[getParent(parent , arr[i]/j)];
			}
		}
	}
	unordered_map<int,int> freq;
	int ans=1;
	for(auto x: arr){
		ans=max(ans , ++freq[getParent(parent , x)]);
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
		