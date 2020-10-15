#include<iostream>
#include<cmath>
using namespace std;
int minCount(int n )
{
    if(sqrt(n) - floor(sqrt(n)) == 0)
        return 1;
    if( n<=3)
        return n;
    int res=n;
    for (int x = 1; x <= n; x++) {
        int temp = x * x;
        if (temp > n)
            break;
        else
            res = min(res, 1 + minCount(n - temp));
    }
    return res;
}
int main()
{
    int number;
    cin>>number;
    int x=minCount(number );
    cout<<counter;
    return 0;
}
