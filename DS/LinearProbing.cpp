//#include <iostream>
//using namespace std;
//
//const int table_size = 10;
//
//class LinearProbing{
//private:
//	int table[table_size];
//	bool occupied[table_size];
//
//public:
//	LinearProbing() {
//		for (int i = 0; i < table_size; i++) {
//			table[i] = -1;
//			occupied[i] = false;
//		}
//	}
//
//	int hash(int key) {
//		return key % table_size;
//	}
//	void insert(int key) {
//		int index = hash(key);
//		int startIndex = index;
//		while (occupied[index]) {
//			if (index == startIndex) { 
//				cout << "Hash table is full, cannot insert " << key << endl;
//				return;
//			}
//			index = (index + 1) % table_size;
//		}
//		table[index] = key;
//		occupied[index] = true;
//	}
//
//	void display() {
//		for (int i = 0; i < table_size; i++) {
//			if (occupied[i]) {
//				cout << "Index " << i << ": " << table[i] << endl;
//			}
//			else {
//				cout << "Index " << i << ": Empty." << endl;
//			}
//		}
//	}
//
//};
//
//int main() {
//	LinearProbing even;
//	LinearProbing odd;
//
//	int n; 
//	cout << "Enter the number of values : ";
//	cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		int val;
//		cout << "Enter the value " << i + 1 << ": ";
//		cin >> val;
//
//		if (val % 2 == 0) {
//			even.insert(val);
//		}
//		else {
//			odd.insert(val);
//		}
//	}
//	cout << "Even hash table : " << endl;
//	even.display();
//
//	cout << "Odd hash table : " << endl; 
//	odd.display();
//}

#include <iostream>
using namespace std;

const int maxSize = 10;

class LinearProbing {
private:
	int table[maxSize];
	int occupied[maxSize];
public:
	LinearProbing() {
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
		int startIndex = index;

		while (occupied[index]) {
			if (index == startIndex) {
				cout << "Hash table is full, cannot insert " << key << endl;
				return;
			}
			index = (index + 1) % maxSize;
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
	LinearProbing even;
	LinearProbing odd;

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