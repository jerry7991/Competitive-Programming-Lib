#include <iostream>
using namespace std;
int countNumbersWithUniqueDigits(int n){
	if(n<1 ) return 1;
	int res=10;
	int uniqueDigit=9;
	int availabaleNumb=9;
	while(n-- >1 && availabaleNumb>0){
		uniqueDigit*=availabaleNumb;
		res+=uniqueDigit;
		availabaleNumb--;
	}
	return res;
}
int main(){
	int n;
	cin>>n;
	cout<<countNumbersWithUniqueDigits(n);
}