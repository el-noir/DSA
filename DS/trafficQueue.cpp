#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string d) {
        this->data = d;
        this->next = NULL;
    }
};
class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        this->front = NULL;
        this->rear = NULL;
    }
    void enqueue(string d) {
        Node* temp = new Node(d);

        if (rear == NULL) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    string dequeue() {
        Node* temp = front;
        if (front == NULL) {
            return "queue is empty.";
        }
        string val = front->data;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
        return val;
    }
    string frontE() {
        if (front == NULL) {
            return "";
        }
        return front->data;
    }

    bool isEmpty() {
        return front == NULL;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

class TrafficManage {
    Queue carQueue;
public:
    TrafficManage() {}
    void redLight() {
        string vehicle;
        char choice;

        do {
            cout << "Red light! Enter vehicle name to enqueue: ";
            cin >> vehicle;
            carQueue.enqueue(vehicle);
            cout << vehicle << " enqueued." << endl;

            cout << "Do you want to enqueue another vehicle? (y/n): ";
            cin >> choice;
        } while (choice == 'y');
    }

    void greenLight() {
        cout << "\nSwitching to green light. Vehicles are passing:\n";
        while (!carQueue.isEmpty()) {
            cout << carQueue.dequeue() << " has passed." << endl;
        }
        cout << "No more vehicles in the queue.\n";
    }
};



int main() {
    TrafficManage tr;

    tr.redLight();
    tr.greenLight();
}