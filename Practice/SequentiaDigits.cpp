#include<bits/stdc++.h>
using namespace std;
vector<int> solve(int low ,int high){
	vector<int>output;
	queue<int> q;
	for(int i=1;i<10;i++) q.push(i);
	while(q.size()){
		int f=q.front();
		q.pop();
		if(f>high) break;
		if(f>=low ){
			output.push_back(f);
		}
		int rem=f%10;
		if(rem<9)
			q.push(f*10+rem+1);
	}
	return output;
}
int main(){
	int low,high;cin>>low>>high;
	vector<int> output=solve(low , high);
	for(auto x:output) cout<<x<<' ';
 return 0;
}
		