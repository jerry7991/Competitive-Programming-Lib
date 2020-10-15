#include <iostream>
#include <string>
using namespace std;
int countMinStep(string str1 ,string str2 , int l ,int m)
{
	if(str1[l]=='\0' && str2[m]=='\0')
		return 0;
	if (str1[l]!='\0' && str2[m]=='\0')
	{
		return(str1.size()-l);
	}
	if (str1[l]=='\0' && str2[m]!='\0')
	{
		return (str2.size()-m);
	}
	if(str1[l]==str2[m])
	{
		return countMinStep(str1 , str2 , l+1 , m+1);
	}else{
		//we have 3 option
		//option 1 delete a char
		int option1=1+countMinStep(str1 , str2 , l , m+1);
		//replace a char with another one
		int option2=1+countMinStep(str1,str2,l+1,m+1);
		//insert a char in str2
		int option3=1+countMinStep(str1 , str2 , l+1 ,m);
		return min(option1 , min(option2,option3));
	}
}
int main()
{
	string str1,str2;
	cin>>str1;
	cin>>str2;
	cout<<countMinStep(str1 ,str2 , 0 , 0);
}