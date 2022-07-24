#include "sort.h"

void _sort(int *arr, size_t left, size_t right, int *tmp);
void _merge(int *arr, size_t left, size_t mid, size_t right, int *tmp);
void _copy(int *arr, int *tmp, size_t size);

/**
 * merge_sort - performs merge sort
 * @array: array
 * @size: size
 */

void merge_sort(int *array, size_t size)
{
	int *tmp = malloc(size * sizeof(int));

	if (!tmp)
		return;
	if (array && size > 1)
		_sort(array, 0, size - 1, tmp);
	free(tmp);
}

/**
 * _sort - break array into sub arrays
 * @arr: array
 * @left: left of array
 * @right: right of array
 * @tmp: buffer
 */
void _sort(int *arr, size_t left, size_t right, int *tmp)
{
	size_t mid, size = (right + 1) - left;

	if (size == 1)
		return;
	mid = left + ((size / 2) - 1);
	_sort(arr, left, mid, tmp);
	_sort(arr, mid + 1, right, tmp);

	_merge(arr, left, mid, right, tmp);
}

/**
 * _merge - merge sub_arrays
 * @arr: array
 * @left: left boundary
 * @mid: pivot btw left anf right
 * @right: right boundary
 * @tmp: buffer
 */
void _merge(int *arr, size_t left, size_t mid, size_t right, int *tmp)
{
	size_t i_l = mid, i_r = right, j = right - left;
	int l_merge = 0;

	printf("Merging..\n[left]: ");
	print_array(&arr[left], (mid + 1) - left);
	printf("[right]: ");
	print_array(&arr[mid + 1], (right + 1) - (mid + 1));

	for (; i_l >= left && i_r >= mid + 1;)
	{
		if (arr[i_r] >= arr[i_l])
			tmp[j--] = arr[i_r--];
		else
		{
			tmp[j--] = arr[i_l];
			if (i_l == 0)
			{
				l_merge = 1;
				break;
			}
			i_l--;
		}
	}

	for (; i_r >= mid + 1;)
		tmp[j--] = arr[i_r--];
	for (; !l_merge && i_l >= left;)
	{
		tmp[j--] = arr[i_l];
		if (i_l == 0)
			break;
		i_l--;
	}
	_copy(&arr[left], tmp, (right + 1) - left);
	printf("[Done]: ");
	print_array(&arr[left], (right + 1) - left);
}

/**
 * _copy - copy array of same size
 * @arr: array
 * @tmp: copy source
 * @size: size of array
 */
void _copy(int *arr, int *tmp, size_t size)
{
	size_t i = 0;
	
	for (; i < size; i++)
		arr[i] = tmp[i];
}
