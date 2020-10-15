#include<iostream>
using namespace std;
int numberOfTotalValideSquare(int n , int openning , int clossing)
{
	if(openning==n && clossing==n)
		return 1;
	if(openning==clossing)
	{
		//then we have to pick an new openning bracket because all clossing bracked balanced
		return numberOfTotalValideSquare(n , openning+1 , clossing);
	}else if(openning==n)
	{
		return numberOfTotalValideSquare(n , openning,clossing+1);
	}
	else{
		int option1=numberOfTotalValideSquare(n,openning ,clossing+1);
		int option2=numberOfTotalValideSquare(n,openning+1 , clossing);
		return (option1 + option2);
	}
}
int main()
{
	int n;
	cin>>n;
	cout<<"\n Total numnber of way to make a square bracket of lengh =	"<<2*n<<endl;
	cout<<numberOfTotalValideSquare(n , 0 , 0);
}