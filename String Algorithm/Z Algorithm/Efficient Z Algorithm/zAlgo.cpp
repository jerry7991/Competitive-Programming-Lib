#include <bits/stdc++.h>
#define fon(i , n) for(int i=0 ; i<n ; i++)
using namespace std;
void buildZ(int *Z,string str)
{
	int l=0,r=0;
	int n=str.length();
	for (int i = 1; i < n; ++i)
	{
		if(i>r)
		{
			l=i;
			r=i;
			while(r<n && str[r-l]==str[r]) r++;

			Z[i]=r-l;
			r--;
		}else{
			int k=i-l;
			if (Z[k]<=r-i)
			{
				Z[i]=Z[k];
			}else{
				l=i;
				while(r<n && str[r-l]==str[r]) r++;
				Z[i]=r-l;
				r--;
			}
		}
	}
}
void printOccurance(string str ,string pattern)
{
	int m=str.length();
	int n=pattern.length();
	string combined=pattern+"$"+str;
	int *Z=new int[n+m+1]();
	buildZ(Z,combined);
	fon(i , combined.length())
	{
		if (Z[i]==n)
		{
			cout<<i-n-1<<endl;
		}
	}
} 
int main()
{
	string str,pattern;
	cin>>str>>pattern;
	printOccurance(str , pattern);
}