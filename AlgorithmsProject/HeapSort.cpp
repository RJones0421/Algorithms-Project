#include "HeapSort.h"

HeapSort::HeapSort(int maxLength)
{
	A = new int[maxLength];
    n = 0;
}

HeapSort::~HeapSort()
{
	delete[] A;
}

int HeapSort::Sort(int length, int index)
{
    n = length;
    BuildMaxHeap();

    for (int i = length - 1; i > 0; i--) {
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;

        n -= 1;
        MaxHeapify(0);
    }

    return (A[index]);
}

void HeapSort::BuildMaxHeap()
{
	for (int i = Parent(n); i >= 0; i--)
		MaxHeapify(i);
}

void HeapSort::MaxHeapify(int i)
{
    int largest;
    int l = Left(i);
    int r = Right(i);
    bool isParentLargest = true;

    //check left side
    if ((l < n) && (A[l] > A[i])) {
        largest = l;
        isParentLargest = false;
    }
    //parent is larger
    else {
        largest = i;
    }

    //check right side
    if ((r < n) && (A[r] > A[largest])) {
        largest = r;
        isParentLargest = false;
    }

    if (!isParentLargest) {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;

        MaxHeapify(largest);
    }
}

int HeapSort::Parent(int i)
{
	return (i / 2) - 1;
}

int HeapSort::Left(int i)
{
	return (2 * i) + 1;
}

int HeapSort::Right(int i)
{
	return (2 * i) + 2;
}
