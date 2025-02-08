#include<iostream>
using namespace std;
template<class T>
class ArrayStack{
	private:
		int length=5;
		int top = -1;
		T stack[5];
	public:
		bool isFull(){
			return top == length - 1;
		}
		bool push(T value){
			if(isFull())return false;
			top++;
			stack[top]=value;
			return true;
		}
		
		bool pop(){
			if(!isEmpty()){
				top--;
				return true;
			}else return false;
		}
		bool isEmpty(){
			return top ==-1;
		}
		T peek(){
			if(isEmpty())return T();
			else return stack[top];
		}
		int size(){
			return top +1;
		}
		int len(){
			return length;
		}
		
};
int main() 
{
	ArrayStack<int> S;
		cout<<S.peek()<<endl;
	cout<<S.isEmpty()<<endl;
	cout<<S.isFull()<<endl;
for(size_t i =1;i<=5;i++){
		cout<<S.push(10*i)<<endl;
	}
	cout<<S.peek()<<endl;
	cout<<S.size()<<endl;
	cout<<S.pop()<<endl;
	cout<<S.len()<<endl;
	cout<<S.isEmpty()<<endl;
	return 0;
}