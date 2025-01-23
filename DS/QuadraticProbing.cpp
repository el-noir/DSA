#include <iostream>
using namespace std;

const int maxSize = 10;

class QuadraticProbing {
private:
	int table[maxSize];
	int occupied[maxSize];
public:
	QuadraticProbing() {
		for (int i = 0; i < maxSize; i++) {
			table[i] = -1;
			occupied[i] = false;
		}
	}

	int hash(int key) {
		return key % maxSize;
	}

	void insert(int key) {
		int index = hash(key);
		int originalIndex = index;
		int i = 1;

		while (occupied[index]) {
			index = (originalIndex + i * i) % maxSize;
			i++;
			if (i == maxSize) {
				cout << "Hash table is full, cannot insert " << key << endl;
				return;
			}
		}
		table[index] = key;
		occupied[index] = true;
	}


	void display() {
		for (int i = 0; i < maxSize; i++) {
			if (occupied[i]) {
				cout << "Index " << i << " is : " << table[i] << endl;
			}
			else {
				cout << "Index " << i << " is : " << " Empty." << endl;
			}
		}
	}
};

int main() {
	QuadraticProbing even;
	QuadraticProbing odd;

	int n;
	cout << "Enter the number of values : ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		int value;
		cout << "Enter value : ";
		cin >> value;


		if (value % 2 == 0) {
			even.insert(value);
		}
		else {
			odd.insert(value);
		}
	}

	cout << "Odd hashtable : ";
	odd.display();
	cout << "Even hashtable : ";
	even.display();
}