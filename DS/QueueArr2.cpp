#include <iostream>
using namespace std;

class Queue {
    int size;
    int* arr;
    int front;
    int rear;

public:
    Queue(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void enQueue(int value) {
        if (isFull()) {
            cout << "Overflow of Queue." << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % size;
        arr[rear] = value;
        cout << value << " has been enqueued." << endl;
    }

    int deQueue() {
        if (isEmpty()) {
            cout << "Queue underflow. " << endl;
            return -1;
        }
        int result = arr[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % size;

        }
        return result;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

};