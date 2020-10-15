#include <iostream>
using namespace std;
uint32_t reverseBits(uint32_t n) {
    uint32_t x=0,j=31;
    for(int i=0 ; i<32  ; i++ , j--){
    	if(n & (1<<i)) x+=(1<<j);
    }
    return x;
}
int main(){
	unsigned int x;
	cin>>x;
	cout<<reverseBits(x);
}