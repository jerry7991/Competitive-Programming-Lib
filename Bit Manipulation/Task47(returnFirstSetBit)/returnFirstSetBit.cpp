#include <bits/stdc++.h>
using namespace std;
int returnFirstSetBit(int n)
{
    if(n==0)
        return 0;

    int i=0;
    while(n%2==0)
    {
        n /=2;
        i++;
    }
    return pow(2, i);
    //very efficient
    //return n & (-1*n);
}
int main() {
	int n;

	cin >> n;

	cout<< returnFirstSetBit(n) <<endl;

	return 0;
}


