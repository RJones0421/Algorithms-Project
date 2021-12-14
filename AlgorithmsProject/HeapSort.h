class HeapSort {

public:
	int* A;

	//Constructors
	HeapSort(int maxLength);
	~HeapSort();

	int Sort(int length, int index);

private:
	int n;

	void BuildMaxHeap();
	void MaxHeapify(int i);
	int Parent(int i);
	int Left(int i);
	int Right(int i);
};