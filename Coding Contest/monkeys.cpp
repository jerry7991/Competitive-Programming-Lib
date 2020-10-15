#include <iostream>
#include <unordered_map>
using namespace std;
void solve(){
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0 ; i<n ; i++) cin>>*(arr+i);
	unordered_map<string , int> isVisit;
	string str;
	int *location=new int[n];
	for(int i=0 ; i<n ; i++){
		str=str+to_string(i);
		location[i]=i;
	}
	isVisit[str]++;
	int time=0;
	while(true){
		string st;
		time++;
		for(int i=0 ; i<n ; i++)
		{
			location[i]=(location[i]+arr[i])%n;
			st=st+to_string(location[i]);
		}
		if(isVisit[st]) break;
		isVisit[st]++;
	}
	cout<<time<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}