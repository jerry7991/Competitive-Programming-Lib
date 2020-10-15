#include<bits/stdc++.h>
using namespace std;
vector<int> vt(){
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	return v;
}
int * arr(){
	int *a=new int[4];
	a[0]=1;
	a[1]=2;
	a[2]=3;
	a[3]=4;
	return a;
}
int main(){
	vector<int> ans=vt();
	for(auto x: ans) cout<<x<<' ';
	int *a=arr();
	for(int i=0 ; i<4 ; i++) cout<<a[i]<<' ';
		return 0;
}