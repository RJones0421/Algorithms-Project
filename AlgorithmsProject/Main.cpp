#include "Main.h"
#include <iostream>
#include <stdlib.h>
#include <chrono>

using namespace std;

int main() {
	Main* main = new Main();
	main->RunProject();
	
	delete main;

	return 0;
}

Main::Main() {
	heapSort = new HeapSort(MAX_NUMBERS);
	insertionSort = new InsertionSort(MAX_NUMBERS);
	randomizedSelect = new RandomizedSelect(MAX_NUMBERS);

	aInsertionTime = new float[ITERATIONS];
	aHeapsortTime = new float[ITERATIONS];
	aRandomizedTime = new float[ITERATIONS];

	A = new int[MAX_NUMBERS];
}

Main::~Main() {
	delete heapSort;
	delete insertionSort;
	delete randomizedSelect;

	delete[] aInsertionTime;
	delete[] aHeapsortTime;
	delete[] aRandomizedTime;

	delete[] A;
}

void Main::RunProject() {
	cout << "IS value | HS value | RS value\n";

	for (int i = 1; i <= ITERATIONS; i++) {
		length = i * 10000;
		index = (int)(2 * length / 3);

		ResetTime();

		cout << "\nIndex values for array of length " << length << ":\n";

		for (int j = 0; j < 5; j++) {
			CreateAndCopyArray(length);

			Insertion(length, index);
			Heap(length, index);
			Randomized(length, index);
		}

		aInsertionTime[i - 1] = insertionTime / 5;
		aHeapsortTime[i - 1] = heapsortTime / 5;
		aRandomizedTime[i - 1] = randomizedTime/ 5;
	}

	PrintResults();
}


void Main::CreateAndCopyArray(int length) {
	for (int i = 0; i < length; i++) {
		int num = (int)rand() % 40000;

		insertionSort->A[i] = num;
		heapSort->A[i] = num;
		randomizedSelect->A[i] = num;
	}
}

void Main::Insertion(int length, int index) {
	startTime = (long)(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());
	int value = insertionSort->Sort(length, index);
	endTime = (long)(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());

	cout << value << "\t";
	insertionTime = (int)(insertionTime + (endTime - startTime));
}

void Main::Heap(int length, int index) {
	startTime = (long)(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());
	int value = heapSort->Sort(length, index);
	endTime = (long)(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());

	cout << value << "\t";
	heapsortTime = (int)(heapsortTime + (endTime - startTime));
}

void Main::Randomized(int length, int index) {
	startTime = (long)(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());
	int value = randomizedSelect->Sort(length, index);
	endTime = (long)(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());

	cout << value << "\n";
	randomizedTime = (int)(randomizedTime + (endTime - startTime));
}

void Main::ResetTime() {
	insertionTime = 0;
	heapsortTime = 0;
	randomizedTime = 0;
}

void Main::PrintResults() {
	cout << "\nAverage time per sorting method (in ms)\n";
	
	cout << "Insertion Sort Times:\t";
	for (int i = 0; i < ITERATIONS; i++) {
		cout << aInsertionTime[i] << "\t";
	}

	cout << "\nHeap Sort Times:\t";
	for (int i = 0; i < ITERATIONS; i++) {
		cout << aHeapsortTime[i] << "\t";
	}

	cout << "\nRandomizedSelect Times:\t";
	for (int i = 0; i < ITERATIONS; i++) {
		cout << aRandomizedTime[i] << "\t";
	}

	cout << "\n";
}