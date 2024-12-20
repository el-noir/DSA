//#include <iostream>
//using namespace std;
//
//class Node {
//public:
//	string name;
//	string data;
//	Node* next;
//	Node* prev;
//
//	Node(string d, string data) {
//		this->data = data;
//		this->name = d;
//		this->next = NULL;
//	}
//
//	void insertStart(Node*& head, string d, string data) {
//		Node* temp = new Node(d, data);
//
//		temp->next = head;
//		head->prev = temp;
//		head = temp;
//	}
//	void insertEnd(Node*& tail, string d, string data) {
//		Node* temp = new Node(d, data);
//		temp->prev = tail;
//		tail->next = temp;
//		tail = tail->next;
//	}
//
//	void insertAtPos(Node*& head, string d, string data, int pos) {
//		Node* temp = new Node(d, data);
//		if (pos == 1) {
//			insertStart(head, d, data);
//			return;
//		}
//		Node* curr = head;
//		for (int i = 1; i < pos - 1 && temp != NULL; i++) {
//			curr = curr->next;
//		}
//		if (curr == NULL) {
//			cout << "Position is out of bounds. " << endl;
//			delete temp;
//			return;
//		}
//		temp->next = curr->next;
//		temp->prev = curr;
//		curr->next = temp;
//
//		if (curr->next != NULL) {
//			temp->next->prev = temp;
//		}
//	}
//
//	void traverseHead(Node*& head) {
//		Node* temp = head;
//
//		cout << "NULL <- ";
//		while (temp != NULL) {
//			cout << temp->name << endl;
//			cout << temp->data << endl;
//			if (temp->next == NULL) {
//				cout << " -> NULL";
//			}
//			else {
//				cout << " <-> ";
//			}
//			temp = temp->next;
//		}
//		cout << endl;
//	}
//	void traverseTail(Node*& tail) {
//		Node* temp = tail;
//		cout << " NULL <- ";
//		while (temp != NULL) {
//			cout << temp->name << endl;
//			cout << temp->data << endl;
//			if (temp->prev == NULL) {
//				cout << " -> NULL";
//			}
//			else {
//				cout << " <-> ";
//			}
//			temp = temp->prev;
//		}
//		cout << endl;
//	}
//};
//
//
//
//class recentContact {
//
//	Node history;
//
//public:
//
//	void peopleadd(string name, string data) {
//		history.insertStart(head, name, data );
//		history.insertStart(head, name, data);
//		history.insertStart(head, name, data);
//	}
//     
//	void scrolldown() {
//		Node* temp = history;
//
//		while (temp != NULL) {
//			history.traverseHead();
//		}
//	}
//	void scrollup() {
//		Node* temp = history;
//
//		while (temp != NULL) {
//			history.traverseTail();
//		}
//	}
//
//};


#include <iostream>
using namespace std;

class Node {
public:
    string name;
    string data;
    Node* next;
    Node* prev;

    Node(string n, string d) {
        name = n;
        data = d;
        next = nullptr;
        prev = nullptr;
    }
};

class RecentContacts {
private:
    Node* head; // Pointer to the head of the list
    Node* tail; // Pointer to the tail of the list
    const int maxContacts; // Maximum number of contacts allowed

public:
    RecentContacts(int max) : head(nullptr), tail(nullptr), maxContacts(max) {}

    void addContact(string name, string data) {
        // Check if the contact already exists
        Node* current = head;
        while (current != nullptr) {
            if (current->name == name) {
                // Move existing contact to the front
                if (current != head) {
                    if (current == tail) {
                        tail = tail->prev; // Update tail if necessary
                        tail->next = nullptr;
                    }
                    else {
                        current->prev->next = current->next; // Bypass current
                        if (current->next != nullptr) {
                            current->next->prev = current->prev; // Bypass current
                        }
                    }
                    current->next = head; // Move to front
                    current->prev = nullptr;
                    head->prev = current;
                    head = current;
                }
                return;
            }
            current = current->next;
        }

        // Create a new node
        Node* newNode = new Node(name, data);

        // Add to the front
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        // Check if we exceed max contacts
        if (countContacts() > maxContacts) {
            removeLastContact();
        }
    }

    void removeLastContact() {
        if (tail == nullptr) return; // No contacts to remove

        Node* toDelete = tail;
        if (tail->prev != nullptr) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else { // List will be empty
            head = nullptr;
            tail = nullptr;
        }
        delete toDelete;
    }

    int countContacts() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void scrollDown() {
        cout << "Recent Contacts (most recent first): " << endl;
        Node* current = head;
        while (current != nullptr) {
            cout << current->name << " (" << current->data << ")" << endl;
            current = current->next;
        }
    }

    void scrollUp() {
        cout << "Recent Contacts (oldest first): " << endl;
        Node* current = tail;
        while (current != nullptr) {
            cout << current->name << " (" << current->data << ")" << endl;
            current = current->prev;
        }
    }
};

int main() {
    RecentContacts recentContacts(5); // Maximum of 5 contacts

    recentContacts.addContact("Alice", "123-456-7890");
    recentContacts.addContact("Bob", "987-654-3210");
    recentContacts.addContact("Charlie", "555-555-5555");
    recentContacts.addContact("Alice", "123-456-7890"); // Revisit Alice
    recentContacts.addContact("Eve", "222-222-2222");
    recentContacts.addContact("Dave", "444-444-4444"); // This should remove Bob

    // Display contacts
    recentContacts.scrollDown(); // Expected: Dave, Eve, Alice, Charlie

    // Display contacts in reverse order
    recentContacts.scrollUp(); // Expected: Charlie, Alice, Eve, Dave

    return 0;
}
