#include<bits/stdc++.h>
using namespace std;
inline int min(int a,int b){ return (a>b)?b:a;}
inline int getCompressLen(string str){
	string st;
	cout<<str<<' ';
	for(int i=0 ; i<str.size();){
		st=st+str[i];
		int count=1,index=i+1;
			while(index<str.size() && str[index]==str[i]) index++,count++;
		i=index;
		if(count>1)
			st=st+to_string(count);
	}
	cout<<st<<'\n';
	return st.size();
}
int getLengthOfOptimalCompression(string s, int k , int start=0) {
    if(k==0 || start>=s.size())
    	return getCompressLen(s);
    int i=start+1;
    for(i=start ; i<s.size() ; i++){
    	if(s[i]!=s[start]) break;
    }
    //now we have two option we can delete or not
    int _delete=getLengthOfOptimalCompression(s.substr(0,start)+s.substr(i,s.size()-i+1) , k-1 , i);
    int not_delete=getLengthOfOptimalCompression(s , k , i+1);
    return min(_delete , not_delete);
}
int main(){
	string str;
	cin>>str;
	int k;cin>>k;
	cout<<getLengthOfOptimalCompression(str ,k)<<'\n';
	return 0;
}