#include <bits/stdc++.h>
#define ff(i,n) for(int i=0;i<n;i++)
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string s,p;
	    cin>>s>>p;
	    map<char,int>m1;
	    map<char,int>m2;
	    bool flag=0;
	    for(int i=97;i<123;i++)
        {
            char d=i;
               m1[d]=0; m2[d]=0;
        }
	    ff(i,s.size())
	    m1[s[i]]++;
	    ff(i,p.size())
	    m2[p[i]]++;
	    char c;
        for(int i=1;i<p.size();i++)
        {
            if(p[i]>p[0])
            {
                flag=1;
                break;
            }
            if(p[i]<p[0])
            {
                flag=0;
                break;
            }
            if(i==p.size()-1)
            {
                flag=0;
                break;
            }
        }
	    for(int i=97;i<123;i++)
        {
             c=i;
            m1[c]-=m2[c];
        }
        string ana="";
        string temp="";
            for(int j=97;j<123;j++)
            {
                 c=j;
                 if(flag==0 && c==p[0])
                     ana=ana+p;
                 while(m1[c]--)
                    temp=temp+c;
                 ana=ana+temp;
                 temp="";
                 if(flag==1 && c==p[0])
                    ana+=p;
            }
        cout<<ana<<endl;
	}
}