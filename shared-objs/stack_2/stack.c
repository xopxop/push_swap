/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:05:50 by dthan             #+#    #+#             */
/*   Updated: 2023/03/21 16:25:02 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

int stack_pop(t_stack *stack)
{
	int element;
	int index = 0;

	element = stack->data[0];
	while (index < stack->length - 1)
	{
		stack->data[index] = stack->data[index + 1];
		index++;
	}
	stack->length--;
	return element;
}

void	stack_push(t_stack *stack, int element)
{
	int index = 0;
	int temp_a;
	int temp_b;

	while (index < stack->length + 1)
	{
		if (index == 0)
		{
			temp_a = stack->data[index + 1];
			stack->data[index + 1] = stack->data[index];
		}
		else
		{
			temp_b = stack->data[index + 1];
			stack->data[index + 1] = temp_a;
			temp_a = temp_b;
		}
		index++;
	}
	stack->data[0] = element;
	stack->length++;
}

void	stack_swap(t_stack *stack)
{
	int temp;

	stack->data[1] = temp;
	stack->data[1] = stack->data[0];
	stack->data[0] = temp;
}

int	stack_constructor_simple(t_stack *stack, unsigned int size)
{
	unsigned int *ptr;

	stack->data = (int*)malloc(sizeof(int) * size);
	stack->length = 0;
	ptr = &(stack->size);
	*ptr = size;
	stack->name = ft_strdup("b");
	return (CONSTRUCTOR_SUCCESS);
}

int	stack_constructor_complex(t_stack *stack, char **inputs, unsigned int size)
{
	int *ptr;

	ptr = &stack->size;
	*ptr = size;
	stack->data = (int*)malloc(sizeof(int) * size);
	stack->length = 0;
	stack->name = ft_strdup("a");
	while (inputs[stack->length])
	{
		if (is_number(inputs[stack->length]) && !is_dup(inputs[stack->length], stack))
			stack_push(stack, inputs[stack->length]);
		else
			return (CONSTRUCTOR_FAILED);
		stack->length++;
	}
	return (CONSTRUCTOR_SUCCESS);
}

t_stack	*new_stack(char **inputs, unsigned int size)
{
	t_stack *stack = (t_stack*)malloc(sizeof(t_stack));
	if (!inputs)
		stack_constructor_simple(stack, size);
	else if (stack_constructor_complex(stack, inputs, size) == CONSTRUCTOR_FAILED)
		return (stack_destructor(stack));
	return (stack);
}
