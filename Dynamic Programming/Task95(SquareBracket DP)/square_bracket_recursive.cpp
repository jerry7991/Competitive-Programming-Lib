#include <iostream>
using namespace std;
int numberOfTotalValideSquare(int n ,int openning ,int clossing ,bool *memo)
{
	if(openning>n || clossing >n)
	{
		return 0;
	}
	if(openning==n && clossing==n)
		return 1;
	
	if(openning==clossing || memo[openning+clossing+1])
	{
		//we have to choose only openning bracket 
		return (numberOfTotalValideSquare(n , openning+1 , clossing , memo));
	}else if(openning==n)
	{
		//we have to choose only clossing bracket
		return ( numberOfTotalValideSquare(n  , openning , clossing+1 , memo) );
	}else{
		//we have both option weather i can choose openning bracket or clossing bracket
		int option1=	numberOfTotalValideSquare(n , openning+1 , clossing , memo);
		int option2=	numberOfTotalValideSquare(n , openning , clossing+1 , memo);
		return (option1+option2);
	}
}
int main()
{
	int dataSet;
	cin>>dataSet;
	while(dataSet--)
	{
		int n , k;
		cin>>n>>k;
		bool *memo=new bool[2*n+1];
		for (int i = 0; i <=2*n; ++i)
		{
			memo[i]=false;
		}
		for (int i = 0; i < k; ++i)
		{
			int s;
			cin>>s;
			memo[s]=true;
		}
        if(memo[0])
        {
            //because s exist in between 0<s<=2*n
            cout<<0<<endl;
            continue;
        }
		cout<<numberOfTotalValideSquare(n , 0 , 0 ,	memo)<<endl;
		delete [] memo;
	}
	cout<<"Due to repeatition time complexity will be worst";
	return 0;
}