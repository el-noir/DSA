//#include <iostream>
//#include <unordered_map>
//using namespace std;
//
//int main() {
//    unordered_map<string, int> m;
//
//    // Insertion
//    pair<string, int> p = make_pair("noi", 2);
//    m.insert(p);
//
//    pair<string, int> p2("is", 4);
//    m["hello"] = 1;
//    m["benjour"] = 3;
//
//    // Accessing existing keys
//    cout << m["hello"] << endl;
//    cout << m.at("benjour") << endl;
//
//    // Checking if key exists before using at()
//    if (m.find("hhh") != m.end()) {
//        cout << m.at("hhh") << endl;
//    }
//    else {
//        cout << "Key 'hhh' not found in map (using at())." << endl;
//    }
//
//    // Using operator[] for safe access
//    cout << m["hhh"] << endl; // This will add a new key with value 0
//
//    cout << m.size() << endl;
//
//    //check presence
//    cout << m.count("hello") << endl;
//
//    //erase
//    m.erase("hello");
//
//    cout << m.size() << endl;
//
//    unordered_map<string, int> ::iterator it = m.begin();
//
//    while (it != m.end()) {
//        cout << it->first << it->second << endl;
//        it++;
//    }
//
//
//    return 0;
//}



//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//
//int maxFrequency(vector<int>& arr, int n) {
//	unordered_map<int, int > count;
//
//	for (int i = 0; i < arr.size(); i++) {
//		count[arr[i]]++;
//	}
//
//	int maxi = INT_MIN;
//	int ans = -1;
//
//	for (auto i : count) {
//		if (i.second > maxi) {
//			maxi = i.second;
//			ans = i.first;
//		}
//	}
//	return ans;
//}
//
//int main() {
//	
//}



//#include <iostream>
//using namespace std;
//
//const int TABLE_SIZE = 10;
//
//class ListNode {
//public:
//	int value;
//	ListNode* next;
//
//	ListNode(int val): value(val), next(NULL){}
//};
//
//class SeperateChainingHashTable {
//private:
//	ListNode* evenTable[TABLE_SIZE];
//	ListNode* oddTable[TABLE_SIZE];
//
//	int hash(int key) {
//		return key % TABLE_SIZE;
//	}
//
//public:
//	SeperateChainingHashTable() {
//		for (int i = 0; i < TABLE_SIZE; i++) {
//			evenTable[i] = NULL;
//			oddTable[i] = NULL;
//		}
//	}
//
//	void insert(int key) {
//		int index = hash(key);
//		ListNode* newNode = new ListNode(key);
//
//		if (key % 2 == 0) {
//			if (evenTable[index] == NULL) {
//				evenTable[index] = newNode;
//			}
//			else {
//				ListNode* current = evenTable[index];
//				while (current->next) {
//					current = current->next;
//				}
//				current->next = newNode;
//			}
//		}
//		else {
//			if (oddTable[key] == NULL) {
//				oddTable[index] = newNode;
//			}
//			else {
//				ListNode* current = oddTable[index];
//				while (current->next) {
//					current = current->next;
//				}
//				current->next = newNode;
//			}
//		}
//	}
//
//	void display(ListNode* table[]){
//		for (int i = 0; i < TABLE_SIZE; i++) {
//			cout << "Index " << i << ": ";
//			ListNode* current = table[i];
//			while (current) {
//				cout << current->value << " ";
//				current = current->next;
//			}
//			cout << endl;
//		}
//}
//
//	void displayTables() {
//		cout << "Even hash table : " << endl;
//		display(evenTable);
//		cout << "Odd hash table : " << endl;
//		display(oddTable);
//	}
//};
//
//int main() {
//	SeperateChainingHashTable hashTable;
//
//	int n;
//	cout << "Enter the number of values : ";
//	cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		int val;
//
//		cout << "Enter value : " << i + 1 << ": ";
//		cin >> val;
//
//		hashTable.insert(val);
//	}
//	hashTable.displayTables();
//}

//#include <iostream>
//using namespace std;
//
//const int TABLE_SIZE = 10;
//
//class ListNode {
//public:
//    int value;
//    ListNode* next;
//    ListNode(int val) : value(val), next(NULL) {}
//};
//
//class SeparateChainingHashTable {
//private:
//    ListNode* evenTable[TABLE_SIZE];
//    ListNode* oddTable[TABLE_SIZE];
//
//    int hash(int key) {
//        return key % TABLE_SIZE;
//    }
//
//public:
//    SeparateChainingHashTable() {
//        for (int i = 0; i < TABLE_SIZE; ++i) {
//            evenTable[i] = NULL;
//            oddTable[i] = NULL;
//        }
//    }
//
//    void insert(int key) {
//        int index = hash(key);
//        ListNode* newNode = new ListNode(key);
//
//        if (key % 2 == 0) {
//            if (evenTable[index] == NULL) {
//                evenTable[index] = newNode;
//            }
//            else {
//                ListNode* current = evenTable[index];
//                while (current->next) {
//                    current = current->next;
//                }
//                current->next = newNode;
//            }
//        }
//        else {
//            if (oddTable[index] == NULL) {
//                oddTable[index] = newNode;
//            }
//            else {
//                ListNode* current = oddTable[index];
//                while (current->next) {
//                    current = current->next;
//                }
//                current->next = newNode;
//            }
//        }
//    }
//
//    void display(ListNode* table[]) {
//        for (int i = 0; i < TABLE_SIZE; ++i) {
//            cout << "Index " << i << ": ";
//            ListNode* current = table[i];
//            while (current) {
//                cout << current->value << " ";
//                current = current->next;
//            }
//            cout << endl;
//        }
//    }
//
//    void displayTables() {
//        cout << "Even Hash Table:" << endl;
//        display(evenTable);
//        cout << "Odd Hash Table:" << endl;
//        display(oddTable);
//    }
//};
//
//int main() {
//    SeparateChainingHashTable hashTable;
//    int n;
//    cout << "Enter the number of values: ";
//    cin >> n;
//
//    for (int i = 0; i < n; ++i) {
//        int value;
//        cout << "Enter value " << i + 1 << ": ";
//        cin >> value;
//        hashTable.insert(value);
//    }
//
//    hashTable.displayTables();
//
//    return 0;
//}

// 
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


