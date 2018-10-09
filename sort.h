#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Sort
{
private:

	/*
	 * Convert vector to string. Use for debugging.
	 */
	static string vecToStr(vector<int>& list);

	/*
	 * Print vector to ostream (default cout). Use for debugging. Calls vecToStr function.
	 */
	static void printVector(vector<int>& l, ostream& os=cout);

	/*
	 * Recursive function used by mergeSort. Splits a vector into two halves.
	 */
	static void split(vector<int>& list, vector<int>& left, vector<int>& right);

	/*
	 * Recursive function used by mergeSort. Merges two halves back together
	 * in sorted order.
	 */
	static void merge(vector<int>& left, vector<int>& right, vector<int>& list);

public:
	Sort() {};
	~Sort() {};
	static void bubbleSort(vector<int>& list);
	static void selectionSort(vector<int>& list);
	static void insertionSort(vector<int>& list);
	static void mergeSort(vector<int>& list);
};
