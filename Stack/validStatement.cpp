#include <iostream>
#include <cstring>
#include <stack>
#define fon(i,n) for(int i=0 ; i<n ; i++)
using namespace std;
bool isValidArray(string str,int len)
{
	char * array=new char[len];
	fon(i , len) array[i]='\0';
	int top=0;
	char  stOpen[3]={'(','{','['};
	char stClose[3]={')','}',']'};
	fon(i,len)
	{
		char curr=str[i];
		if (curr=='{' || curr=='(' || curr=='[')
		{
			array[top++]=curr;
		}else if(curr=='}' || curr==')' || curr==']')
		{	
			char topElement=array[top-1];
			int closeIndex=-1;
			fon(j,3)
			{
				if(stOpen[j]==topElement) 
					{
						closeIndex=j ; 
						break;
					}
			}
			if (stClose[closeIndex]==curr)
			{
				array[top-1]='\0';top--;
			}else{
				 return false;
			}
		}
	}
	fon(i,len)
	{
		if(array[i]!='\0')
			return false;
	}
	return true;
}
bool isValid(string str, int len)
{
	stack<char> st;
	char  stOpen[3]={'(','{','['};
	char stClose[3]={')','}',']'};
	fon(i,len)
	{
		char curr=str[i];
		if (curr=='{' || curr=='(' || curr=='[')
		{
			st.push(curr);
		}else if(curr=='}' || curr==')' || curr==']')
		{	
			char topElement=st.top();
			int closeIndex=-1;
			fon(j,3)
			{
				if(stOpen[j]==topElement) 
					{
						closeIndex=j ; 
						break;
					}
			}
			if (stClose[closeIndex]==curr)
			{
				st.pop();
			}else{
				return false;
			}
		}
	}
	if(st.size()!=0)
	{
		return false;
	}
return true;
}
int main()
{
	string statement;
	getline(cin,statement);
	bool answer=isValid(statement , statement.size()) && isValidArray(statement , statement.size()); 
	if(answer)
	{
		cout<<"Valid";
	}else{
		cout<<"Invalid";
	}
}