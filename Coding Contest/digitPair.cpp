#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	set<int> st;
	while(n--){
		int x;
		cin>>x;
		vector<int> v;
		while(x){
			v.push_back(x%10);
			x/=10;
		}
		reverse(v.begin(), v.end());
		
	}
}