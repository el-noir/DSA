#include <iostream>
using namespace std;

class Node {
public:
    string text;
    Node* next;

    Node(string text) {
        this->text = text;
        this->next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(string text) {
        Node* newText = new Node(text);
        newText->next = top;
        top = newText;
    }

    Node* pop() {
        if (top == nullptr) {
            cout << "Underflow." << endl;
            return nullptr;
        }

        Node* temp = top;
        top = top->next;
        return temp;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    void history() const {
        Node* temp = top;
        int count = 1;
        while (temp != nullptr) {
            cout << "String " << count << ": " << temp->text << "\n";
            temp = temp->next;
            count++;
        }
    }
};

class TextEditor {
    Stack mainstack;
    Stack redostack;
public:

    void insertText(string text) {
        mainstack.push(text);

        while (!redostack.isEmpty()) {
            redostack.pop();
        }
    }

    void undo() {
        Node* temp = mainstack.pop();

        if (temp != NULL) {
            redostack.push(temp->text);
            delete temp;
        }
        else {
            cout << "Cannot undo.\n";
        }
    }
    void redo() {
        Node* temp = redostack.pop();

        if (temp != NULL) {
            mainstack.push(temp->text);
        }
        else {
            cout << "Cannot redo.\n";
        }
    }

    void showHistory() {
        mainstack.history();
    }

};