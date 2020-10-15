#include <iostream>
using namespace std;
void bottumUpMaxHeapify(int *heap , int n){
	int child=n;
	int parent=(child-1)/2;
	while(child>0){
		if(heap[parent]>heap[child])	return;
		swap(heap[parent] , heap[child]);
		child=parent;//now curr parent become child and grand parent become parent
		parent=(child-1)/2;
	}
}
void topDownMaxHeapify(int *heap , int end){
	int parent=0;
	int lChild=parent*2+1;
	int rChild=parent*2+2;
	while(lChild<end){
		int maxIndex=parent;
		if(heap[maxIndex]<heap[lChild])	maxIndex=lChild;
		if(rChild<end && heap[maxIndex]<heap[rChild])	maxIndex=rChild;
		if(maxIndex==parent)//nothing changed.... all right just return
			return;
		//else swap
		swap(heap[parent] , heap[maxIndex]);
		parent=maxIndex;
		lChild=parent*2+1;
		rChild=parent*2+2;
	}
}
void heapSort(int *arr ,int n){
	//we alocate within arr..
	//i-th index explore that till the i-th index all element is in heap.. and rest of out of heap
	for (int i = 1; i < n; ++i)
	{
		//we have inserted element of index 1 into heap[i0,]--> hea[i0,i1];
		//now need to heapify i.e. bottumUp
		bottumUpMaxHeapify(arr , i);
	}
	//now we are deleting each element for start i.e. maxElement replace with end and perform
	//topdownHeapify
	while(n){
		swap(arr[0] , arr[n-1]);
		n--;
		topDownMaxHeapify(arr , n);
	}
}
int main(){
	int n;
	cin>>n;
	int *arr=new int[n];
	for (int i = 0; i < n; ++i) cin>>arr[i];
	heapSort(arr , n);
	for(int i=0 ; i<n ; i++) cout<<arr[i]<< ' ';
	delete []arr;
return 0;
}