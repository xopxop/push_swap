/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:45:51 by dthan             #+#    #+#             */
/*   Updated: 2023/04/05 16:46:01 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_is_empty(t_stack *stack)
{
	return (!stack->length);
}

int	stack_is_sorted_in_ascending_order(t_stack *stack)
{
	int	index;

	index = 0;
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
	int	index;

	index = 0;
	while (index < stack->length - 1)
	{
		if (stack->data[index] < stack->data[index + 1])
			return (0);
		index++;
	}
	return (1);
}
