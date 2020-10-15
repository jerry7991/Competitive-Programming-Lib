#include <bits/stdc++.h>
using namespace std;
int kTHLargestSum(int *arr , int n , int k){
	priority_queue<int,vector<int>,greater<int>> pq;
	int *sum=new int[n+1];
	sum[0]=0;
	sum[1]=arr[0];
	for(int i=2 ;i<=n;i++){
		sum[i]=sum[i-1]+arr[i-1];
	}
	//calculate the contiguous sum sub arr
	for(int i=1;i<=n;i++){
		for(int j=i ; j<=n ; j++){
			int x=sum[j]-sum[i-1];
			//if pq size is less than k
			//just push
			if(pq.size()<k){
				pq.push(x);
			}else{
				//pop top element of heap and push it
				if(pq.top()<x){
					pq.pop();
					pq.push(x);
				}
			}
		}
	}
	return pq.top();
}
int main(){
	int n,k;
	cin>>n>>k;
	int *arr=new int[n];
	for(int i=0; i<n ; i++) cin>>arr[i];
		cout<<kTHLargestSum(arr , n ,k);
	delete []arr;
	return 0;
}