# Bubble Sort

```bash
do:
	for each pair of adjacent elements:
		if the values are out of order:
			swap the values
			while the array is not sorted
```

With bubble sort, you go over the array and look at every pair of adjacent elements. If the values are out of order, you swap them. After a single pass over the array, the greatest element in the array will be in the correct place at the end. (After the second pass, the second greatest element will be in the correct place at the second-to-end, and so on). Once you make a pass over the array and no elements are swapped, you know that the list is sorted.

The worst-case runtime of bubble sort is O(n2). Each pass of the array is O(n), and up to n passes may be required. Multiply that together to get O(n2).

```c++
void Sort::bubbleSort(vector<int>& list)
{
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
	} while(isSwap); // Do again if at least one swap took place
}
```

# Selection Sort

The basic concept of selection sort is to keep finding the smallest value in the unsorted part of the array and swap it into the next index after the sorted part of the array. For the first pass, find the smallest value in the array and swap it to index 0. For the second pass, find the smallest value in the remaining part of the array and swap it to index 1. Continue this pattern until the array is sorted.

```bash
for each i from 0 to size-2:
	min = i
	for each j from i+1 to size-1:
		if list[j] < list[min]:
			min = j
	swap list[i] and list[min]
```

The worst-case runtime of selection sort is also O(n2). Again, each pass of the array is O(n) and up to n passes will be required to sort the list, resulting in O(n2) overall.

```c++
void Sort::selectionSort(vector<int>& list)
{
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
	}
}
```

# Insertion Sort
Imagine you're playing a game of cards with a group of friends. The dealer deals, and you follow good card etiquette by leaving them on the table until the dealer is finished dealing. Then you pick up your hand one card at a time.

The first card you pick up is a 7. You hold it in your hand. The next one is a 3. You put it to the left of the 7. Then you pick up a 6. You insert it between the 3 and the 7. Then you put a King to the far right. Then a 2 to the far left. Then a 10 between the 7 and the King.

Without knowing it, you just did an insertion sort.

For an insertion sort, you have to keep track of the sorted portion (e.g. the cards you have sorted into your hand) and the unsorted portion (e.g. the remaining cards on the table). To begin, index 0 is considered the sorted portion (e.g. the first card you pick up) and the rest of the array is the unsorted portion. You look at the value at index 1. If it's less than the value at index 0, then swap them. Now indexes [0, 1] are your sorted portion and index 2 is the next value. If the value at index 2 is less than the value at index 1, swap them (so now the new value is at index 1). Then if the value at index 0 is less than the value at index 1, swap them.

```bash
for each i from 1 to size-1:
	j = i
	item = list[j]
	while j > 0 and list[j-1] > item:
		list[j] = list[j-1];
		j--;
	list[j] = item
```

The worst-case runtime is again O(n2). The outer loop iterates over the list and the inner loop can potentially iterate over the whole list as well.

```c++
void Sort::insertionSort(vector<int>& list)
{
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
	}
}
```

# Merge Sort

# Test Driver

The test driver has a function that takes a sorting function as input:

```c++
void testSort(void (*sortFunction)(std::vector<int>&), string sortName)
```

The testSort function can then create test cases that can be applied to any
sorting algorithm passed in. Functions are passed in by name:

```c++
int main()
{
	Sort mySort;
	testSort(mySort.insertionSort, "Insertion Sort");
	testSort(mySort.bubbleSort, "Bubble Sort");
	testSort(mySort.selectionSort, "Selection Sort");
	testSort(mySort.mergeSort, "Merge Sort");
}
```
