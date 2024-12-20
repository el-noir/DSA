//#include <iostream>
//using namespace std;
//
//class Heap {
//public:
//	int arr[100];
//	int size;
//
//	Heap() {
//		arr[0] = -1;
//		size = 0;
//	}
//
//	void insert(int value) {
//		size++;
//		int index = size;
//		arr[index] = value;
//
//		while (index > 1) {
//			int parent = index / 2;
//
//			if (arr[parent] < arr[index]) {
//				swap(arr[parent], arr[index]);
//				index = parent;
//			}
//			else {
//				return;
//			}
//		}
//	}
//
//	void deletefrom () {
//		if (size == 0) {
//			return;
//		}
//		arr[1] = arr[size];
//		size--;
//
//		// take the root node to its correct position
//		int i = 1;
//		while (i < size) {
//			int leftIndex = 2 * i;
//			int rightIndex = 2 * i + 1;
//
//			if (leftIndex < size && arr[i] < arr[leftIndex]) {
//				swap(arr[i], arr[leftIndex]);
//				i = leftIndex;
//			}
//			else if (rightIndex < size && arr[i] < arr[rightIndex]) {
//				swap(arr[i], arr[rightIndex]);
//				i = rightIndex;
//			}
//			else {
//				return;
//			}
//		}
//	}
//
//	void print() {
//		for (int i = 1; i <= size; i++) {
//			cout << arr[i] << " ";
//
//		}
//		cout << endl;
//	}
//
//
//};
//
//void heapify(int arr[], int n, int i) {
//	int largest = i;
//	int left = 2 * i;
//	int right = 2 * i + 1;
//
//	if (left <= n && arr[largest] < arr[left]) {
//		largest = left;
//	} 
//	if (right <= n && arr[largest] < arr[right]) {
//		largest = right;
//	}
//	if (largest != i) {
//		swap(arr[largest], arr[i]);
//		heapify(arr, n, largest);
//	}
//}
//
//int main() {
//	Heap h;
//	h.insert(50);
//	h.insert(55);
//	h.insert(53);
//	h.insert(52);
//	
//	h.insert(54);
//
//	h.print();
//
//	h.deletefrom();
//
//	h.print();
//
//	int arr[6] = { -1, 54, 53, 55, 52, 50 };
//	int n = 5;
//	for (int i = n / 2; i > 0; i--) {
//		heapify(arr, n, i);
//	}
//
//	cout << "Printing elements : " << endl;
//
//	for (int i = 1; i <= n; i++) {
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//
//}

#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
	vector<int> heap;

	int parent(int index) {
		return (index - 1) / 2;
	}
	int leftChild(int index) {
		return 2 * index;
	}
	int rightChild(int index) {
		return 2 * index + 1;
	}
	void swap(int index1, int index2) {
		int temp = heap[index1];
		heap[index1] = heap[index2];
		heap[index2] = temp;
	}

	void heapify(int index) {
		int largest = index;
		int left = leftChild(index);
		int right = rightChild(index);

		if (left < heap.size() && heap[largest] < heap[left])
		{
			largest = left;
		}
		if (right < heap.size() && heap[largest] < heap[right]) {
			largest = right;
		}
		if (largest != index) {
			swap(index, largest);
			heapify(index);
		}
	}


public:
	void insert(int val) {
		heap.push_back(val);
		int currentI = heap.size() -1;

		while (currentI > 0 && heap[parent(currentI)] < heap[currentI]) {
			swap(currentI, parent(currentI));
			currentI = parent(currentI);
		}
	}
	int deleteRoot() {
		if (heap.empty()) {
			return -1;
		} 
		int maxElement = heap[0];

		heap[0] = heap[heap.size() - 1];
		heap.pop_back();
		heapify(0);

		return maxElement;
	}

	int getMax() {
		if (heap.empty()) {
			if (heap.empty()) {
				return -1;
			}
			return heap[0];
		}
	}

	void print() {
		for (int i : heap) {
			cout << i << " ";
		}
		cout << endl;
	}
};

int main() {
	
}