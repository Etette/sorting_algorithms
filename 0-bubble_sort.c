#include "sort.h"

/**
 * bubble_sort - sorts an array of inetgers
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t count1, count2;
	int tmp_swap, flag = 0;

	/*checks inputs*/
	if (array == NULL || size == 0)
		return;

	/*iterates current step in the sort*/
	for (count1 = 0; count1 < (size - 1); count1++)
	{
		/*Loops through the array*/
		for (count2 = 0; count2 < size - count1 - 1; count2++)
		{
			if (array[count2] > array[count2 + 1])
			{
				/*swap a[i] with a[i + 1]*/
				tmp_swap = array[count2 + 1];
				array[count2] = array[count2 + 1];
				array[count2 + 1] = tmp_swap;
				print_array(array, size);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
