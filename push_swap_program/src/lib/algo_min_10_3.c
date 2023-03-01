#include "lib.h"

// int *copy_stack_to_list(t_stack *stack)
// {
// 	t_node *node = stack->first_node;
// 	int *number_list = (int*)malloc(sizeof(int) * stack->count);
// 	int index = 0;

// 	while (node)
// 	{
// 		number_list[index] = node->data;
// 		index++;
// 		node = node->next;
// 	}
// 	return number_list;
// }

void copy_stack_to_list(int array[], t_stack *stack)
{
	t_node *node = stack->first_node;
	int index = 0;

	while (node)
	{
		array[index] = node->data;
		index++;
		node = node->next;
	}
}

void merge(int *arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
  
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

  i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j]) 
		{
			arr[k] = L[i];
			i++;
		}
		else 
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int *arr, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

#include <stdio.h>
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int get_half_number(t_stack *stack)
{
	int number_list[stack->count];
	//int *number_list = copy_stack_to_list(stack);
	copy_stack_to_list(number_list, stack);

	mergeSort(number_list, 0, stack->count - 1);
	printArray(number_list, stack->count);
	return (number_list[stack->count / 2]);
}

unsigned int algo_min_10_3(t_push_swap *program)
{
	// finding the half number
	int half_number = get_half_number(program->data->stack_a);
	(void)half_number;
	// move all numbers which is below than the half number to B
	// sort A and B
	// move all numbers from B back to A
	return (0);
}