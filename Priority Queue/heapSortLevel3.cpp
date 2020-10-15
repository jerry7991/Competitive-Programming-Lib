//in this level we need not to do work on leafe
#include <iostream>
using namespace std;
void downHeapify(int *heap , int start , int end){
	int parent=start;
	int lChild=parent*2+1;
	int rChild=parent*2+2;
	while(lChild<end){
		int minIndex=parent;
		if(heap[minIndex]>heap[lChild]) minIndex=lChild;
		if(rChild<end  && heap[minIndex]>heap[rChild]) minIndex=rChild;
		if(minIndex==parent)return;
		swap(heap[minIndex] , heap[parent]);
		parent=minIndex;
		lChild=parent*2+1;
		rChild=parent*2+2;
	}
}
void heapSort(int *arr , int n){
	for(int i=(n/2-1) ; i>=0 ; i--){
		downHeapify(arr,i,n);
	}
	//remove one by one element and append it in the end
	while(n){
		swap(arr[0] , arr[n-1]);
		n--;
		downHeapify(arr ,  0 , n);
	}
}
int main(){
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0 ; i<n ; i++)cin>>arr[i];
	heapSort(arr , n);
	for(int i=0 ; i<n ; i++)cout<<arr[i]<<" ";
		cout<<endl;
	cout<<"Algorithm took O(N) time complexity and O(1) space complexity";
	delete []arr;
return 0;
}