#include "sort.h"

void testSort(void (*sortFunction)(std::vector<int>&), string sortName)
{
	cout << "--- Testing " << sortName << " --- " << endl;
	vector<int> nums;

	// Test 1
	nums.clear();
	for(int i = 7; i > 0; i--)
		nums.push_back(i);
	sortFunction(nums);
	cout << endl;

	// Test 2
	nums.clear();
	nums.push_back(3);
	nums.push_back(7);
	nums.push_back(2);
	nums.push_back(8);
	nums.push_back(5);
	nums.push_back(9);
	nums.push_back(1);
	sortFunction(nums);
	cout << endl;
}

int main()
{
	Sort mySort;
	testSort(mySort.insertionSort, "Insertion Sort");
	testSort(mySort.bubbleSort, "Bubble Sort");
	testSort(mySort.selectionSort, "Selection Sort");
	testSort(mySort.mergeSort, "Merge Sort");
}
