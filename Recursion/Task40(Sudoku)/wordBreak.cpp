#include <bits/stdc++.h>
using namespace std;
unordered_map<string , int> isPresent;
void printValideWord(string input,int i , string result=""){
	string s=input.substr(0,i+1);
	int k=input.size();
	if(isPresent[s]){
		if(i<k-1){
			//ie string not yet ended
			printValideWord(input.substr(i+1 , k-i) , 0 , result+s+" ");
		}else{
			//string has ended
			cout<<(result+s)<<endl;
		}
	}
	if(i<k-1){
		//find next valid string's word
		printValideWord(input , i+1 , result);
	}
}
int main(){
	int n;
	cin>>n;
	while(n--){
		string str;
		cin>>str;
		isPresent[str]++;
	}
	string input;
	cin>>input;
	printValideWord(input,0);
}