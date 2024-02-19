#include "sort.h"

/**
 * swap - swaps 2 location in a list.
 * @array: int pointer to the array.
 * @a: first location of array to be swapped.
 * @b: second location of array to be swapped.
 *
 * Return: void.
 */
void swap(int a, int b, int *array)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

/**
 * create_partition - creates a partition (Lomuto) to
 * be quick sorted.
 * @array: int pointer to the array to be partitioned.
 * @begin: beginning of the array to be partitioned.
 * @end: ending of the array to be partitioned.
 * @size: the size of the whole list.
 *
 * Return: sorted pivot index.
 */
int create_partition(int *array, int begin, int end, int size)
{
	int pivot, i, j, pivotindex;

	(void)size;
	pivot = array[end];
	i = begin;
	j = end - 1;
	while (i <= j)
	{
		while (array[i] < pivot)
			i++;
	        while (array[j] >= pivot && j >= begin)
			j--;
		if (i < j)
		{
			swap (i, j, array);
			i++;
			j--;

			if (array[i] != array[j])
				print_array(array, size);
		}
	}
	pivotindex = i;
	swap(pivotindex, end, array);
	if (array[i] != array[end])
		print_array(array, size);
	return (pivotindex);
}

/**
 * sort - a recursive function that sorts the list
 * using the quick sort algorithm.
 * @array: int pointer to the array to be sorted.
 * @begin: beginning of the array to be sorted.
 * @end: ending of the array to be sorted.
 * @size: size of the whole list.
 *
 * Return: void.
 */
void sort(int *array, int begin, int end, int size)
{
	int splitloc;

	if (begin >= end || begin < 0 || end < 0)
		return;

	splitloc = create_partition(array, begin, end, size);

	/* Sort the left side after splitting */
	sort(array, begin, splitloc - 1, size);

	/* Sort the right side after splitting */
	sort(array, splitloc + 1, end, size);
}

/**
 * quick_sort_hoare - sorts an array using quick sort algorithm
 * and uses the Hoare partitioning scheme.
 * @array: int pointer to the array being sorted.
 * @size: the size of the array being sorted.
 *
 * Return: void.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sort(array, 0, size - 1, size);
}
