#include <iostream>
#include <ctime>
#include <time.h>

using namespace std;

void printArray(int* a, int N) {
	for (int i = 0; i < N; i++) cout << " " << a[i];
}

void insertionSort(int* a, int N) {
	
	int check, j;

	clock_t begin = clock();

	for (size_t i = 0; i < N; i++)
	{
		check = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > check)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = check;
	}
	clock_t end = clock();
	double elapsed = double(end - begin);
	cout << "Time taken with N = " << N << " is " << elapsed << "ms = " << elapsed / 1000.0 << " s" << endl;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */

int partition(int *a, int first, int last) {
	int pivot = a[last];
	int leftwall = first - 1;
	for (int i = first; i < last; i++)
	{

		if (a[i] < pivot) {
			leftwall++;
			swap(a[leftwall], a[i]);
		}

	}
	swap(a[leftwall + 1], a[last]);
	return (leftwall + 1);
}


/* The main function that implements QuickSort
a --> Array to be sorted,
first--> Starting index,
last --> Ending index */
void quickSort(int *a, int first, int last) {
	if (first < last) {
		int partitioning_index = partition(a, first, last);
		quickSort(a, first, partitioning_index - 1);
		quickSort(a, partitioning_index + 1, last);
	}
}

template <typename T>
void bubbleSort(T *a, int N) {
	clock_t begin = clock();
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
		}
	}
	clock_t end = clock();
	double elapsed = double(end - begin);
	cout 
		<< "Time taken with N = " 
		<< N 
		<< " is " 
		<< elapsed 
		<< "ms = " 
		<< elapsed / 1000.0 
		<< " s" 
		<< 
		endl;
}

// To generate permuatation of the array 
void shuffle(int a[], int n)
{
	for (int i = 0; i < n; i++)
		swap(a[i], a[rand() % n]);
}

// Sorts array a[0..n-1] using Bogo sort 
void bogosort(int *a, int n)
{
	// if array is not sorted then shuffle 
	// the array again 
	while (!isSortedAscending(a, n))
		shuffle(a, n);
}

template <typename T> 
bool isSortedAscending(T* a, int N) {
	for (size_t i = 1; i < N; i++)
		if (a[i - 1] > a[i]) return false;
	return true;
}

template <typename T>
bool isSortedDescending(T* a, int N){
	for (size_t i = 1; i < N; i++)
		if (a[i - 1] < a[i]) return false;
	return true;

}

void selectionSort(int* a, int N) {
	for (int i = 0; i < N - 1; i++)
	{
		int min = i;
		for (int j = 0; j < N; j++)
			if (a[j] < a[min])
				min = j;
			swap(a[min], a[i]);
	}
}

int binarySearch(int* a, int l, int r, int x) {
	while (l <=  r) {
		int m = l - (l - r) / 2;
		if (a[m] == x) 
			return m;
		if (a[m] <= x) 
			l = m + 1;
		else 
			r = m - 1;
	}
	return -1;
}

int main() {

	

	int arr_unsorted[4] = { 3,2,1,4 };
	insertionSort(arr_unsorted, 4);
	//quickSort(arr_unsorted, 0, 3);

	printArray(arr_unsorted, 4);
	cout << endl;
	if (isSortedAscending(arr_unsorted, 4))
		cout << "Sorted" << endl;
	else
		cout << "Unsorted" << endl;
}