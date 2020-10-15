#include <iostream>
using namespace std;
void solve(int n){
	for(int i=1 ; i<=n ;i++){
		if(i==1 || i==n){
			for(int j=1 ; j<=n ; j++) cout<<"#";
        if(i!=n)
			cout<<'\n';
		}else{
			for(int j=1 ; j<=n ; j++){
				if(j==1 || j==n) cout<<"*";
				else cout<<" ";
			}
            if(i!=n)
			 cout<<'\n';
		}
	}
}
int main(){
	int n;
	cin>>n;
	solve(n);
}