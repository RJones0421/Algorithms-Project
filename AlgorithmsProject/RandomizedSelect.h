class RandomizedSelect {

public:
	int* A;

	//Constructors
	RandomizedSelect(int maxLength);
	~RandomizedSelect();

	int Sort(int length, int index);

private:
	int RandomizedSort(int start, int end, int i);
	int RandomizedPartition(int start, int end);
	int Partition(int start, int end);
};