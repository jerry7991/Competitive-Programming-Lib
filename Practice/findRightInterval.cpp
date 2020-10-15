#include<bits/stdc++.h>
using namespace std;
class Interval{
public:
	int aTime;
	int fTime;
	int index;
};
bool compare(Interval itr1 , Interval itr2){
	return itr1.aTime<itr2.aTime;
}
int getFirstNonConflictInterval(Interval *interval , int start , int end , int val){
  if(start>end) return -1;
  int mid=(start+end)/2;
  if(interval[mid].aTime<val){
  	return getFirstNonConflictInterval(interval , mid+1 , end , val);
  }else if(interval[mid].aTime>=val && interval[mid-1].aTime>=val){
  	return getFirstNonConflictInterval(interval , start , mid-1 , val);
  }else{
  	return mid;
  }
}
vector<int> findRightInterval(vector<vector<int>>& intervals) {
	int n=intervals.size();
	Interval *interval=new Interval[n];
	for(int i=0 ; i<n;i++){
		interval[i].aTime=intervals[i][0];
		interval[i].fTime=intervals[i][1];
		interval[i].index=i;
	}
	sort(interval ,interval+n , compare);
	vector<int> output(n);
	for(int i=0 ; i<n ; i++){
		int x=getFirstNonConflictInterval(interval , 0 , n-1 , interval[i].fTime);
		if(x!=-1)
			output[interval[i].index]=interval[x].index;
		else
			output[interval[i].index]=x;
	}
	return output;
}
int main(){
	int n;
	cin>>n;
	vector<vector<int>> v;
	for(int i=0 ; i<n  ; i++){
		vector<int> v1(2);
		cin>>v1[0]>>v1[1];
		v.push_back(v1);
	}
	vector<int> output=findRightInterval(v);
	for(unsigned int i=0 ; i<output.size() ; i++) cout<<output[i]<<' ';
}