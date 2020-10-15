#include <iostream>
using namespace std;
int main()
{
	int s,k;
	cin>>s>>k;
	int *arr=new int[k];
	arr[0]=1;
	s -=1;
	for(int i=k-1 ; i>0 ; i--)
	{
		if(s<=0)
		{
			arr[i]=0;
		}
		else if (s<=9)
		{
			arr[i]=s;
			s =s-arr[i];
		}else{
			arr[i]=9;
			s 	=s- 9;
		}
	}
	if (s>0)
	{
		arr[0] +=s;
	}
	for (int i = 0; i < k; ++i)
	{
		cout<<arr[i];
	}
}