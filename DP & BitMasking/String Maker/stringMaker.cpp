#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int getAnswer(string a ,string b , string c , int l ,int m , int n)
{
if (n<0)
{
    return 1;
}
int nWay=0;
        //for a
        for(int k=l ; k>=0 ; k--)
        {
            if (c[n]==a[k])
            {
                nWay +=getAnswer(a, b, c, k-1 , m , n-1);
            }
        }
        //for b
        for(int k=m ; k>=0 ; k--)
        {
            if (c[n]==b[k])
            {
                nWay+=getAnswer(a, b, c, l ,k-1 ,n-1);
            }
        }
return nWay;
}
int solve(string a,string b,string c)
{
	int l=a.size(),m=b.size(),n=c.size();
	return getAnswer(a , b ,c , l-1 , m-1 , n-1);
}
int main()
{
	string a,b,c;
	cin>>a>>b>>c;
	cout<<solve(a,b,c)<<endl;
}