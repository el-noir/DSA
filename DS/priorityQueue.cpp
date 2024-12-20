#include <iostream>
using namespace std;

class PriorityQueue {
    int size;
    int* arr;
    int* priority;
    int front;
    int rear;

public:
    PriorityQueue(int size) {
        this->size = size;
        arr = new int[size];
        priority = new int[size];
        front = -1;
        rear = -1;
    }

    void enQueue(int value, int pri) {
        if (isFull()) {
            cout << "Overflow of Queue." << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
            arr[rear] = value;
            priority[rear] = pri;
        }
        else {
            int i;
            for (i = rear; i >= front; i--) {
                if (priority[i] < pri) {
                    arr[(i + 1) % size] = arr[i];
                    priority[(i + 1) % size] = priority[i];
                }
                else {
                    break;
                }
            }
            arr[(i + 1) % size] = value;
            priority[(i + 1) % size] = pri;
            rear = (rear + 1) % size;
        }
        cout << value << " has been enqueued with priority " << pri << "." << endl;
    }

    int deQueue() {
        if (isEmpty()) {
            cout << "Queue underflow." << endl;
            return -1;
        }
        int result = arr[front];
        cout << result << " has been dequeued with priority " << priority[front] << "." << endl;

        if (front == rear) {  // Queue becomes empty
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % size;
        }
        return result;
    }

    bool isEmpty() const {
        return (front == -1);
    }

    bool isFull() const {
        return (rear + 1) % size == front;
    }

    ~PriorityQueue() {
        delete[] arr;
        delete[] priority;
    }
};

int main() {
    PriorityQueue pq(5);

    pq.enQueue(10, 1);
    pq.enQueue(20, 2);
    pq.enQueue(30, 0);
    pq.enQueue(40, 3);
    pq.enQueue(50, 2);

    pq.deQueue();
    pq.deQueue();
    pq.deQueue();

    return 0;
}
