#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int d) {
		this->data = d;
		this->next = NULL;
	}
};
class Queue {
	Node* front;
	Node* rear;

public:
	Queue() {
		front = NULL;
		rear = NULL;
	}
	void enqueue(int d) {
		Node* temp = new Node(d);

		if (isEmpty()) {
			front = temp;
			rear = temp;

		}
		else {
			rear->next = temp;
			rear = temp;
		}
		cout << "Enqueued item : " << d << endl;
	}
	int dequeue()
	{
		if (isEmpty()) {
			cout << "Underflow of Queue.";
			return -1;
		}
		Node* temp = front;
		int result = temp->data;
		front = front->next;
		if (front == NULL) {
			rear = NULL;
		}
		delete temp;

		return result;
	}
	bool isEmpty() {
		return (front == NULL);
	}
};