#include <iostream>
#include <cstring>
using namespace std;
void printCombination(int n , string str="" , int k=1)
{
	if (n==0)
	{
		cout<<str<<endl;
		return;
	}
	for (int i = k; i <= n; ++i)
	{
		printCombination(n-i , str+to_string(i)+" " , i);
	}
}
int main()
{
	int n;
	cin>>n;
	printCombination(n);
	return 0;
}