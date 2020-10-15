#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int len=0;
void printsubset(int input[] , int n , int k , int start , vector<int> v,int output[][50]){
	if(start==n || k<0){
		return;
	}
	if(k==0){
		output[len][0]=v.size();
		int index=1;
		for(auto x: v) output[len][index++]=x;
			len++;
	return;
	}
	printsubset(input , n , k , start+1 , v,output);
	v.push_back(input[start]);
	printsubset(input , n , k-input[start] , start+1,v,output);
}
int subsetSumToK(int input[], int n, int output[][50], int k) 
{
	vector<int>v;
	printsubset(input , n , k ,0,v,output);
	return len;
}
int main(){
	int input[21];
	int output[50][50];
	int n;
	cin>>n;
	for(int i=0 ; i<n ; i++) cin>>input[i];
	int k;
	cin>>k;
	int x=subsetSumToK(input , n ,output , k);
	cout<<x<<endl;
	for(int i=0 ; i<x;i++){
		int j=output[i][0];
		for(int l=1 ; l<=j ; l++)	cout<<output[i][l]<<" ";
		cout<<endl;
	}
}