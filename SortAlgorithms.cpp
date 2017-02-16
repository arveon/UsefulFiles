#include <iostream>
#include <string>

using namespace std;

void bubbleSort(int*, int);
void selectSort(int*, int);
void insertSort(int*, int);

void printArray(int*, int);


int main()
{
	int arr[9] = {25, 15, 146, 220, 1, 0, 9, 35, 4};
	int size = 9;
	
	cout << "Before sort: " << endl;
	printArray(arr, size);
	//bubbleSort(arr, size);
	//selectSort(arr, size);
	insertSort(arr, size);

	cout << "\nAfter sort: " << endl;
	printArray(arr, size);

	string asd;
	getline(cin, asd);
	return 0;
}


//space complexity - O(1)
//time complexity - O(n^2)
void bubbleSort(int* a, int n)
{
	//loop through every element of the array
	for (int i = 0; i < n; i++)
	{
		//loop through all of the elements that come before this element
		for (int j = 0; j < i; j++)
		{
			//compare the previous elements with the current one and swap them if the previous element is bigger
			if (a[j] > a[i])
			{
				//swap the neighbours using only two variables
				a[j] += a[i];
				a[i] = a[j] - a[i];
				a[j] -= a[i];
			}
		}
	}
}

//space complexity - O(1)
//time complexity - O(n^2)
void selectSort(int* a, int n)
{
	//loop through every element of the array
	for (int i = 0; i < n; i++)
	{
		//index of the lowest number in the unsorted part of the array
		int min_index = i;
		//loop through every other element of the unsorted part of the array
		for (int j = i + 1; j < n; j++)
		{
			//if element smaller than the current element at min_index is found, store it's index instead
			if (a[j] < a[min_index]) min_index = j;
		}
		//if the element smaller than the current one is found, swap it with the current element
		if (min_index != i)
		{
			a[i] += a[min_index];
			a[min_index] = a[i] - a[min_index];
			a[i] -= a[min_index];
		}
	}
		

}

//space complexity - O(1)
//time complexity - Worst Case: O(n^2)
//					Best Case: O(n)
void insertSort(int* a, int n)
{
	//loop through every element of the array
	for (int i = 0; i < n; i++)
	{
		int key_id = i;//element that is currently being processed
		//loop through all elements before it and swap it left if it's smaller than element on its left
		while (key_id > 0 && a[key_id] < a[key_id - 1])
		{
			//swap two elements
			int temp = a[key_id];
			a[key_id] = a[key_id-1];
			a[key_id - 1] = temp;
			key_id--;//set the key element to the previous element of the array (where the key got moved to)
		}
	}
}



void printArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << endl;
}