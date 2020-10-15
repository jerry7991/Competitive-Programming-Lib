#include <iostream>
#include <string>
using namespace std;
int min1 = INT_MAX; 
int _count = 0; 
// Find all the possible permutation of Value A. 
int permutation(string str1, int i, int n, int p) 
{ 
    if (i == n) 
    { 
    	//we got a new permutated string 
        // Convert into Integer 
        int q = stoi(str1); 
  
        // Find the minimum value of A by interchanging 
        // the digit of A and store min1. 
        if (q - p > 0 && q < min1) 
        { 
            min1 = q; 
            _count = 1; 
        } 
    } 
    else
    { 
        for (int j = i; j <= n; j++) 
        { 
            // Swap two string character 
            swap(str1[i], str1[j]); 
            permutation(str1, i + 1, n, p); 
            //backtrack what i have done because we need original string while making permutation
            swap(str1[i], str1[j]); 
        } 
    } 
    return min1; 
} 
int main()
{
	string str1;int second;
	cin>>str1>>second;
	int answer=permutation(str1, 0,  str1.size()-1,  second) ;
	if (_count==1)
	{
		cout<<answer<<endl;
	}else{
		cout<<-1<<endl;
	}
}