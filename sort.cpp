#include "sort.h"

string Sort::vecToStr(vector<int>& list)
{
	stringstream ss;

	// Iterate through vector, adding each value to stringstream
	for(vector<int>::iterator it = list.begin(); it != list.end(); it++)
	{
		ss << *it << ",";
	}

	// Convert stringstream to string
	string vectorString = ss.str();

	// Remove trailing comma
	if(vectorString.size() > 0)
		vectorString.pop_back();

	return vectorString;
}

void Sort::printVector(vector<int>& l, ostream& os)
{
	os << vecToStr(l) << endl;
}

void Sort::split(vector<int>& list, vector<int>& left, vector<int>& right)
{
  cout << "split: " << vecToStr(list) << endl;
	int middle = list.size()/2;
	for(int i = 0; i < middle; i++)
		left.push_back(list[i]);
	for(int i = middle; i < list.size(); i++)
		right.push_back(list[i]);
}

void Sort::merge(vector<int>& left, vector<int>& right, vector<int>& list)
{
	cout << "merge: " << vecToStr(left) << ", " << vecToStr(right) << endl;
	list.clear();
	int l = 0;
	int r = 0;
	while(l < left.size() && r < right.size())
	{
		if(left[l] < right[r])
		{
			list.push_back(left[l]);
			l++;
		}
		else
		{
			list.push_back(right[r]);
			r++;
		}
	}
	while(l < left.size())
	{
		list.push_back(left[l]);
		l++;
	}
	while(r < right.size())
	{
		list.push_back(right[r]);
		r++;
	}
	cout << "  merged: " << vecToStr(list) << endl;
}

void Sort::bubbleSort(vector<int>& list)
{
	cout << "bubbleSort: " << vecToStr(list) << endl;
	bool isSwap;

	// Do at least once
	do
	{
		isSwap = false;
		for(int i = 0; i < list.size()-1; i++)
		{
			// If adjacent numbers are out of order, perform swap
			if(list[i] > list[i+1])
			{
				int tmp = list[i];
				list[i] = list[i+1];
				list[i+1] = tmp;
				isSwap = true; // Mark that a swap took place
			}
		}
		printVector(list); // Print contents after each iteration
	} while(isSwap); // Do again if at least one swap took place
}

void Sort::selectionSort(vector<int>& list)
{
	cout << "selectionSort: " << vecToStr(list) << endl;
	for(int i = 0; i < list.size()-1; i++)
	{
		// Find smallest remaining item in vector
		int min = i;
		for(int j = i+1; j < list.size(); j++)
		{
			if(list[j] < list[min])
				min = j;
		}

		// Swap smallest remaining item into position
		int tmp = list[i];
		list[i] = list[min];
		list[min] = tmp;

		printVector(list); // Print contents after each iteration
	}
}

void Sort::insertionSort(vector<int>& list)
{
	cout << "insertionSort: " << vecToStr(list) << endl;
	for(int i = 1; i < list.size(); i++)
	{
		int j = i;
		int item = list[j]; // Item to move into sorted portion

		// While item is smaller than current item in sorted portion
		while(j > 0 && list[j-1] > item)
		{
			// Shift items in sorted portion up an index
			list[j] = list[j-1];
			j--;
		}
		// Place item into sorted position
		list[j] = item;

		printVector(list); // Print contents after each iteration
	}
}

void Sort::mergeSort(vector<int>& list)
{
	cout << "mergeSort: " << vecToStr(list) << endl;
	if(list.size() < 2)
		return;
	vector<int> left, right;
	split(list, left, right);
	mergeSort(left);
	mergeSort(right);
	merge(left, right, list);
}
