#include <iostream>
using namespace std;

class Stack {
private:
	int* arr;
	int size;
	int top;

public:
	Stack(int size) {
		this->size = size;
		arr = new int[size];
		top = -1;
	}
	~Stack() {
		delete[] arr;
	}
	void push(int d) {
		if (top < size - 1) {

			top++;
			arr[top] = d;
			int pushed = arr[top];
			cout << "Popped element : " << pushed << endl;
		}
		else {
			cout << "Stack overflow." << endl;
		}
	}

	void pop() {
		if (top >= 0) {
			int popped = arr[top];
			top--;
			cout << "Popped element : " << popped << endl;
		}
		else {
			cout << "Stack underflow." << endl;
		}
	}
	void peek() {
		if (top >= 0) {
			int peeked = arr[top];
			cout << "Top element is : " << peeked << endl;
		}
		else {
			cout << "empty." << endl;
		}
	}

	bool isEmpty() {
		return top == -1; // Return true if top is -1
	}

	// Function to display the stack
	void display() {
		if (isEmpty()) {
			cout << "Stack is empty." << endl;
			return;
		}
		cout << "Stack elements: ";
		for (int i = 0; i <= top; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};