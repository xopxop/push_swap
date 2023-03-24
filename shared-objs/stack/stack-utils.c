/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack-utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:28:07 by dthan             #+#    #+#             */
/*   Updated: 2023/03/23 17:01:25 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int stack_get_index(t_stack *stack, int number)
{
	int index = 0;

	while (index < stack->length)
	{
		if (stack->data[index] == number)
			break;
		index++;
	}
	return (index);
}

int stack_get_biggest_number(t_stack *stack)
{
	int index = 0;
	int biggest_number;

	while (index < stack->length)
	{
		if (index == 0 || biggest_number < stack->data[index])
			biggest_number = stack->data[index];
		index++;
	}
	return biggest_number;
}

int stack_get_closet_bigger_number(t_stack *stack, const int number)
{
	int index = 0;
	int closet_bigger_number;

	closet_bigger_number = stack_get_biggest_number(stack);
	while (index < stack->length)
	{
		if (stack->data[index] < closet_bigger_number && stack->data[index] > number)
			closet_bigger_number = stack->data[index];
		index++;
	}
	return (closet_bigger_number);
}

int stack_get_smallest_number(t_stack *stack)
{
	int index = 0;
	int smallest_number;

	while (index < stack->length)
	{
		if (index == 0 || smallest_number > stack->data[index])
			smallest_number = stack->data[index];
		index++;
	}
	return smallest_number;
}

int	stack_is_empty(t_stack *stack)
{
	return (!stack->length);
}

int	stack_is_sorted_in_ascending_order(t_stack *stack)
{
	int	index = 0;

	while (index < stack->length - 1)
	{
		if (stack->data[index] > stack->data[index + 1])
			return (0);
		index++;
	}
	return (1);
}

int	stack_is_descending_sorted(t_stack *stack)
{
	int	index = 0;

	while (index < stack->length - 1)
	{
		if (stack->data[index] < stack->data[index + 1])
			return (0);
		index++;
	}
	return (1);
}
