package myPackage.priorityQueue;
import java.util.*;
class Element<T>
{
	T value;
	int priority;
	public Element(T value  , int priority)
	{
		this.value=value;
		this.priority=priority;
	}
}
class PriorityQueueException extends Exception{
	PriorityQueueException(){
		super();
	}
}
public class PriorityQueue<T>{
	private ArrayList<Element<T>> heap;
	//constructor
	public PriorityQueue(){
		heap=new ArrayList<Element<T>>();
	}
	//now some function which have to implement for PriorityQueue
	public void insert(T value , int priority){
		Element<T> e=new Element<T>(value , priority);
		//add new element in heap
		heap.add(e);
		int childIndex=heap.size()-1;//i.e. last element
		int parentIndex=(childIndex-1)/2;//cause of formulas
		//now let's do min heapiffy
		while(childIndex>0){
			if(heap.get(childIndex).priority < heap.get(parentIndex).priority){
				//need to swap
				Element<T> temp=heap.get(childIndex);
				heap.set(childIndex , heap.get(parentIndex));
				heap.set(parentIndex , temp);
				//now curr parentIndex will be child for next iteration of minHeapyfy
				childIndex=parentIndex;
				parentIndex=(childIndex-1)/2;
			}else{
				return;//cause all the parent of parentIndex element will be greater than curr child
			}
		}
	}
	public T removeMin() throws PriorityQueueException{
		if(isEmpty()) throw new PriorityQueueException();
		Element<T> removed=heap.get(0);
		T value=removed.value;
		heap.set( 0 , heap.get(heap.size()-1));
		heap.remove(heap.size()-1);
		int parentIndex=0;
		int lChildIndex=parentIndex*2+1;
		int rChildIndex=parentIndex*2+2;
		while(lChildIndex<heap.size())
		{
			int minIndex=parentIndex;
			if(heap.get(minIndex).priority > heap.get(lChildIndex).priority)
			{
				minIndex=lChildIndex;
			}
			if(rChildIndex<heap.size() && heap.get(minIndex).priority > heap.get(rChildIndex).priority)
			{
				minIndex=rChildIndex;
			}
			//finally our midIndex has the index which has min value among the root 
			//and left,right child... if minIndex==root i.e. no need heappify
			if(minIndex==parentIndex)
			{
				return value;
			}
			Element<T> temp=heap.get(minIndex);
			heap.set(minIndex , heap.get(parentIndex));
			heap.set(parentIndex , temp);
			parentIndex=minIndex;
			lChildIndex=parentIndex*2+1;
			rChildIndex=parentIndex*2+2;
		}
		return value;
	}
	public T getMin() throws PriorityQueueException{
		if(isEmpty())	throw new PriorityQueueException();
		//return the root node.... i.e. first element
		return heap.get(0).value;
	}
	public int size(){
		return heap.size();
	}
	public boolean isEmpty(){
		return (heap.size()==0);
	}
}
