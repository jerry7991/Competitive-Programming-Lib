#include <iostream>
#define fon(i,n) for(int i=0 ; i<n;i++)
using namespace std;
int n,k,*price;
int getMaxProfit(int start , int nTransaction , bool onGoing)
{
	if(nTransaction==k)	return 0;
	if(start==n) return 0;
	//onthing is common that either any onegoing transaction are not... we can skipp the current transaction
	int ans=getMaxProfit(start+1 , nTransaction , onGoing);
	if(onGoing){
		//we can only sell the purchased price..
		int sell=getMaxProfit(start+1 , nTransaction+1 , false)+price[start];
		ans=max(sell , ans);
	}else{
		//we can make a transaction if only transaction is available
		if(nTransaction<k){
			int buy=getMaxProfit(start+1 , nTransaction, true)-price[start];//nTransaction not increase because currently we just buy it i.e. transaction not yet complited
			ans=max(ans , buy);
		}else{
			ans=0;
		}
	}
	return ans;
}
int main()
{
	int t;
	cin>>t;
	while (t--) {
		cin>>k>>n;
		price=new int[n];
		fon(i,n)	cin>>price[i];
		cout<<getMaxProfit(0,0 , false)<<endl;
	}
}
