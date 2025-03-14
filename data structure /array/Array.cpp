#include <iostream>
using namespace std;

template <typename T>
class Array
{
  private:
	int length;
	int index = -1;
	T *space;

  public:
	Array(int size) : length(size),
					  space(nullptr)
	{
		if (!size)
			throw "\
		array length must be up than zero";
		space = new T[length];
	};
	T &operator[](int i)
	{
		if (i >= 0 && i <= index)
			return space[i];

		throw out_of_range("Index out of range");
	}
	/*
	display the elements.
	*/
	void display(string title)
	{
		cout << "\n-----------------------  " << title << "  -----------------\n";
		cout << "\t-> [ ";
		for (size_t i = 0; i <= index; i++)
		{
			cout << space[i];
			if (i != index)
				cout << " , ";
		}
		cout << " ]";
		cout << "\n-------------------  END " << title << "  -------------------\n";
	}

	/*
            Basic array operators      
1- pop -> remove the last element from the array and return it .

2- push -> add an element to end of the array and return the new size .

3- shift -> remove the first element from the array and return it .
 
4- unshift -> add an element to start of the array and return the new size .

5- insert -> insert an element at spicific index.
					(modifi original array).
					
6- remove -> remove  an element at spicific index.
 					(modifi original array).
*/

	int pop()
	{
		if (index > -1)
		{
			T temp = space[index];
			space[index] = T();
			index--;
			return temp;
		}
		else
			throw "Array is already empty";
	}

	int push(T value)
	{ //[ 0 , 1 , 2 ]
		if (index < length - 1)
		{
			space[++index] = value;
			return index + 1;
		}
		else
		{
			throw "Array is full!";
		}
	}

	T shift()
	{
		if (index >= 0)
		{ // i = 2; c = 1 ; [ 0 ];
			T temb = space[0];
			for (int i = 0; i <= index; i++)
			{
				space[i] = space[i + 1];
			}
			space[index] = T();
			index--;
			return temb;
		}
		else
		{
			throw "Array is already empty";
		}
	}

	int unshift(T value)
	{
		if (index < length - 1)
		{ //[ 1 , 2 , - ]   i=0;
			for (int i = index; i >= 0; i--)
			{
				space[i + 1] = space[i];
			}
			space[0] = value;
			return ++index;
		}
		else
		{
			throw "Array dose not has any extra spaces";
		}
	}

	bool insert(int index ,T value)
	{
		if(this->index<length&&index<length&&index>=0){
		for(int i = this->index;i>=index;i--)
		{
			space[i+1]=space[i];
		}
		space[index]=value;
		this->index++;
		}else return false;
		
		return true;
	}
	
	bool remove(int index )
	{
		if(index<length&&index>=0){
		for(int i = index;i<this->index;i++)
		{
			space[i]=space[i+1];
		}
		this->index--;
		}else throw out_of_range("array is full");
		
		return true;
	}
	/*
			search methods
1- indexOf -> return the index of an element 
				(if the element dose not found return -1)
				(start search from begin).
2- lastIndexOf -> return the index of an element 
				(if the element dose not found return -1)
				(start search from end).
3- includes -> chick if an element exists
				(return boolean value).
4- find -> return the first element matching.
				( cb ).

5- findIndex -> return the index of the first element matching.
				( cb ).
*/

	int indexOf(T element)
	{
		for (size_t i = 0; i <= index; i++)
		{
			if (space[i] == element)
				return i;
		}
		return -1;
	}

	int lastIndexOf(T element)
	{
		for (size_t i = index; i >= 0; i--)
		{
			if (space[i] == element)
				return i;
		}
		return -1;
	}

	int includes(T element)
	{
		for (size_t i = 0; i <= index; i++)
		{
			if (space[i] == element)
				return true;
		}
		return false;
	}

	T find(bool (*cb)(T ele))
	{
		for (size_t i = 0; i < length; i++)
		{
			if (cb(space[i]))
				return space[i];
		}
		cout << "element not found\n";
		return T();
	}

	int findIndex(function<bool(T ele)> cb)
	{
		for (size_t i = 0; i < length; i++)
			if (cb(space[i]))
				return i;

		return -1;
	}

	/*
			Transformation Methods
1- map -> transform elements and return a new array.
			( cb ).
2 - filter -> return a new array with items that pass the condetion;
			(cb).
*/
	template <class V>
	Array<V> map(V (*cb)(T))
	{
		Array<V> newArray(length);
		for (int i = 0; i <= index; i++)
		{
			newArray.push(cb(space[i]));
		}
		return newArray;
	}
	template <class V>
	Array<V> filter(bool (*cb)(T))
	{
		Array<V> newArray(length);
		for (int i = 0; i <= index; i++)
		{
			if (cb(space[i]))
				newArray.push(space[i]);
		}
		return newArray;
	}

	/*  
          Sorting and Ordering
1- sort -> sort the array on numbers and char.
		( rank ) if rank == 1 ranked ascending
		             or ranke == -1 descending.
2- reverse -> revers the array has numbers and chars.
		*edited the array*	
*/
	//Big O(n^2)
	void sort(int rank)
	{
		if (!(rank == 1 || rank == -1))
		{
			throw " sort ( rank ) \n \t-> rank must be 1 to ascending \n\t-> or -1 to descinding";
		}
		for (int i = 0; i < index; i++)
		{
			bool swapped = false;
			for (int j = 0; j < index - i; j++)
			{
			//	display("test");
				if (rank * ((int)space[j] - (int)space[j + 1]) > 0)
				{
					T temp = space[j];
					space[j] = space[j + 1];
					space[j + 1] = temp;
					swapped = true;
				}
			}
			if (!swapped)
				break;
		}
	}
	void reverse()
	{
		for(size_t i=0;i<=int(index/2);i++)
		{
			T temp = space[i];
			space[i]=space[index-i];
			space[index-i]=temp;
		}
	}
	
	/*
			Slicing and Splicing
1 - slice -> slice part of array and return it.
					(int start , int end).
					end not included.
2- splice -> remove spicific element from array and add.
					(int start , int lemit, T value).
					(end not include)
					(modify the original array).
	*/
	template<class V>
	Array<V> slice(int start,int end)
	{
		if(start>end&&start!=end)
		{
			int temp=start;
			end=start;
			start=temp;
		}
		Array<V> temp(end-start);
		for(;start<end;start++)
		{
			temp.push(space[start]);
		}
		return temp;
	}
	void splice(int start,int lemit , T value=T())
	{
		if(start+lemit<length&&lemit>=0)
		{
			for(int i = 0;i<lemit;i++)
			{
				remove(start);
			}
		if(value)
		{
			insert(start,value);
		}
		}else throw out_of_range("index largger than the length of the array");
		
	}
	
	/*
			Utility and Conversion
1- size -> return the size of the array.

2- capacity -> return how much element on the array.

3- join -> merage tow array.
				(modify the array).
				
	*/
	
	int size()
	{
		return length;
	}
	int capacity()
	{
		return index;
	}
	Array<T> join(Array<T>&otherArray)
	{
	Array<T> temp(length+otherArray.size());
	for(int i=0;i<=capacity();i++)
		{
			temp.push((*this)[i]);
		}
		for(int i=0;i<=otherArray.capacity();i++)
		{
			temp.push(otherArray[i]);
		}
		return temp;
	}
	
	~Array()
	{
		delete[] space;
		space = nullptr;
	}
};

int main()
{
	Array<char> A(20),B(5);
	A.push('A');
	A.push('C');
	A.push('B');
	A.push('E');
	A.insert(2,'F');
	B.push('G');
	B.push('H');
	B.push('I');
	B.push('J');
		//A.shift();
		//	cout<<"pop->"<<A.pop()<<endl;
	A.unshift('D');
		cout
		<< "\n--------------------------------------------\n";
	cout << A.indexOf('C') << endl;
	cout << A.lastIndexOf('C') << endl;
	cout << A.includes('A') << endl;
	cout << "find it -> " << A.find([](char ele) -> bool {
		return (char)ele == 65;
	}) << endl;
	cout << "index is -> " << A.findIndex([](char ele) -> bool {
		return (char)ele == 65;
	}) << endl;
	Array<char> arrM = A.map<char>([](char ele) {
		return char((int)ele + 32);
	});
	arrM.display("map");
	Array<char> arrF = A.filter<char>([](char ele) {
		return (int)ele >= 66;
	});
	arrF.display("filter");
	A.sort(1);
	A.display("sort");
	A.reverse();
	A.remove(2);
	A.splice(1,1,'B');
	A.display("reverse");
Array<char>C=A.join(B);
	C.display("join");

	Array<char> sliced=A.slice<char>(0,2);
	sliced.display("slice");
	return 0;
}
