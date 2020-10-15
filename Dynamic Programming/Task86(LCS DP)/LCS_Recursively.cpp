#include <iostream>
#include <cstring>
using namespace std;
int lcs(char * s1 , char * s2)
{
	if(s1[0]=='\0' || s2[0]=='\0')
		return 0;	//i.e. 0 subsequence possible
	//other wise we have two condition
	//1.weather the first element of both string same or not
	//First condition:-
	if (s1[0]==s2[0])
	{
		return( 1+lcs(s1+1 , s2+1) );
	}else{
		//we have two option
		//one is either sub sequence start with s2[0]
		int option1=lcs(s1 , s2+1);	
		//second is either sub sequence start with s1[o]
		int option2=lcs(s1+1 , s2);
		//now return which subsequence have maximum
		return	(	(option1>option2)? option1 :option2	);
	}
}
int main(){

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  char *s=new char[s1.length()];
  char *sb=new char[s2.length()];
  for(unsigned int i=0 ; i<s1.length() ; i++)
  {
  	s[i]=s1[i];
  }
  for(unsigned int i=0 ; i<s2.length() ; i++)
  {
  	sb[i]=s2[i];
  }
  cout<<lcs(s,sb)<<endl;
  cout<<"\n But time complexity=O(2^N) due to many duplicate element.. Increa input size >20 and look what will happen\n";
  return 0;
}
