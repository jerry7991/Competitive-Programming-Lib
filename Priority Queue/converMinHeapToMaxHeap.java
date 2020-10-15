import java.util.Scanner;
class converMinToMaxHeap{
	private static void downHeapify(int []heap ,int start , int end){
		int parent=start;
		int lChild=parent*2+1;
		int rChild=parent*2+2;
		while(lChild<end){
			int maxIndex=parent;
			if(heap[maxIndex]<heap[lChild])	maxIndex=lChild;
			if(rChild<end && heap[maxIndex]<heap[rChild])	maxIndex=rChild;
			if(maxIndex==parent)return;
			//swap
			int temp=heap[parent];
			heap[parent]=heap[maxIndex];
			heap[maxIndex]=temp;
			//now maxIndex will be parent
			parent=maxIndex;
			lChild=parent*2+1;
			rChild=parent*2+2;
		}
	}
	private static void convertMaxHeap(int arr[], int n) {
		for(int i=(n/2-1);i>=0 ; i--){
			downHeapify(arr , i, n);
		}
	}
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		int n=scan.nextInt();
		int []arr=new int[n];
		for (int i=0;i<n ;i++ ) {
			arr[i]=scan.nextInt();
		}
		convertMaxHeap(arr , n);
		for(int i=0 ; i<n ; i++)
		{
			System.out.print(arr[i]+" ");
		}
	}
}