// lab_7-5.cpp :

#include <iostream>

using namespace std;

template <typename T>
class Queue {
   
	struct Node {
		T value;
		Node* pNext;
	
		Node(T value, Node* pNext = nullptr) {
			this->value = value;
			this->pNext = pNext;
		}
	};

	Node *head;
	int size;
public:
	Queue(){
		size = 0;
		head = nullptr;
	}

	void pushBack(T value) {
		if (head == nullptr) {
			head = new Node(value);
		}

		else {
			Node* current = this->head;
			while (current->pNext != nullptr) {
				current = current->pNext;
			}

			current->pNext = new Node(value);
		}
		size++;
	}

	void popFront() {
		Node* temp = this->head;
		head = head->pNext;
		delete temp;
		size--;
	}

	void print() {
		Node* current = this->head;
		while (current != nullptr) {
			cout << current->value << endl;
			current = current->pNext;
		}
	}

	int getSize() {
		return size;
	}

	~Queue() {
		while (size)
		{
			popFront();
		}
	}
};


int main()
{
	Queue<int>queue;

	queue.pushBack(1);
	queue.pushBack(2);
	queue.pushBack(3);
	queue.pushBack(4);

	queue.print();
	cout << "size = " << queue.getSize() << endl;

	queue.pushBack(5);
	queue.popFront();
	queue.popFront();
	queue.print();
	cout << "size = " << queue.getSize() << endl;
}

