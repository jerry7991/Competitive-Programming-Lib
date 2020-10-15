#include <iostream>
using namespace std;
class Details{
public:
	int time,cost;
};
int solve(Details ** details,bool **visited , int t , int n , int si=0 , int sj=0){
	//if(t<0) return INT_MAX;
	cout<<si<<" "<<sj<<endl;
	visited[si][sj]=true;
	int ans=INT_MAX;
	for(int i=si ; i<n ; i++){
		for(int j=sj ; j<n ; j++){
			if(visited[si][sj] || si==sj) continue;
			ans=min(ans , details[i][j].cost+solve(details , visited , t-details[i][j].time , n ,i ,j));
		}
	}
	visited[si][sj]=false;
	return ans;
}
int main(){
	int n,t;
	cin>>n>>t;
	Details ** details=new Details*[n];
	bool **visited=new bool*[n];
	for(int i=0 ; i<n;i++){
		details[i]=new Details[n];
		visited[i]=new bool[n];
		for(int j=0 ; j<n ; j++){
			cin>>details[i][j].time;
			visited[i][j]=false;
		}
	} 
	for(int i=0 ; i<n;i++){
		for(int j=0 ; j<n ; j++)
			cin>>details[i][j].cost;
	}
	cout<<solve(details,visited ,t,n);
}