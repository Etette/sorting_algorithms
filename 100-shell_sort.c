#include "sort.h"

/**
 * knuth_seq - find largest gap of given size
 * @size: size of the array
 * Return: void
 */
size_t knuth_seq(size_t size)
{
	size_t counter;

	for (counter = 1; counter < size; counter = (counter * 3) + 1)
		;
	return ((counter - 1) / 3);
}

/**
 * shell_sort - sorts an array of integers
 * @array: array to be sorted
 * @size: size of array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int tmp;

	/*checks inputs*/
	if (array == NULL || size == 0)
		return;

	/*begins gap at largest knuth seq, for each pass, reduce by 1/3*/
	for (gap = knuth_seq(size); gap; gap = (gap - 1) / 3)
	{
		/* check elements to the right of the gap*/
		for (i = gap; i < size; i++)
		{
			tmp = array[i];

			/*shift gapped elem left until array[i] is in correct index*/
			for (j = i; j > gap - 1 && array[j - gap] > tmp; j -= gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
