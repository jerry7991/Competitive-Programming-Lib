#include <bits/stdc++.h>
using namespace std;
int solve(int *arr , int n){
	priority_queue<int,vector<int> , greater<int>> pq;
	for(int i=0 ; i<n ; i++){
		pq.push(arr[i]);
	}
	int cost=0;
	while(pq.size()!=1){
		int x=pq.top();
		pq.pop();
		int y=pq.top();
		pq.pop();
		pq.push(x+y);
		cost+=x+y;
	}
	return cost;
}
int main(){
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0 ; i<n ; i++) cin>>arr[i];
	cout<<solve(arr,n);
delete []arr;
return 0;
}