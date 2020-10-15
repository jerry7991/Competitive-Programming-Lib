#include <bits/stdc++.h>
using namespace std;
double solve(vector<int> salary){
	int *pref=new int[salary.size()+1];
	int *suff=new int[salary.size()+1];
	pref[0]=0;
	suff[salary.size()]=0;
	for(int i=1 ; i<=salary.size() ; i++){
		if(salary[i-1]){
			pref[i]=pref[i-1]+1;
		}else{
			pref[i]=0;
		}
	}
	for(int i=salary.size()-1 ; i>=0 ; i--){
		if(salary[i]){
			suff[i]=suff[i+1]+1;
		}else{
			suff[i]=0;
		}
	}
	int maxOne=0;
	for(int i=1 ; i<salary.size() ; i++){
		
			maxOne=max(maxOne , pref[i-1]+suff[i]);
		
	}
	delete []pref;
	delete []suff;
	return maxOne;
}
int main(){
	int n;
	cin>>n;
	vector<int>s;
	for(int i=0 ; i<n ; i++){
		int x;cin>>x;
		s.push_back(x);
	}
	cout<<solve(s);
}