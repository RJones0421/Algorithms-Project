#include "HeapSort.h"
#include "InsertionSort.h"
#include "RandomizedSelect.h"

#define MAX_NUMBERS	200000
#define ITERATIONS 20

class Main {

public:
	Main();
	~Main();

	void RunProject();

private:
	HeapSort* heapSort;
	InsertionSort* insertionSort;
	RandomizedSelect* randomizedSelect;

	int* A;

	float* aInsertionTime;
	float* aHeapsortTime; 
	float* aRandomizedTime;
	
	int insertionTime;
	int heapsortTime;
	int randomizedTime;

	int length;
	int index;

	long startTime;
	long endTime;

	void CreateAndCopyArray(int length);
	void Insertion(int length, int index);
	void Heap(int length, int index);
	void Randomized(int length, int index);
	void ResetTime();
	void PrintResults();
};