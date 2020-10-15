#include <iostream>
using namespace std;
template <typename T> class Queue{
private:
	T *arr , front,rear,size;
public:
	Queue(int size){
		this->size=size;
		front=rear=0;
		arr=new T[size];
	}
	void add(T data){
		if((rear+1)%size==front){
			cout<<"overflow"<<endl;
			return;
		}
		arr[rear]=data;
		rear=(rear+1)%size;
	}
	T remove(){
		if(front==(rear+1)%size){
			cout<<"Underflow"<<'\n';
			return -1;
		}
		T ans=arr[front];
		front=(front+1)%size;
		return ans;
	}
	T getFront(){
		if(front==(rear+1)%size){
			cout<<"Underflow"<<'\n';
			return -1;
		}
		return arr[front];
	}
};
int main(){
	Queue<string> *q=new Queue<string>(5);
	Queue<int> *qt=new Queue<int>(5);
	Queue<float> *qf=new Queue<float>(5);
	Queue<double> *qb=new Queue<double>(5);
	Queue<char> *qc=new Queue<char>(5);
	while(true){
		int ch;
		cin>>ch;
		if(ch==0) return 0;
		else if(ch==1){
			cin>>ch;
			q->add(ch);
		}else if(ch==2){
			cout<<q->remove()<<endl;
		}else{
			cout<<q->getFront()<<'\n';
		}
	}
	return 0;
}