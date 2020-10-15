#include <iostream>
using namespace std;
int getMinDistanceII(int x , int y){
	//first basic voilate condition
	if(min(x,y)<=0) return INT_MIN;//-ve infinite
	/*
		In prev optmizeLevelI implimentation we have stored all the ancestors of x and y so space complexity
		was O(log(max(x,y))) but if we analyse that solution so we are just finding the common ancestor
		i.e any value k such that it is ancestor of both so we can do this like as we did in heap while heapifing we are going
		to parent by getting flor(x/2);
		so we will keep deviding by 2 to max(x,y) until it become equal
	*/
	int distance=0;
	if(x<y){
		//swap because we are going to assume that x always be greater then or equal to y
		int temp=x;
		x=y;
		y=temp;
	}
	while(x!=y){
		//we are know that while loop terminate because 1 is root of all node and at worst case we meet at one
		distance++;//each time distance increases by one
		if(x>y){
			x/=2;
		}
		if(y>x){
			y/=2;
			distance++;
			//we got one more uncommon ancestor
		}
	}
	//now this algorithm is with time O(log(max(x,y))) we can say depth of tree and tree always be balanced
	//and space is O(1) we are not using any extra space
	return distance;
}
int main(){
		int x,y;
		cin>>x>>y;
		cout<<getMinDistanceII(x,y)<<'\n';
}