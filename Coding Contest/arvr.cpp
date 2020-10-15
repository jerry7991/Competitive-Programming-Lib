#include <bits/stdc++.h>
using namespace std;
double solve(vector<int> salary){
	int minS=INT_MAX , maxS=INT_MIN;
      double sum=0;
      for(int i=0 ; i<salary.size() ; i++){
        sum+=(double)salary[i];
        minS=min(minS , salary[i]);
        maxS=max(maxS , salary[i]);
      }
      sum-=(minS+maxS);
      double ans=(sum/((double)salary.size()-2));
      return ans;
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