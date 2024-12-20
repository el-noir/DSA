#include <iostream>
#include <algorithm>  
using namespace std;

void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void selectionSort(int arr[], int n) {


	for (int i = 0; i < n; i++) {
		int minI = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minI]) {
				minI = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[minI];
		arr[minI] = temp;
	}
}

void insertionSort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// Merge Sort
void merge(int arr[], int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int L[n1], R[n2];
	for (int i = 0; i < n1; i++) L[i] = arr[left + i];
	for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) arr[k++] = L[i++];
		else arr[k++] = R[j++];
	}
	while (i < n1) arr[k++] = L[i++];
	while (j < n2) arr[k++] = R[j++];
}

void mergeSor(int arr[], int low, int high) {
	if (low < high) {
		int mid = low + (low + high) / 2;
		mergeSor(arr, low, mid);
		mergeSor(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}


void mergeSort(int arr[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

// Quick Sort
int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j < high; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return i + 1;
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

// Bucket Sort
void bucketSort(int arr[], int n) {
	int maxVal = *max_element(arr, arr + n);
	int bucketCount = 10;  // Fixed number of buckets
	int buckets[10][10] = { 0 };  // Assuming max 10 items in each bucket
	int bucketSizes[10] = { 0 };

	for (int i = 0; i < n; i++) {
		int index = (arr[i] * bucketCount) / (maxVal + 1);
		buckets[index][bucketSizes[index]++] = arr[i];
	}

	for (int i = 0; i < bucketCount; i++) {
		for (int j = 0; j < bucketSizes[i] - 1; j++) {
			for (int k = 0; k < bucketSizes[i] - j - 1; k++) {
				if (buckets[i][k] > buckets[i][k + 1]) {
					swap(buckets[i][k], buckets[i][k + 1]);
				}
			}
		}
	}

	int index = 0;
	for (int i = 0; i < bucketCount; i++) {
		for (int j = 0; j < bucketSizes[i]; j++) {
			arr[index++] = buckets[i][j];
		}
	}
}

// Radix Sort
int getMax(int arr[], int n) {
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

void countingSort(int arr[], int n, int exp) {
	int output[n];
	int count[10] = { 0 };
	for (int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
	for (int i = 1; i < 10; i++) count[i] += count[i - 1];
	for (int i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for (int i = 0; i < n; i++) arr[i] = output[i];
}

void radixSort(int arr[], int n) {
	int m = getMax(arr, n);
	for (int exp = 1; m / exp > 0; exp *= 10)
		countingSort(arr, n, exp);
}

// Binary Search
int binarySearch(int arr[], int left, int right, int x) {
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == x) return mid;
		if (arr[mid] < x) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}

int main() {
	const int n = 9;
	int arr[n] = { 4, 6, 1, 5, 7, 10, 7, 2, 12 };

	// Uncomment to use each sorting algorithm
	// bubbleSort(arr, n);
	// selectionSort(arr, n);
	// insertionSort(arr, n);
	// mergeSort(arr, 0, n - 1);
	// quickSort(arr, 0, n - 1);
	// bucketSort(arr, n);
	// radixSort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	// Binary Search (after sorting the array)
	int x = 7;  // Element to search
	int result = binarySearch(arr, 0, n - 1, x);
	if (result != -1)
		cout << "Element found at index " << result << endl;
	else
		cout << "Element not found" << endl;

	return 0;
}
