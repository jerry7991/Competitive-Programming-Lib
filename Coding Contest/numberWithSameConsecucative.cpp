#include<bits/stdc++.h>
using namespace std;
unordered_set<int> st;
vector<int> output;
int abs(int x){
  if(x<0) return -1*x;
  return x;
}
void solve(int n , int k , int last=0 , int number=0){
  if(n==0){
    if(st.find(number)==st.end()){
      st.insert(number);
      output.push_back(number);
    }
    return;
  }
  for(int i=0 ; i<10 ; i++){
    if(last==0 && number==0){
      solve(n-1,  k , i+(i==0) , i+(i==0));
    }
    else if(abs(last-i)==k){
      solve(n-1 , k , i , number*10+i);
    }
  }
}
vector<int> numsSameConsecDiff(int n, int k) {
  if(n==0) return output;
  if(n==1){
    for(int i=0 ; i<10 ; i++)
      output.push_back(i);
  return output;
  }
  solve(n, k);
  return output;
}
int main(){
  int n,k;
  cin>>n>>k;
  vector<int> output=numsSameConsecDiff(n,k);
  for(int i=0 ; i<output.size() ;i++) cout<<output[i]<<" ";
  return 0;
}