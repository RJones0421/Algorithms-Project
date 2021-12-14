#include "InsertionSort.h"

InsertionSort::InsertionSort(int maxLength) {
	A = new int[maxLength];
}

InsertionSort::~InsertionSort() {
	delete[] A;
}

int InsertionSort::Sort(int length, int index) {
	for (int i = 1; i < length; i++) {
		int key = A[i];
		int j = i - 1;

		while ((i > -1) && (A[j] > key)) {
			A[j + 1] = A[j];
			j -= 1;
		}

		A[j + 1] = key;
	}

	return A[index];
}