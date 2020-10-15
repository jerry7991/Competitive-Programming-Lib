#include <iostream>
using namespace std;
int turnOffFirstSetBit(int n)
{
    //first find once compliment
    /* e.g n=12;
    n= 1 1 0 0
    */
    int once_compliment= ~n;
    /*
        Once_compliment=0 0 1 1
    */
    //find tows_compliment
    int tows_compliment= once_compliment+1;
    /*
        tows_compliment= 0 0 1 1
                                                +1
                                          0 1 0 0
    */

    // n & tows _compliment return the first set Bit
    /*
        first set bit =
                            1 1 0 0
                        &  0 1 0 0
    first set bit =    0 1 0 0
    */
    int first_set_bit=n & tows_compliment;

    //subtract first_set_bit from number and output will be the number where first set bit from n will be absent
    /*
    ans=
            1 1 0 0
        -   0 1 0 0
    ans=1 0 0 0 (12-4=8)
    */
    return (n-first_set_bit);
}
int main() {
	int n;

	cin >> n;

	cout<< turnOffFirstSetBit(n) <<endl;

	return 0;
}


