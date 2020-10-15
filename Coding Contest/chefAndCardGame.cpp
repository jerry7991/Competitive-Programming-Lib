#include <iostream>
using namespace std;
void solve(){
	int m=0,c=0;
	int round,x,y;
	unsigned long int xSum=0,ySum=0;
	cin>>round;
	while(round--){
		cin>>x>>y;
		while(x & y){
			xSum+=x%10;
			x/=10;
			ySum+=y%10;
			y/=10;
		}
		while(x){
			xSum+=x%10;
			x/=10;
		}
		while(y){
			ySum+=y%10;
			y/=10;
		}
		c+=(xSum>=ySum);
		m+=(ySum>=xSum);
		xSum=ySum=0;
	}
	if(c==m){
		cout<<2<<" "<<c<<endl;
	}else if(c>m){
		cout<<0<<" "<<c<<endl;
	}else{
		cout<<1<<" "<<m<<endl;
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}