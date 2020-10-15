#include <iostream>
#include <vector>
using namespace std;
bool getPath(vector<int> &path , int *tree , int treeIndex , int &destination , int &maxLen){
	//base case
	if(treeIndex>maxLen){
		//we can not find the path
		return false;
	}
	if(tree[treeIndex]==destination){
		path.push_back(destination);
		return true;
	}
	bool isFound=false;
	isFound=getPath(path , tree , treeIndex*2 , destination , maxLen);
	if(isFound){

		//if there is path from current treeIndex to destination way left subtree then store tree[treeIndex]
		path.push_back(tree[treeIndex]);
		/*
			return true for which while backtracking we are able to know that we got a path and this is tree
			so it ensure that there must be a single path
		*/
		return isFound;
	}
	isFound=getPath(path , tree , treeIndex*2+1 , destination , maxLen);
	if(isFound){
		//if there is path from current treeIndex to destination way right subtree then store tree[treeIndex]
		path.push_back(tree[treeIndex]);
		return isFound;
	}
	return isFound;
}
int get_Min_Distance(int x , int y){

	//first and basic condition would be if any of x and y become <=0 then we can not find because
	//tree is starting from 1---->+ve infinite

	if(min(x,y)<=0) return INT_MIN;

	//if x and y is same then min distance would be 0 

	if(x==y) return 0;

	//we have to create a tree of max node==max(x,y)
	//so i'm here using tree into arr (as we did in Heap)

	int maxLen=max(x,y);
	int *tree=new int[maxLen+1];
	/*
		0-th node as dummy because if want to go left then index of root node of left subtree would be 2*i and for right
		2*i+1 so if parent would at be 0 then 2*i will always 0.. Or other way you can start with 0
		then for index of root of left subtree would be 2*i+1 and for right subtree 2*i+2;
	*/
	tree[0]=-1;
	for(int i=0 ; i<=maxLen ; i++){
		tree[i]=i;
	}
	//now we will store path of x from root node and path of y from root node
	
	vector<int>pathX;
	vector<int>pathY;
	getPath(pathX , tree , 1 , x , maxLen);
	getPath(pathY , tree , 1 , y , maxLen);
	/*
		now pathX has the path from root node to x and path y has the path from root node to y
		so for distance find the length of common ancestor and as we know we are storing path while backtracking
		so pathX and pathY has path from root node in reverse order i.e. path x to root and path y to root
	*/
	int lenCommonAnc=0;
	int i=pathX.size()-1 , j=pathY.size()-1;
	while(i>=0 && j>=0 && pathX[i]==pathY[j]){
		//increment common ancestor
		lenCommonAnc++;
		i--;j--;
	}
	/*
		so distance would be length of pathX and length of pathY and subtract 2*lenCommonAnc because common
		ancestor include two times one in path x and other in path
		e.g. pathX={5,2,1} pathY={4,2,1} where x=5 and y=4 so common ancestor included 2 times {2,1} in both
		path x and y
	*/
	int distance=pathX.size()+pathY.size()-2*lenCommonAnc;

	//release memory of tree since we have created it dynamically so it's our responsibilities to release
	delete []tree;
	return distance;
}
int main(){
	int x,y;
	cin>>x>>y;
	cout<<get_Min_Distance(x,y)<<endl;
}