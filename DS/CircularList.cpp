#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = nullptr; // Initialize next pointer to nullptr
    }
};

void insertStart(Node*& head, int d) {
    Node* temp = new Node(d);
    if (head == nullptr) {
        head = temp;
        head->next = head; // Point next to itself to make it circular
    }
    else {
        Node* curr = head;
        while (curr->next != head) { // Traverse to the last node
            curr = curr->next;
        }
        curr->next = temp; // Link the last node to the new node
        temp->next = head; // Point the new node to head
        head = temp; // Update head to the new node
    }
}

void insertEnd(Node*& head, int d) {
    Node* temp = new Node(d);
    if (head == nullptr) {
        head = temp;
        head->next = head; // Point next to itself to make it circular
    }
    else {
        Node* curr = head;
        while (curr->next != head) { // Traverse to the last node
            curr = curr->next;
        }
        curr->next = temp; // Link the last node to the new node
        temp->next = head; // Point the new node to head
    }
}

void insertAtPos(Node*& head, int d, int pos) {
    Node* temp = new Node(d);
    if (pos == 1) {
        insertStart(head, d);
        return;
    }
    Node* curr = head;
    for (int i = 1; i < pos - 1 && curr->next != head; i++) {
        curr = curr->next; // Traverse to the position before where we want to insert
    }
    if (curr->next == head) {
        cout << "Position is out of bounds." << endl;
        delete temp; // Free memory if position is invalid
        return;
    }
    temp->next = curr->next; // Link new node to the next node
    curr->next = temp; // Link previous node to the new node
}

void deleteHead(Node*& head) {
    if (head == nullptr) {
        cout << "No element found." << endl;
        return;
    }
    Node* temp = head;
    if (head->next == head) { // Only one node
        head = nullptr; // Update head to nullptr
    }
    else {
        Node* curr = head;
        while (curr->next != head) { // Find the last node
            curr = curr->next;
        }
        curr->next = head->next; // Link last node to second node
        head = head->next; // Update head to the next node
    }
    delete temp; // Free memory of the deleted node
}

void deleteTail(Node*& head) {
    if (head == nullptr) {
        cout << "No elements." << endl;
        return;
    }
    if (head->next == head) { // Only one node
        delete head; // Delete the only node
        head = nullptr; // Update head to nullptr
        return;
    }
    Node* curr = head;
    while (curr->next->next != head) { // Traverse to the second last node
        curr = curr->next;
    }
    delete curr->next; // Delete the last node
    curr->next = head; // Link the second last node to head
}

void deletePos(Node*& head, int pos) {
    if (head == nullptr) {
        cout << "No elements found." << endl;
        return;
    }
    if (pos == 1) {
        deleteHead(head);
        return;
    }
    Node* curr = head;
    for (int i = 1; i < pos - 1 && curr->next != head; i++) {
        curr = curr->next; // Traverse to the position before where we want to delete
    }
    if (curr->next == head) {
        cout << "Position out of bounds!" << endl;
        return;
    }
    Node* temp = curr->next; // Node to be deleted
    curr->next = temp->next; // Link previous node to next of the node to be deleted
    delete temp; // Free memory of the deleted node
}

void traverse(Node* head) {
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }
    Node* curr = head;
    cout << "List: ";
    do {
        cout << curr->data; // Print the current node's data
        curr = curr->next; // Move to the next node
        if (curr != head) {
            cout << " -> "; // Print an arrow if there is a next node
        }
    } while (curr != head); // Continue until we come back to head
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Inserting elements
    insertStart(head, 5);
    insertStart(head, 4);
    insertStart(head, 3);
    traverse(head); // List: 3 -> 4 -> 5

    insertEnd(head, 6);
    insertEnd(head, 7);
    traverse(head); // List: 3 -> 4 -> 5 -> 6 -> 7

    insertAtPos(head, 100, 3);
    traverse(head); // List: 3 -> 4 -> 100 -> 5 -> 6 -> 7

    deletePos(head, 3);
    traverse(head); // List: 3 -> 4 -> 5 -> 6 -> 7

    deleteHead(head);
    traverse(head); // List: 4 -> 5 -> 6 -> 7

    deleteTail(head);
    traverse(head); // List: 4 -> 5 -> 6

    return 0;
}
