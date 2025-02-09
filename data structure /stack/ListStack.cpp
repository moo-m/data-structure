#include<iostream>
using namespace std;

template<class T>
class ListStack{
	private:
		struct Stack{
			Stack* prev = nullptr;
			T element = T();
		};
		Stack* top = nullptr;

	public:
		void push(T element){
			Stack* newStack = new Stack;
			newStack->element = element;
			newStack->prev = top;
			top = newStack;
		}
		
		bool pop(){
			if (top) {
				Stack* temp = top;
				top = top->prev;
				delete temp;
				return true;
			} else {
				return false;
			}
		}
		
		T peek(){
			if (top) {
				return top->element;
			} else {
				return T(); 
			}
		}
		
		void print(){
			Stack* toPrint = top;
			while (toPrint) {
				cout << toPrint->element << endl;
				toPrint = toPrint->prev;
			}
		}
		
		~ListStack(){
			while (top) {
				Stack* temp = top;
				top = top->prev;
				delete temp;
			}
		}
};

int main() 
{
	ListStack<int> S;
	S.push(1);
	S.push(2);
	S.push(3);
	S.pop();
	cout << "top is -> " << S.peek() << endl;
	S.print();
	return 0;
}
