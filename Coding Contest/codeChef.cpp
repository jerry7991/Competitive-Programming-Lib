#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin>>n;
	unordered_set<long long> st;
	long long totalOr=0;
	bool ans=true;
	long long *arr=new long long[n];
	for(int i=0 ;i<n  ; i++){
		cin>>arr[i];
	}
	st.insert(arr[0]);
	totalOr=arr[0];
	for(int i=1 ; i<n && ans ; i++){
		if(st.find(arr[i])==st.end()){
			st.insert(arr[i]);
		}else{
			ans=false;
		}
		if( st.find(totalOr | arr[i])==st.end()){
			st.insert(totalOr | arr[i]);
		}else{
			ans=false;
		}
		if(i>1){
			if( st.find(arr[i] | arr[i-1])==st.end()){
				st.insert(arr[i] | arr[i-1]);
			}else{
				ans=false;
			}
		}
	}
	if(ans){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--) solve();
}









	/*
	if(st.find(curr)==st.end())
					st.insert(curr);
				else 
					ans=false;
				if(last){
					if( st.find(curr | last)==st.end())
						st.insert(curr | last);
					else 
						ans=false;
				}
				if(totalOr){
					if(st.find(totalOr | curr)==st.end())
						st.insert(totalOr | curr);
					else 
						ans=false;
				}
				last=curr;
				totalOr |=curr;
	*/