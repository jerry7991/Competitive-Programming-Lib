#include <iostream>
#include <vector>
using namespace std;
void getAncestor(vector<int> &ans , int value){
	if(value==0) return;
	getAncestor(ans , value/2);

	//store parent while backtracking because we want to path as increasing and later we apply on binary search
	//otherwise have to reverse the path or have to change binary search algorithm(because then we have path in decreasing order)
	
	ans.push_back(value);
}
int isContain(int value , vector<int> &arr){
	//normal binary search
	int start=0,end=arr.size()-1;
	while(start<=end){
		int mid=(start+end)/2;
		if(arr[mid]==value){
			return mid;
		}else if(arr[mid]>value){
			//left side
			end=mid-1;
		}else{
			//right side
			start=mid+1;
		}
	}
	return -1;
}
int getMinDistance(int x , int y){
/*
	so in previous appraoch we are constructing tree which has O(max(x,y)) space . But we don't need to construct
	the tree instead of constructing the tree and getting path we store direct ancestor
	so if current node is x then it left child would be 2*i and right child would be 2*i+1 and if we look reverse 
	of this if current node is x then it's parent would be floor(x/2) as we did in heap to apply heapify	
*/
	vector<int> ancestorX;
	vector<int> ancestorY;
	getAncestor(ancestorX , x);
	getAncestor(ancestorY , y);
	/*
		so find first common ancestor , so start from end because in beginning  probabilities of getting number of
		common ancestor is height	 for example
		ancestorX {1,2,5} and ancestorY {1,2,4} so getting first common ancestor we have to binary search on 1 and 2
		and then when we call on 5/4 we get mismatched ancestor and get 2 as a last common ancestor but if we
		start from end then after calling at 2 we get first matched ancestor
	*/
	for(int i=ancestorX.size()-1 ; i>=0;i--){
		int x=isContain(ancestorX[i] , ancestorY);
		if(x!=-1){
			//we got first comman ancestor
			int distance=(ancestorX.size()-1-i)+(ancestorY.size()-1-x);
			return distance;
		}
	}
	return 0;
}
int main(){
	while(true){
		int x,y;
		cin>>x>>y;
		cout<<getMinDistance(x,y)<<'\n';
}