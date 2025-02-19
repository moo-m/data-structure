#include<iostream> 
using namespace std;
template<typename T>
class Queue{
	private:
		int size;
		T*queue;
		int front=0;
		int rear = -1;
		int count = 0;
	public:
		Queue(int length):size(length){
			queue=new T[size];
		};
		bool isFull(){
			return count == size;
		}
		bool isEmpty(){
			return count == 0;
		}
		bool enqueue(T value){
			if(!isFull()){
				rear=(rear+1)%size;
				queue[rear]=value;
				count++;
				return true;
			}else{
				 cout<<"queue is full"<<endl;
				 return false;
			}
		}
		T dequeue(){
			if(!isEmpty()){
				T temp = queue[front];
				queue[front]=T();
				front=(front+1)%size;
				count--;
				return temp;
			}else {
				cout<<"queue is empty"<<endl;
				return T();
			}
		}
		T getFront(){
			if(!isEmpty()){
				return queue[front];
			}else return T();
		}
		T getRear(){
			if(!isEmpty()){
				return queue[rear];
				
			}else return T();
		}
		int getSize(){
			return count;
		}
		void clear(){
			while(count>0){
				queue[front]=T();
				front=(front+1)%size;
				count --;
			}
		}
		~Queue(){
			delete[]queue;
		}
	}; 
int main()
{
	Queue<int>q{4};
	cout<<"size = "<<q.getSize()<<endl;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.dequeue();
		cout<<"siz= "<<q.getSize()<<endl;
	cout<<q.getFront()<<endl;
	cout<<q.getRear()<<endl;
	return 0;
}