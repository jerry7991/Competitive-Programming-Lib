#include <bits/stdc++.h>
using namespace std;
int k;
int findBestBless(char *b1,char *b2 ,int k)
{
	//base case
	if(k==0)
	{
		return 0;
	}
	if(b1[0]=='\0' || b2[0]=='\0')
	{
		return INT_MIN;
	}
	//now we have two candition 
	//1st:- either both b1[0] and b2[0] is same
	if(b1[0]==b2[0])
	{
		//now we have 3 option 
		int bless=b1[0];
		//Option 1:- skip b1[0] and find bless for rest
		int option1=findBestBless(b1+1 , b2 ,k);
		//option 2:- skip b2[0] and find bless for rest
		int option2=findBestBless(b1 , b2+1 , k);
		//option 3:- pick common i.e. b1[0]==b2[0] i.e. i have picked a char for subsequence to bless
		int option3=bless+findBestBless(b1+1, b2+1,k-1);
		return (	max(option1 , max(option2 , option3))	);
	}else{
		//we have to option
		//skip b1[0] and find bless sequence on rest
		int option1=findBestBless(b1+1 , b2 , k);
		//skip b2[0] and find bless sequence  rest
		int option2=findBestBless(b1 , b2+1  , k);
		return (	(option1>option2)?option1 :option2	);
	}
}
int main()
{
	char *b1=new char[100];
	char *b2=new char[100];
	cin>>b1>>b2;
	cin>>k;
	int x=findBestBless(b1,b2,k);
	if(x/97>=k)
		cout<<x<<endl;
	else
		cout<<0<<endl;
	//cout<<"\n What would be the time complexity of this algorithm ... That is O(3^N)... \n";
	//release memory
	delete []b1;
	delete []b2;
	return 0;
}