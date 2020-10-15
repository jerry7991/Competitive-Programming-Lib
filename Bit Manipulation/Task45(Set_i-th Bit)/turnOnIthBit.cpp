#include <iostream>
using namespace std;
int turnOnIthBit(int n, int i)
{
    //first find the i-th bit and make it 1 and rest of 0
    int i_th_bit=1<<i;

    //make it Or operation with given number because or just add this bit to given number
    /* Normal Or works like :-

        X | 0 = X;
        X | 1 = 1;
    */
    int ans=i_th_bit | n;
    /*
    e.g.=
        n=4;    4 = 0 0 1 0 0     ;i=4;that's 5(4+1) because Counting of bits start from 0 from right to left.
        i_th_bit=   1 0 0 0 0
        ans        =   1 1 0 0 0 =20;
    */
    return ans;
    /*
    in single line
    return ( n | (1<<i));
    */
}
int main() {
	int n, i;

	cin >> n >> i;

	cout<< turnOnIthBit(n, i) <<endl;

	return 0;
}


