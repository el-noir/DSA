#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

class Stack {
private:
	Node* top;
public:
	Stack() : top(NULL) {};

	void push(int d) {
		Node* newnode = new Node(d);
		newnode->next = top;
		top = newnode;
	}

	int pop() {
		if (top == NULL) {
			cout << "Underflow!" << endl;
			return -1;
		}
		else {
			Node* temp = top;
			int popped = temp->data;
			top = top->next;
			delete temp;
			return popped;
		}
	}

	int peek() {
		if (top == NULL) {
			cout << "Underflow!" << endl;
			return -1;
		}
		else {
			return (top->data);
		}
	}
};