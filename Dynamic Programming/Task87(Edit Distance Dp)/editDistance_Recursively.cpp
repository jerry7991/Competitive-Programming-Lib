#include <iostream>
#include <cstring>
using namespace std;
int editDistance(char *s1, char *s2) 
{
	//base case 1:-
	if(s1[0]=='\0' && s2[0]!='\0')
	{
		return strlen(s2);
	}
	//base case 2:-
	if (s1[0]!='\0' && s2[0]=='\0')
	{
		return strlen(s1);
	}
	// base case 3:-
	if (s1[0]=='\0' && s2[0]=='\0')
	{
		return 0;
	}
	if(s1[0]==s2[0])
	{
		return (editDistance(s1+1 , s2+1));
	}
	//now we have 3 choice
	//option 1:-we can simply delete first character of s1;
	int option1=1+editDistance(s1+1 , s2);
	//option 2:-replace first character of s1 with first of s2..
	int option2=1+editDistance(s1+1 , s2+1);
	//option 3:-we insert first of s2 in front of s1;
	int option3=1+editDistance(s1 , s2+1);
	//and all above option which is min that's mine for particuler length of s1 and s2
	return (	min(option1 , min(option2 , option3)	)	);
}
int main()
{
	char s1[100],s2[100];
	cin>>s1>>s2;
	cout << editDistance(s1,s2) << endl;
	cout<<"\n Time complexity would be nearly O(3^N) due to highly duplicate function called.. we should reduce it\n";
	return 0;
}