#include <iostream>
using namespace std;
int turnOffIthBit(int n, int i)
{
       //first find the i-th bit and make it 1 and rest of 0
       //left shift i-times it give also as 2^i;
    int i_th_bit=1<<i;

    //question has given a number with i ,  at i-th bit which we will have to remove if we are getting 1 then set it 0 else nothing have to do
    // so first ~ the i_th_bit for which  i-th bit become 0 and rest of 1
    // and now make it & so at the i-th either 0 or 1 present i-th reset as 0; because  1 & 0 = 0;
    int ans=  n & (~ i_th_bit );
    return ans;
}
int main() {
	int n, i;

	cin >> n >> i;

	cout<< turnOffIthBit(n, i) <<endl;

	return 0;
}


