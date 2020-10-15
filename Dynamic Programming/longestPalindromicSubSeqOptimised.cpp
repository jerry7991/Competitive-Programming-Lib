#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define fon(i,n) for(unsigned int i=0 ; i<n ; i++)
#define ui	unsigned int
#define ll long long
#define ull unsigned long long 
#define uos unordered_set
#define upm unordered_map
using namespace std;
int longestPalindromeSubseq(string s){
	  vector<vector<int>> longest(s.size(), vector<int>(s.size()));
        for (int len=1; len<=s.size(); len++) {
            for (int lhs=0; lhs+len<=s.size(); lhs++) {
                int rhs = lhs+len-1;
                if (lhs == rhs) {
                    longest[lhs][rhs] = 1;
                } else if (lhs+1 == rhs) {
                    longest[lhs][rhs] = (s[lhs] == s[rhs]) ? 2 : 1;
                } else {
                    int add = s[lhs] == s[rhs] ? 2 : 0;
                    longest[lhs][rhs] = max(max(longest[lhs][rhs-1], longest[lhs+1][rhs]), longest[lhs+1][rhs-1] + add);
                }
            }
        }
        
        return longest[0].back();
}
int main(){
	string str;
	cin>>str;
	cout<<longestPalindromeSubseq(str);
}