#include<bits/stdc++.h>
#include "Tries.h"
using namespace std;
int main(){
	Tries *tries=new Tries();
	while(true){
		char ch;
		cin>>ch;
		if(ch=='i'){
			string str;
			cin>>str;
			tries->insert(str);
		}else if(ch=='s'){
			string str;cin>>str;
			cout<<tries->search(str)<<'\n';
		}
		else{
			tries->print();
		}
	}
 return 0;
}