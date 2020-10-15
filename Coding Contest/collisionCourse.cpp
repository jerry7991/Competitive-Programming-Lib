#include <bits/stdc++.h>
#define ll long long int
using namespace std;
struct Location
{
	ll x,y,sp;
};
double Time(ll x , ll y , ll sp){
	return ((double)sqrt(x*x+y*y)/sp);
}
int main(){
	int n;
	cin>>n;
	Location *location=new Location[n];
	for(int i=0 ; i<n ; i++){
		ll x,y,sp;
		cin>>x>>y>>sp;
		location[i].x=x;
		location[i].y=y;
		location[i].sp=sp;
	}
	double *time =new double[n];
	for(int i=0 ; i<n ; i++){
		time[i]=Time(location[i].x , location[i].y,location[i].sp);
	}
	// for(int i=0 ;i<n ; i++)
	// 	cout<<time[i]<<endl;
	sort(time , time+n);
	int coll=0;
	for(int i=0 ; i<n ; i++){
		int j=i+1;
		while(time[i]==time[j]){
			j++;
			coll++;
		}
	}
	cout<<coll<<endl;
}