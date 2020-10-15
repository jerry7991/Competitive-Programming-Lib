#include <iostream>
using namespace std;
int main(){
	int v,e,q;
	cin>>v>>e>>q;
	unsigned long long **wtMatrix=new unsigned long long*[v];
	for(int i=0 ; i<v; i++){
		wtMatrix[i]=newunsigned  long long[v];
		for(int j=0 ; j<v; j++){
			wtMatrix[i][j]=INT_MAX;
		}
	}
	for(int i=0 ; i<e;i++){
		int x,y,wt;
		cin>>x>>y>>wt;
		wtMatrix[x-1][y-1]=wt;
		wtMatrix[y-1][x-1]=wt;
	}
	for(int i=0 ; i<v ; i++){
		for(int j=0 ; j<v;j++){
			for(int k=0 ; k<v; k++){
				if(wtMatrix[i][j]+wtMatrix[j][k]<wtMatrix[i][k]){
					wtMatrix[i][k]=wtMatrix[i][j]+wtMatrix[j][k];
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(wtMatrix[x-1][y-1]==INT_MAX) cout<<-1<<endl;
		else cout<<wtMatrix[x-1][y-1]<<endl;
	}
}