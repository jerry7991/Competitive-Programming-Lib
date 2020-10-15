package myPackage.priorityQueue;
import java.util.*;
public class Max_PriorityQueue<T>{
	private ArrayList<Element<T>> heap;
	public Max_PriorityQueue(){
		heap=new ArrayList<Element<T>>();
	}
	//let's define all the functionalities for Max_PriorityQueue
	public void insert(T value , int priority){
		//insert at the end
		Element<T> newElement=new Element<T>(value , priority);
		heap.add(newElement);
		int child=heap.size()-1;
		int parent=(child-1)/2;
		//let's heapify bottum up
		while(child>0){
			if(heap.get(parent).priority > heap.get(child).priority) break;//everything is fine
			//swap with parent to child
			Element<T> temp=heap.get(child);
			heap.set(child , heap.get(parent));
			heap.set(parent, temp);
			child=parent;//now our parent become child for next iteration
			parent=(child-1)/2;//and now parent become grandparent of older child
		}
	}
	public T removeMax() throws PriorityQueueException{
		if(isEmpty()) throw new PriorityQueueException();
		//we are allowed to delete only from last to copy last element to the first 
		//and delete last element and perform maxHeapify
		T removed=heap.get(0).value;
		heap.set(0  , heap.get(heap.size()-1));
		//now erase heap last element
		heap.remove(heap.size()-1);
		int parent=0;
		int lChild=parent*2+1;
		int rChild=parent*2+2;
		while(lChild<heap.size()){
			int maxIndex=parent;
			if(heap.get(maxIndex).priority < heap.get(lChild).priority){
				maxIndex=lChild;
			}
			if(heap.get(maxIndex).priority < heap.get(rChild).priority){
				maxIndex=rChild;
			}
			//now if maxIndex didn't change the we don't need to again maxHeapify
			if(maxIndex==parent)	return removed;
			//otherwise swap between maxIndex and parent
			Element<T>temp=heap.get(maxIndex);
			heap.set(maxIndex  , heap.get(parent));
			heap.set(parent ,temp);
			//now our maxIndex will become parent for next iteration
			parent=maxIndex;
			lChild=maxIndex*2+1;
			rChild=maxIndex*2+1;
		}
		return removed;
	}
	public T getMax() throws PriorityQueueException{
		if(isEmpty()) throw new PriorityQueueException();
		//otherwise 0th index has max value
		return heap.get(0).value;
	}
	public int size(){
		return heap.size();
	}
	public boolean isEmpty(){
		return (heap.size()==0);
	}
}