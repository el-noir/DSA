#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = NULL; // Initialize next pointer to NULL
    }
};

void insertStart(Node*& head, int d) {
    Node* temp = new Node(d);
    temp->next = head; // Point the new node's next to the current head
    head = temp; // Update head to the new node
}

void insertEnd(Node*& head, int d) {
    Node* temp = new Node(d);
    if (head == NULL) {
        head = temp; // If list is empty, new node becomes the head
        return;
    }
    Node* curr = head;
    while (curr->next != NULL) { // Traverse to the end of the list
        curr = curr->next;
    }
    curr->next = temp; // Link the last node to the new node
}

void insertAtPos(Node*& head, int d, int pos) {
    Node* temp = new Node(d);
    if (pos == 1) {
        insertStart(head, d);
        return;
    }
    Node* curr = head;
    for (int i = 1; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next; // Traverse to the position before where we want to insert
    }
    if (curr == NULL) {
        cout << "Position is out of bounds." << endl;
        delete temp; // Free the memory if the position is invalid
        return;
    }
    temp->next = curr->next; // Link the new node to the next node
    curr->next = temp; // Link the previous node to the new node
}

void deleteHead(Node*& head) {
    if (head == NULL) {
        cout << "No element found." << endl;
        return;
    }
    Node* temp = head;
    head = head->next; // Update head to the next node
    delete temp; // Free the memory of the deleted node
}

void deleteTail(Node*& head) {
    if (head == NULL) {
        cout << "No elements." << endl;
        return;
    }
    if (head->next == NULL) {
        delete head; // If there is only one node
        head = NULL; // Update head to NULL
        return;
    }
    Node* curr = head;
    while (curr->next->next != NULL) { // Traverse to the second last node
        curr = curr->next;
    }
    delete curr->next; // Delete the last node
    curr->next = NULL; // Set the second last node's next to NULL
}

void deletePos(Node*& head, int pos) {

    if (head == NULL) {
        cout << "No elements found.";
        return;
    }

    if (pos == 1) {
        delete head;
    }
    int count = 1;

    Node* curr = head;

    while (curr != NULL && count < pos-1) {
        curr = curr->next;
        count++;
    }

    Node* temp = curr->next;
    curr->next = temp->next;

    delete temp;

    //if (head == NULL) {
    //    cout << "No elements found." << endl;
    //    return;
    //}
    //if (pos == 1) {
    //    deleteHead(head);
    //    return;
    //}
    //Node* curr = head;
    //for (int i = 1; i < pos - 1 && curr != NULL; i++) {
    //    curr = curr->next; // Traverse to the position before where we want to delete
    //}
    //if (curr == NULL || curr->next == NULL) {
    //    cout << "Position out of bounds!" << endl;
    //    return;
    //}
    //Node* temp = curr->next; // Node to be deleted
    //curr->next = temp->next; // Link the previous node to the next of the node to be deleted
    //delete temp; // Free the memory of the deleted node
}

void traverse(Node* head) {
    Node* curr = head;
    if (curr == NULL) {
        cout << "The list is empty." << endl;
        return;
    }
    cout << "List: ";
    while (curr != NULL) {
        cout << curr->data; // Print the current node's data
        if (curr->next != NULL) {
            cout << " -> "; // Print an arrow if there is a next node
        }
        curr = curr->next; // Move to the next node
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

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
