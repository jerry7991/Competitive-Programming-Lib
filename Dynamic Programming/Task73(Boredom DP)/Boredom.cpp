#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
int n;
vector<int>A;
map<int,int>frequency;
int solve(int n,vector<int>A)
{
    vector<int>nonDuplicat;
    set<int>s;
    vector<int>::iterator itr;
    for(itr=A.begin()   ;   itr!=A.end()    ;   itr++)
    {
       frequency[(*itr)]++;
       //store nonDuplicate element
       if(s.find((*itr))==s.end())
       {
           s.insert(*(itr));
           nonDuplicat.push_back(*(itr));
       }
    }
    /*
    check weather frequency stored or not
    map<int,int>::iterator m;
    for(m=frequency.begin() ; m!=frequency.end() ; m++)
    {
        cout<<m->first<<"   ->  "<<(*m).second<<endl;
    }
    */
    int *output=new int[n+1];
    output[0]=nonDuplicat[0];
    output[1]=nonDuplicat[1]*frequency[nonDuplicat[1]];int i;
    for(i=2 ; i<nonDuplicat.size() ; i++)
    {
        output[i]=  max(  output[i-2]+nonDuplicat[i]*frequency[nonDuplicat[i]] ,output[i-1] );
        cout<<output[i]<<endl;
    }
    return output[i-1];
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		A.push_back(x);
	}
	cout<<solve(n,A)<<endl;
}
