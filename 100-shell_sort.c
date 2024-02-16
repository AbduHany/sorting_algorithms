#include "sort.h"

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
	int maxgap = 1, i, temp, j, k;

	if (array == NULL || size < 2)
		return;
	while (maxgap * 3 + 1 <= (int)size - 1)
	{
		maxgap = maxgap * 3 + 1;
	}
	while (maxgap > 0)
	{
		for (i = 0; (i + maxgap) < (int)size; i++)
		{
			if (array[i] > array[i + maxgap])
			{
				temp = array[i];
				array[i] = array[i + maxgap];
				array[i + maxgap] = temp;
				j = i - maxgap;
				k = i;
				while (j >= 0)
				{
					if (array[j] > array[k])
					{
						temp = array[j];
						array[j] = array[k];
						array[k] = temp;
					}
					else
						break;
					k--;
					j -= maxgap;
				}
			}
		}
		print_array(array, size);
		maxgap = (maxgap - 1) / 3;
	}
}
