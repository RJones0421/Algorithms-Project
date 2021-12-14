#include "RandomizedSelect.h"
#include <stdlib.h>

RandomizedSelect::RandomizedSelect(int maxLength) {
    A = new int[maxLength];
}

RandomizedSelect::~RandomizedSelect() {
	delete[] A;
}

int RandomizedSelect::Sort(int length, int index) {
	int start = 0;
	int end = length - 1;

	RandomizedSort(start, end, index);

	return(A[index]);
}

int RandomizedSelect::RandomizedSort(int start, int end, int i) {
    if (start == end) {
        return(A[start]);
    }

    int q = RandomizedPartition(start, end);

    if (i == q) {
        return A[q];
    }
    else if (i < q) {
        return RandomizedSort(start, q - 1, i);
    }
    else {
        return RandomizedSort(q + 1, end, i);
    }
}

int RandomizedSelect::RandomizedPartition(int start, int end)
{
    int i = (int)(rand() % (end - start) + start);

    int temp = A[end];
    A[end] = A[i];
    A[i] = temp;

    return (Partition(start, end));
}

int RandomizedSelect::Partition(int start, int end)
{
    int x = A[end];
    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (A[j] <= x) {
            i++;

            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    int temp = A[i + 1];
    A[i + 1] = A[end];
    A[end] = temp;

    return(i + 1);
}
