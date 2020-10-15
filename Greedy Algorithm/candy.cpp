#include <iostream>
#include <vector>
using namespace std;
int candy(vector<int>& ratings) {
	int n=ratings.size();
    int *c=new int[n];
    c[0]=1;//at least have to give one candy
    for(int i=1 ;i<n ; i++){
    	c[i]=1;//min possible candy
    	if(ratings[i]>ratings[i-1]) c[i]=c[i-1]+1;
    }
    for(int i=n-2 ; i>=0 ; i--){
    	if(ratings[i]>ratings[i+1]) c[i]=c[i+1]+1;
    }
    int count=0;
    for(int i=0 ; i<n ; i++) count+=c[i];
    	return count;
}
int main(){
	int m;cin>>m;
	vector<int> v;
	for (int i = 0; i < m; ++i)
	{
		int x;cin>>x;
		v.push_back(x);
	}
	cout<<candy(v);
}