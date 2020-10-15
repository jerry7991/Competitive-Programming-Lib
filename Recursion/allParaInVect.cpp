#include <iostream>
#include <vector>
using namespace std;
void getOutput(int n , int start , int differ , vector<string>* &output , string str)
{
	if(start==n)
	{
		output->push_back(str);
		//cout<<str<<endl;
		return;
	}
	if (differ==0)
	{
		getOutput(n ,start+1 , differ+1 , output , str+"(");
	}else if(differ==(n-start)){
		while(differ!=0)
		{
			str+=")";
			differ--;
		}
		getOutput(n , n  ,  0 , output ,str);
	}else{
		getOutput(n , start+1 , differ+1 , output , str+"(");
		getOutput(n , start+1, differ-1 , output ,str+")");
	}
}
vector<string>* findParenthesis(int n)
{
    vector<string> *output=new vector<string>();
    getOutput(2*n , 0 , 0 , output , "");
    return output;
}
int main()
{
	int n;
	cin>>n;
	vector<string>*output=findParenthesis(n);
	for (int i = 0; i < output->size(); ++i)
	{
		string str=output->at(i);
		cout<<str<<endl;
	}
}