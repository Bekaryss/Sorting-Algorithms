// Heap Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// To heapify a subtree rooted with node i which is 
// an index in heap. n is size of heap 
void heapify(vector<int>& heap, int n, int i) {
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && heap[l] > heap[largest]) {
		largest = l;
	}

	// If right child is larger than largest so far 
	if (r < n && heap[r] > heap[largest]) {
		largest = r;
	}

	// If largest is not root 
	if (largest != i) {
		swap(heap[i], heap[largest]);

		// Recursively heapify the affected sub-tree 
		heapify(heap, n, largest);
	}
}

void heapSort(vector<int>& heap) {
	int n = heap.size();
	for (int i = n / 2; i >= 0; i--) {
		heapify(heap, n, i);
	}

	// One by one extract an element from heap 
	for (int i = n - 1; i >= 0; i--) {
		// Move current root to end 
		swap(heap[0], heap[i]);

		// call max heapify on the reduced heap 
		heapify(heap, i, 0);
	}
}

void PrintRes(vector<int> res) {
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> input = { 10, 6, 7, 5, 15, 17 ,12 };
	PrintRes(input);
	heapSort(input);
	PrintRes(input);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
