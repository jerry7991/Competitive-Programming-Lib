#include<bits/stdc++.h>
using namespace std;
void solve(string str){
	stack<char> st;
	for(int i=0 ; i<str.size() ; i++){
		if(st.size() && st.top()=='(' && st.top()==str[i+1] && st.top()==str[i+1]){
			st.pop();
			i=i+1;
			continue;
		}
		st.push(str[i]);
	}
	int ans=0;
	while(st.size()){
		char ch1=st.top();
		st.pop();
		if(st.size())
			char ch2=st.top();
		if(ch1==')' && ch2==')') || (ch1=='(' && ch2==')' || (ch1==')' && ch2=='(')) ans++;
		else{
			ans+=2;
		}
	}
	return ans;
}
int main(){
	string str;
	cin>>str;
	cout<<solve(str);
}