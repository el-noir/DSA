#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int d) {
        this->data = d;
        this->next = NULL;
        this->prev = NULL; // Initialize prev to NULL in the constructor
    }
};

void insertStart(Node*& head, int d) {
    Node* temp = new Node(d);
    if (head != NULL) {
        temp->next = head;
        head->prev = temp;
    }
    head = temp;
}

void insertEnd(Node*& tail, int d) {
    Node* temp = new Node(d);
    if (tail != NULL) {
        temp->prev = tail;
        tail->next = temp;
    }
    tail = temp;
}

void insertAtPos(Node*& head, int d, int pos) {
    Node* temp = new Node(d);
    if (pos == 1) {
        insertStart(head, d);
        return;
    }
    Node* curr = head;
    for (int i = 1; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
    }
    if (curr == NULL) {
        cout << "Position is out of bounds." << endl;
        delete temp;
        return;
    }
    temp->next = curr->next;
    temp->prev = curr;
    curr->next = temp;

    if (temp->next != NULL) {
        temp->next->prev = temp;
    }
}

void deleteHead(Node*& head) {
    if (head == NULL) {
        cout << "No element found." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }
    delete temp;
}

void deleteTail(Node*& head) {
    if (head == NULL) {
        cout << "No elements." << endl;
        return;
    }


    Node* curr = head;

    while (curr->next->next != NULL) {
        curr = curr->next;
    }
    Node* temp = curr->next;

    delete temp;

    curr->next = NULL;


    //Node* temp = tail;
    //tail = tail->prev;

    //if (tail != NULL) {
    //    tail->next = NULL;
    //}
    //delete temp;
}

void deletePos(Node*& head, int pos) {
    if (head == NULL) {
        cout << "No elements found." << endl;
        return;
    }
    Node* curr = head;

    for (int i = 1; i < pos && curr != NULL; i++) {
        curr = curr->next;
    }

    if (curr == NULL) {
        cout << "Position out of bounds!" << endl;
        return;
    }
    if (curr->prev != NULL) {
        curr->prev->next = curr->next;
    }
    else {
        head = curr->next; // Update head if deleting the first node
    }
    if (curr->next != NULL) {
        curr->next->prev = curr->prev;
    }
    delete curr;
}

void traverseHead(Node* head) {
    Node* temp = head;
    cout << "NULL <- ";
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) {
            cout << " <-> ";
        }
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

void traverseTail(Node* tail) {
    Node* temp = tail;
    cout << "NULL <- ";
    while (temp != NULL) {
        cout << temp->data;
        if (temp->prev != NULL) {
            cout << " <-> ";
        }
        temp = temp->prev;
    }
    cout << " -> NULL" << endl;
}

Node* reverseList(Node*& head) {
    Node* curr = head, * prevP = NULL, * nextP;

    while (curr != NULL) {
        nextP = curr->next;
        curr->next = prevP;
        curr->prev = nextP;


        prevP = curr;
        curr = nextP;
    }
    return prevP;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertStart(head, 5);
    tail = head; // Initialize tail to head
    insertStart(head, 4);
    insertStart(head, 3);
    traverseHead(head);
    traverseTail(tail);

    insertEnd(tail, 6);
    insertEnd(tail, 7);
    traverseHead(head);

    insertAtPos(head, 100, 4);
    traverseHead(head);

    deletePos(head, 4);
    traverseHead(head);

    deleteHead(head);
    traverseHead(head);

    deleteTail(head);
    traverseHead(head);

    return 0;
}
