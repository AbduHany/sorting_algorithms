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
 * shell_sort - sorts a list using the shell sort algorithm
 * using a Knuth squence gap.
 * @array: int pointer to the array to be sorted.
 * @size: the size of the array to be sorted.
 *
 * Return: void.
 */
void shell_sort(int *array, size_t size)
{
	int maxgap = 1, i, j;

	if (array == NULL || size < 2)
		return;
	while ((maxgap * 3 + 1) <= (int)size - 1)
		maxgap = (maxgap * 3) + 1;
	for (;maxgap > 0; maxgap = (maxgap - 1) / 3)
	{
		for (j = maxgap; j < (int)size; j++)
		{
			for (i = j - maxgap; i >= 0; i -= maxgap)
			{
				if (array[i + maxgap] > array[i])
					break;
				else
					swap(i, i + maxgap, array);
			}
		}
		print_array(array, size);
	}
}
