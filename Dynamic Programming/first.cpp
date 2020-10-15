#include <iostream>
#define fon(i,n)
using namespace std;
int main()
{
	char ch[10];
	for(int i=0 ; i<10 ; i++)
	{
		cin>>ch[i];
	}
	cout<<ch<<endl;
	int x=(int)(&ch);
	cout<<x<<endl;
	cout << static_cast<const void*>(ch) << endl;
}