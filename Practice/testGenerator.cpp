#include <iostream>
using namespace std;
int main(){
	char ch;
	for(int i=1;i<=100;i++){
		for(int j=1;j<=i && j<=16;j++){
		  ch=('a')+(i/16);
		  cout<<ch;
		}
		cout<<'\n';
	}
}