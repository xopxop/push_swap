/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack-operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:27:30 by dthan             #+#    #+#             */
/*   Updated: 2023/04/05 16:49:32 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_pop(t_stack *stack)
{
	int	element;
	int	index;

	index = 0;
	element = stack->data[0];
	while (index < stack->length - 1)
	{
		stack->data[index] = stack->data[index + 1];
		index++;
	}
	stack->length--;
	return (element);
}

void	stack_push(t_stack *stack, int element)
{
	int	index;
	int	temp_a;
	int	temp_b;

	index = 0;
	while (index < stack->length + 1)
	{
		if (index == 0)
		{
			temp_a = stack->data[index];
			stack->data[index] = element;
		}
		else
		{
			temp_b = stack->data[index];
			stack->data[index] = temp_a;
			temp_a = temp_b;
		}
		index++;
	}
	stack->length++;
}

void	stack_add(t_stack *stack, int element)
{
	stack->data[stack->length] = element;
	stack->length++;
}

int	stack_reduce(t_stack *stack)
{
	stack->length--;
	return (stack->data[stack->length]);
}

void	stack_swap(t_stack *stack)
{
	int	temp;

	temp = stack->data[1];
	stack->data[1] = stack->data[0];
	stack->data[0] = temp;
}
