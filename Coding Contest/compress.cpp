#include<bits/stdc++.h>
using namespace std;
class Word{
public:
	char ch;
	int freq;
};
bool compare(Word w1 , Word w2){
	return w1.freq<w2.freq;
}
int solve(string str , int k){
	map<char,int>feq;
	for(int i=0 ; i<str.size();i++) feq[str[i]]++;
	Word *word=new Word[feq.size()];
	int i=0;
	for(auto x:feq){
		word[i].ch=x.first;
		word[i].freq=x.second;
		i++;
	}
	sort(word , word+feq.size() , compare);
	i=0;
	while(k>0){
		if(word[i].freq<=k){
			k-=word[i].freq;
			word[i].freq=0;
			i++;
		}
	}
		int count=0;
	for(int i=0 ; i<feq.size() ; i++) {
		if(word[i].freq==1){
			count++;
			continue;
		}else if(word[i].freq==0){
			continue;
		}
			int x=0;
			while(word[i].freq){
				word[i].freq/=10;
				x++;
			}
			count+=x+1;
	}
	return count;
}
int main(){
	string str;
	int k;
	cin>>str;
	cin>>k;
	cout<<solve(str ,k)<<'\n';
}