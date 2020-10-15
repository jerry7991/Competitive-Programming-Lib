#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int solve(int *arr ,int n,unsigned int k){
	 priority_queue<int, vector<int>, greater<int> > pq; 
	 //insert all element into the pq;
	 for(int i=0 ; i<n ; i++){
	 	pq.push(arr[i]);
	 }
	 int count=0,ans=1;
	 while(!pq.empty() && count<k){
	 	long curr=(long)ans*pq.top();
	 	ans=(int)(curr%mod);
	 	pq.pop();
	 	count++;
	 }
	 return ans;
}
int main(){
	int n,k;
	cin>>n>>k;
	int *arr=new int[n];
	for(int i=0 ; i<n ; i++)cin>>arr[i];
		cout<<solve(arr , n,k);
		return 0;
}