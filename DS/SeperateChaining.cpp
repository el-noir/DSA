#include <iostream>
using namespace std;
const int max_size = 10;
class ListNode {
public:

	int value;
	ListNode* next;

	ListNode(int value) {
		this->value = value;
		this->next = NULL;
	}
};

class SeperateChainingList {
private:
	ListNode* even[max_size];
	ListNode* odd[max_size];

	int hash(int key) {
		return key % max_size;
	}

public:
	SeperateChainingList() {
		for (int i = 0; i < max_size; i++) {
			even[i] = NULL;
			odd[i] = NULL;
		}
	}

	void insert(int key) {
		int index = hash(key);

		ListNode* newNode = new ListNode(key);

		if (key % 2 == 0) {
			if (even[index] == NULL) {
				even[index] = newNode;
			}
			else {
				ListNode* curr = even[index];

				while (curr->next) {
					curr = curr->next;
				}
				curr->next = newNode;
			}
		}
		else {
			if (odd[index] == NULL) {
				odd[index] = newNode;

			}
			else {
				ListNode* curr = odd[index];
				while (curr->next) {
					curr = curr->next;
				}
				curr->next = newNode;
			}
		}
	}

	void display(ListNode* table[]) {
		for (int i = 0; i < max_size; i++) {
			cout << "Index " << i << " : ";
			ListNode* current = table[i];
			while (current) {
				cout << current->value << " ";
				current = current->next;
			}
			cout << endl;
		}
	}

	void displayTables() {
		cout << "Even table : " << endl;
		display(even);
		cout << "\nOdd table : " << endl;
		display(odd);
	}

};

int main() {
	SeperateChainingList hashtable;

	int n;
	cout << "Enter number of elements : ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		int val;
		cout << "Enter value " << i << " : ";
		cin >> val;

		hashtable.insert(val);
	}
	hashtable.displayTables();
}
