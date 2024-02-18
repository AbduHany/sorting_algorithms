#include "sort.h"

/**
 * make_heap - transforms the array into a heap using the
 * siftdown method.
 * @array: the array to be transformed.
 

/**
 * heap_sort - sorts an array by creating a heap out of an array
 * then deleting elements from the heap which leaves a sorted array
 * behind.
 * @array: int pointer to the array being sorted.
 * @size: the size of the array.
 *
 * Return: void.
 */
void heap_sort(int *array, size_t size)
{
	int i, child1, child2, maxidx, temp;


	/* Creates a heap from the array */
	for (i = size - 1; i >= 0; i--)
	{
		child1 = (i * 2) + 1;
		child2 = (i * 2) + 2;
		if (child1 < (int)size && child2 < (int)size)
			maxidx = array[child1] > array[child2] ? child1 : child2;
		else if (child1 < (int)size)
			maxidx = child1;
		else
			continue;
		if (array[maxidx] > array[i])
		{
			temp = array[i];
			array[i] = array[maxidx];
			array[maxidx] = temp;
			print_array(array, size);
		}
        }
}
