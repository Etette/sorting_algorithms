#include "sort.h"

/**
 * selection_sort - selection sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t count1, count2, min_index, tmp_swap;

	/*checks inputs*/
	if (array == NULL || size == 0)
	{
		return;
	}

	/*iterate through array*/
	for (count1 = 0; count1 < size - 1; count1++)
	{
		/*set current number to mi_index*/
		min_index = count1;

		/*find smallest number and set to min_index*/
		for (count2 = count1 + 1; count2 < size; count2++)
		{
			if (array[count2] < array[min_index])
				min_index = count2;
		}
		/* if current index is not the smallest element*/
		if (min_index != count1)
		{
			tmp_swap = array[min_index];
			array[min_index] = array[count1];
			array[count1] = tmp_swap;
			print_array(array, size);
		}
	}
}

