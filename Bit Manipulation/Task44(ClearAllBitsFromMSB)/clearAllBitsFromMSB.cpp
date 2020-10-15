#include <iostream>
using namespace std;
int clearAllBits(int n , int i)
{
    //first find the position of i-th
    // 1<<i provide the position of i-th bits
    //make i-th position 1 and rest of 0
    int i_th_term=1<<(i);

    //subtract 1 from above value now current value have only 1s from i-th position to 0-th position
    i_th_term = i_th_term-1;//all contains once from i-th to 0th bits

     //make ~ of above value , now current value have only 1s from M.S.B. to i-th position
    int negatiate_term= ~ (i_th_term);

    //remove all once from LSB to i-th position
    int clearAllFromLSB= n & negatiate_term;
    // now clearAllFromLSB have 0 from i-th to 0-th position and from M.S.B. to i-th position is same as n;

     // so, X-OR [given Number(from M.S.B. to i-th position) ^ clearALLFromLSB(from M.S.B. to i-th position)]
    //above line makes 0 from M.S.B. to i-th position because from M.S.B. to i-th position all value will be same as in derived value (clearAllFromLSB)  and as in given number
    //and if we are able to find the a bit as a 1 then X-OR make it 0 other wise no change.... And from i-th to M.S.B.  position derived has 0 so no affect of EX-OR
   // and from i-th to 0-th position X-OR make copy of n in clearALLFromMSB because clearALLFromLSB have 0 from i-th to 0-th position
   // so in general X-OR works like -
   /*
        X^0 = X;
        X^1 = ~X;
   */
    int clearAllFromMSB=  n ^ clearAllFromLSB;
    return clearAllFromMSB;


    /*in single line
    return (n^(n & ( ~ ( (1<<i)-1) ) ) );
    */
}
int main() {
	int n, i;

	cin >> n >> i;

	cout<< clearAllBits(n, i) <<endl;

	return 0;
}

