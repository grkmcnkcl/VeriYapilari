#include<stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>



void zamanFormatla(double a) {
	int saniye1, salise, saniye, dakika;	
	a *= 60;
	saniye1 = a;
	salise = saniye1;
	saniye = salise / 60;
	salise =salise% 60; 
	dakika = saniye / 60; 
	saniye = saniye % 60; 

	
	
	printf("\n %d:%d:%d\n\n\n",  dakika, saniye, salise);
}
struct MaxHeap
{
	int size;
	int* array;
};
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void maxHeapify(struct MaxHeap* maxHeap, int idx)
{
	int largest = idx;  // Initialize largest as root
	int left = (idx << 1) + 1;  // left = 2*idx + 1
	int right = (idx + 1) << 1; // right = 2*idx + 2

	// See if left child of root exists and is greater than
	// root
	if (left < maxHeap->size &&
		maxHeap->array[left] > maxHeap->array[largest])
		largest = left;

	// See if right child of root exists and is greater than
	// the largest so far
	if (right < maxHeap->size &&
		maxHeap->array[right] > maxHeap->array[largest])
		largest = right;

	// Change root, if needed
	if (largest != idx)
	{
		swap(&maxHeap->array[largest], &maxHeap->array[idx]);
		maxHeapify(maxHeap, largest);
	}
}

struct MaxHeap* createAndBuildHeap(int *array, int size)
{
	int i;
	struct MaxHeap* maxHeap =
		(struct MaxHeap*) malloc(sizeof(struct MaxHeap));
	maxHeap->size = size;   // initialize size of heap
	maxHeap->array = array; // Assign address of first element of array

	// Start from bottommost and rightmost internal mode and heapify all
	// internal modes in bottom up way
	for (i = (maxHeap->size - 2) / 2; i >= 0; --i)
		maxHeapify(maxHeap, i);
	return maxHeap;
}
void heapSort(int* array, int size)
{
	// Build a heap from the input data.
	struct MaxHeap* maxHeap = createAndBuildHeap(array, size);

	// Repeat following steps while heap size is greater than 1.
	// The last element in max heap will be the minimum element
	while (maxHeap->size > 1)
	{
		// The largest item in Heap is stored at the root. Replace
		// it with the last item of the heap followed by reducing the
		// size of heap by 1.
		swap(&maxHeap->array[0], &maxHeap->array[maxHeap->size - 1]);
		--maxHeap->size;  // Reduce heap size

		// Finally, heapify the root of tree.
		maxHeapify(maxHeap, 0);
	}
}


void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}





void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place    
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray 
	for (i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted array 
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element 
		swap(&arr[min_idx], &arr[i]);
	}
}

int binarySearch(int a[], int item, int low, int high)
{
	if (high <= low)
		return (item > a[low]) ? (low + 1) : low;

	int mid = (low + high) / 2;

	if (item == a[mid])
		return mid + 1;

	if (item > a[mid])
		return binarySearch(a, item, mid + 1, high);
	return binarySearch(a, item, low, mid - 1);
}

void binaryInsertionSort(int a[], int n)
{
	int i, loc, j, k, selected;

	for (i = 1; i < n; ++i)
	{
		j = i - 1;
		selected = a[i];

		// find location where selected sould be inseretd 
		loc = binarySearch(a, selected, 0, j);

		// Move all elements after location to create space 
		while (j >= loc)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = selected;
	}
}

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		  greater than key, to one position ahead
		  of their current position */
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];    // pivot 
	int i = (low - 1);  // Index of smaller element 

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot 
		if (arr[j] < pivot)
		{
			i++;    // increment index of smaller element 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		   at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before 
		// partition and after partition 
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int shellSort(int arr[], int n)
{
	// Start with a big gap, then reduce the gap 
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		// Do a gapped insertion sort for this gap size. 
		// The first gap elements a[0..gap-1] are already in gapped order 
		// keep adding one more element until the entire array is 
		// gap sorted  
		for (int i = gap; i < n; i += 1)
		{
			// add a[i] to the elements that have been gap sorted 
			// save a[i] in temp and make a hole at position i 
			int temp = arr[i];

			// shift earlier gap-sorted elements up until the correct  
			// location for a[i] is found 
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];

			//  put temp (the original a[i]) in its correct location 
			arr[j] = temp;
		}
	}
	return 0;
}

int main()
{
	int dizi[1000];
	int rastgele;
	int secenek;
	srand(time(NULL));
	clock_t begin, end;
	double a;

	printf("Siralama algoritmasi seciniz :\n");
	printf("Shell Sort(1)\n");
	printf("Heap Sort(2)\n");
	printf("Quick Sort(3)\n");
	printf("Bubble Sort(4)\n");
	printf("Selection Sort(5)\n");
	printf("Binary Insertion Sort(6)\n");
	printf("Straight Insertion Sort(7)\n");
	printf("Insertion Sort(8)\n");
	printf("Seciminiz :  ");
	scanf_s("%d", &secenek);
	
	switch (secenek) {
	case 1:

		for (int i = 0; i < 1000; i++)
		{
			rastgele = rand() % 500;
			dizi[i] = rastgele;
		}
		begin = clock();
		shellSort(dizi, 1000);
		end = clock();
		a = (double)(end - begin) / CLOCKS_PER_SEC;
		zamanFormatla(a);
			break;
	case 2:
		for (int i = 0; i < 1000; i++)
		{
			rastgele = rand() % 500;
			dizi[i] = rastgele;
		}
		
		begin = clock();
		heapSort(dizi, 1000);
		end = clock();
		a = (double)(end - begin) / CLOCKS_PER_SEC;
		zamanFormatla(a);
		
			break;
	case 3:
		for (int i = 0; i < 1000; i++)
		{
			rastgele = rand() % 500;
			dizi[i] = rastgele;
		}
		begin = clock();
		quickSort(dizi, 0, 999);
		end = clock();
		a = (double)(end - begin) / CLOCKS_PER_SEC;
		zamanFormatla(a);

		break;
	case 4:
		for (int i = 0; i < 1000; i++)
		{
			rastgele = rand() % 500;
			dizi[i] = rastgele;
		}
		
		begin = clock();
		bubbleSort(dizi, 1000);
		end = clock();
		a = (double)(end - begin) / CLOCKS_PER_SEC;
		zamanFormatla(a);
		
		
		break;
	case 5:
		for (int i = 0; i < 1000; i++)
		{
			rastgele = rand() % 500;
			dizi[i] = rastgele;
		}
		
		begin = clock();
		selectionSort(dizi, 1000);
		end = clock();
		a = (double)(end - begin) / CLOCKS_PER_SEC;
		zamanFormatla(a);
		
		break;
	case 6:
		for (int i = 0; i < 1000; i++)
		{
			rastgele = rand() % 500;
			dizi[i] = rastgele;
		}
		
		begin = clock();
		binaryInsertionSort(dizi, 1000);
		end = clock();
		a = (double)(end - begin) / CLOCKS_PER_SEC;
		zamanFormatla(a);
		break;
	case 7:
		for (int i = 0; i < 1000; i++)
		{
			rastgele = rand() % 500;
			dizi[i] = rastgele;
		}
		
		begin = clock();
		insertionSort(dizi, 1000);
		end = clock();
		a = (double)(end - begin) / CLOCKS_PER_SEC;
		zamanFormatla(a);
		break;
	case 8:
		for (int i = 0; i < 1000; i++)
		{
			rastgele = rand() % 500;
			dizi[i] = rastgele;
		}
		
		begin = clock();
		for (int i = 1; i < 1000; i++) 
		{ 
			int T = dizi[i];  
			int j = i; 
			while (j > 0 && dizi[j - 1] > T) 
			{
				dizi[j] = dizi[j - 1]; j--;
			}
			dizi[j] = T;
		}
		end = clock();
		a = (double)(end - begin) / CLOCKS_PER_SEC;
		zamanFormatla(a);
		break;

	default:
		printf("Gecersiz rakam girdiniz");
		break;
		
	}

	return 0;
}