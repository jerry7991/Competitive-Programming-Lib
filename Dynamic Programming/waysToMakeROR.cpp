#include <iostream>
#include <string>
using namespace std;
long long int geTnWay(string str1 , string str2 , int s1,int s2 , int l , int m)
{
	//base case
	if (s1==l && s2==m)
	{
		return 1;
	}
	if (s1==l)
	{
		return 0;
	}
	if (s2==m)
	{
		return 1;
	}
	long long int ans=0;
	if(str1[s1]!=str2[s2])
	{
		ans=geTnWay(str1 , str2 , s1+1 , s2 , l ,m);
	}else{
		int opt1=geTnWay(str1 , str2 , s1+1 ,s2 , l ,m);
		int opt3=geTnWay(str1 , str2 , s1+1 ,s2+1 , l ,m);
		ans=opt1+opt3;
	}
	return ans;
}
int main()
{
	string str1;
	cin>>str1;
	string str2="ROR";
	int l=str1.size();int m=str2.size();
	cout<<geTnWay(str1 , str2 , 0 , 0 ,l , m);
}