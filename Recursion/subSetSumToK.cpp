#include <iostream>
#include <vector>
using namespace std;
int subsetSumToK(int input[], int n, int output[][50], int k) 
{
	int count=0;
	int len=0;
	while(count<(1<<n)){
		int x=count++;
		int sum=0;
		vector<int> v;
		while(x){
			v.push_back(x%2);
			x/=2;
		}
		int setBit=0;
		for(int i=0 ; i<v.size();i++){
			//cout<<v[i];
			if(v[i]) 
				{
					sum+=input[i];
					setBit++;
				}
		}
		//cout<<endl;
		//cout<<sum<<endl;
		if(sum==k){
			output[len][0]=setBit;
			int index=1;
			for(int i=0 ; i<v.size();i++){
				if(v[i]){
					output[len][index++]=input[i];
					//cout<<input[i]<<" ";
				}
			}
			//cout<<endl;
			len++;
		}
	}
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