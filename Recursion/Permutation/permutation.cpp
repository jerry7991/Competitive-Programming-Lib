#include <iostream>
#include <cstring>
using namespace std;
void permutation( string str , int start , int len)
{
	if (start==len)
	{
		cout<<str<<endl;
		return;
	}else{
		for (int i = start; i <=len; ++i)
		{
			swap(str[start] , str[i]);
			permutation(str ,start+1 , len);
			//bracktrack what i have done;
			swap(str[start] , str[i]);
		}
	}
}
int main()
{
	string str;
	cin>>str;
	int len=str.size();
	permutation(str , 0 , len-1);
}