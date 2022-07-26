#include "sort.h"

int recurrences(int *array, size_t size, int range);

/**
 * recurrences - count number of time value in list
 * @array: array
 * @size: size of array
 * @range: distance btw largest numbers
 * Return: void
 */

int recurrences(int *array, size_t size, int range)
{
	int total = 0;
	size_t count;

	for (count = 0; count < size; count++)
	{
		if (array[count] == range)
			total++;
	}
	return (total);
}

/**
 * counting_sort - sorts array in ascending order
 * @array: array
 * @size: size of the array
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	size_t count1, count2;
	int largest_num = 0, range = 0, tmp = 0;
	int *count_array, *sorted_array;

	if (!array || size < 2)
		return;

	/* find largest num in list*/
	for (count1 = 0; count1 < size; count1++)
	{
		if (array[count1] > largest_num)
			largest_num = array[count1];
	}

	/* init count_array as size of laest num*/
	count_array = malloc(sizeof(int) * (largest_num + 1));

	if (!count_array)
		return;

	/* count recurrence number within range of largest number */
	for (count2 = 0; count2 < ((size_t)largest_num + 1); count2++)
	{
		if (count2 == 0)
			count_array[count2] = recurrences(array, size, range);
		else
		{
			tmp = count_array[count2 - 1] + recurrences(array, size, range);
			count_array[count2] = tmp;
		}
		range++;
	}
	print_array(count_array, (largest_num + 1));

	/*init array to return sorted list*/
	sorted_array = malloc(sizeof(int) * size);

	if (!sorted_array)
	{
		free(count_array);
		return;
	}
	for (count1 = 0; count1 < size; count1++)
	{
		sorted_array[count_array[array[count1]] - 1] = array[count1];
		count_array[array[count1]]--;
	}
	for (count1 = 0; count1 < size; count1++)
	{
		array[count1] = sorted_array[count1];
	}
	free(count_array);
	free(sorted_array);
}
