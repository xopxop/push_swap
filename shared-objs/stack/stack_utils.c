/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:28:07 by dthan             #+#    #+#             */
/*   Updated: 2023/04/05 16:45:47 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_get_index(t_stack *stack, int number)
{
	int	index;

	index = 0;
	while (index < stack->length)
	{
		if (stack->data[index] == number)
			break ;
		index++;
	}
	return (index);
}

int	stack_get_biggest_number(t_stack *stack)
{
	int	index;
	int	biggest_number;

	index = 0;
	while (index < stack->length)
	{
		if (index == 0 || biggest_number < stack->data[index])
			biggest_number = stack->data[index];
		index++;
	}
	return (biggest_number);
}

int	stack_get_closet_bigger_number(t_stack *stack, const int number)
{
	int	index;
	int	closet_bigger_number;

	index = 0;
	closet_bigger_number = stack_get_biggest_number(stack);
	while (index < stack->length)
	{
		if (stack->data[index] < closet_bigger_number && \
			stack->data[index] > number)
			closet_bigger_number = stack->data[index];
		index++;
	}
	return (closet_bigger_number);
}

int	stack_get_smallest_number(t_stack *stack)
{
	int	index;
	int	smallest_number;

	index = 0;
	while (index < stack->length)
	{
		if (index == 0 || smallest_number > stack->data[index])
			smallest_number = stack->data[index];
		index++;
	}
	return (smallest_number);
}
