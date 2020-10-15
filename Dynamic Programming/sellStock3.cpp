#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices ){
	int n=prices.size();
	if(n<2) return 0;
	int *prefMin=new int[n];
	int *suffMax=new int[n];
	suffMax[n-1]=prices[n-1];
	prefMin[0]=prices[0];
	for(int i=1 ; i<n ; i++){
		prefMin[i]=min(prefMin[i-1] , prices[i]);
		suffMax[n-i-1]=max(suffMax[n-i] , prices[n-i-1]);
	}
	int ans=0;
	for(int i=0 ; i<n ; i++){
		ans=max(ans , suffMax[i]-prefMin[i]);
	}
	delete[] prefMin;
	delete[] suffMax;
	return ans;
}
int maxProfitBetter(vector<int>& prices ){
	int n=prices.size();
	if(n<2) return 0;
	int prefMin;
	int suffMax;
	suffMax=prices[n-1];
	prefMin=prices[0];
	int ans=0;
	for(int i=1 ; i<n/2 ; i++){
		prefMin=min(prefMin, prices[i]);
		suffMax=max(suffMax, prices[n-i-1]);
		ans=max(ans , suffMax-prefMin);
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<maxProfit(v)<<endl;
	cout<<maxProfitBetter(v);
}