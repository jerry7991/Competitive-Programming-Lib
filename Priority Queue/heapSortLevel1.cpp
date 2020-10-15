#include <iostream>
using namespace std;
void bottumUpMinHeapify(int *heap , int start , int end)
{
	int child=end;
	int parent=(child-1)/2;
	while(child>0){
		if (heap[parent]>heap[child])
		{
			swap(heap[parent] , heap[child]);
		}else{
			return;
		}
		child=parent;
		parent=(child-1)/2;
	}
}
void topDownHeapify(int *heap , int end){
	int parent=0;
	int lChild=parent*2+1;
	int rChild=parent*2+2;
	while(lChild<end){
		int minIndex=parent;
		if(heap[minIndex]>heap[lChild]){
			minIndex=lChild;
		}
		if(rChild<end && heap[minIndex]>heap[rChild]){
			minIndex=rChild;
		}
		if(minIndex==parent){
			//i.e. everthing is ok no need to further heapify cause if parent is greater then
			//child of parent will also be greater
			return;
		}
		//swap parent with minIndex
		swap(heap[parent] , heap[minIndex]);
		//next parent will be modified minIndex
		parent=minIndex;
		//left child
		lChild=parent*2+1;
		rChild=parent*2+2;
	}
}
void HeapSort(int *arr , int n){
	int *heap=new int[n];
	//now insert one by one elemenet in heap from arr
	for (int i = 0; i < n; ++i)
	{
		heap[i]=arr[i];
		//and after adding each element we need to min-Heapify
		bottumUpMinHeapify(heap , 0 , i);
	}
	for (int i = 0; i < n; ++i)
	{
		cout<<heap[i]<<" ";
	}
	cout<<endl;
	//and now delete max heap and store it till the last element
	int i=0,hLen=n;//hLen==i.e. heapLength
	while(hLen && i<n){
		arr[i++]=heap[0];
		heap[0]=heap[hLen-1];
		hLen--;
		topDownHeapify(heap , hLen);
	}
}
int  main()
{
	int n;
	cin>>n;
	int *arr=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	HeapSort(arr , n);
	cout<<"Sorted Array is"<<endl;
	for(int i=0 ; i<n ; i++)	cout<<arr[i]<<endl;
	cout<<"Algorithm  used O(N) space complexity and nearly O(N) time complexity"<<endl;
	delete []arr;
return 0;
}