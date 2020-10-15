#include <iostream>
using namespace std;
bool isPowerOf10(int n)
{
    int count=0;
    while(n)
    {
        count+=n%10;
        n=n/10;
    }
    return count==1;
}
int countOfNumbers(int n)
{
	
    int x=n-1;
    //check weather n is power of 10 or not
    bool isPower=isPowerOf10(n);
    int count=0;
    while(x)
    {
        count++;
        x/=10;
    }
    int ans=1;
    while(count)
    {
        ans*=2;
        count--;
    }
    if(!isPower)	ans--;
    return ans;
}

int main()
{
	int n;
	cin>>n;
	cout<<countOfNumbers(n);
}