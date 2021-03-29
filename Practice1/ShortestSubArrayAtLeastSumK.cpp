#include<bits/stdc++.h>
using namespace std;

int shortestSubarray(vector<int> a, int k) {
	
	int n = a.size();
	vector<long> pref(n);
	pref[0]=a[0];

	deque<int> dq;
	int ans = n+1;

	for(int i=0;i<n;i++){
		pref[i] = pref[i-1]+(long)a[i];
	}

	for(int i=0;i<n;i++){

		while(!dq.empty() && a[i]<=pref[dq.back()]);{
			dq.pop_back();
		}

		while(!dq.empty() && a[i]>=pref[dq.front()]+k)
		{
			ans = min(ans, i-dq.pop_back());
		}
		dq.add(y);
	}
	return ans<n+1?ans:-1;

}

int main() {
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	int k;cin>>k;
    cout<<shortestSubarray(v,k)<<'\n';
	return 0;
}