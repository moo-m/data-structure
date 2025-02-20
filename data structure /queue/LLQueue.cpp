#include <iostream>
using namespace std;
template <typename T>
class Queue
{
  private:
	struct Node
	{
		T data;
		Node *next;
	};
	Node *front = nullptr;
	Node *rear = nullptr;
	int count = 0;

  public:
	bool isEmpty()
	{
		return count == 0;
	}
	T enqueue(T value)
	{
		Node *temp = new Node;
		temp->data = value;
		temp->next = nullptr;
		if (rear)
		{
			rear->next = temp;
		}
		else
		{
			front = temp;
		};
		rear = temp;
		count++;
		return value;
	}
	T dequeue()
	{
		if (!isEmpty())
		{
			T data = front->data;
			Node *temp = front;
			front = front->next;
			delete temp;
			count--;
			return data;
		}
		else
		{
			cout << "queue is empty" << endl;
			return T();
		}
	}
	T getFront()
	{
		if (!isEmpty())
		{
			return front->data;
		}
		else
			return T();
	}
	T getRear()
	{
		if (!isEmpty())
		{
			return rear->data;
		}
		else
			return T();
	}
	int getSize()
	{
		return count;
	}
	void clear()
	{
		while (front)
		{
			Node *temp = front;
			front = front->next;
			delete temp ;
		}
		rear=nullptr;
		count=0;
	}
	~Queue(){
		clear();
	}
};
int main()
{
    Queue<int> q;
    return 0;
}