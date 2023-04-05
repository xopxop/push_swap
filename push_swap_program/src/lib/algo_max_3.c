/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_max_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:05:12 by dthan             #+#    #+#             */
/*   Updated: 2023/04/05 17:22:53 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../objs/push_swap/push_swap.h"
#include "../../../libft/includes/libft.h"
#define ASCENDING 0
#define DESCENDING 1

static int	can_rotate(t_stack *stack, int order)
{
	if (stack->length > 2)
	{
		if (order == ASCENDING)
		{
			if (
				stack->data[0] > stack->data[1] && \
				stack->data[0] > stack->data[stack->length - 1]
			)
				return (1);
		}
		else if (order == DESCENDING)
		{
			if (
				stack->data[0] < stack->data[1] && \
				stack->data[0] < stack->data[stack->length - 1]
			)
				return (1);
		}
	}
	return (0);
}

static int	can_reverse_rotate(t_stack *stack, int order)
{
	if (stack->length > 2)
	{
		if (order == ASCENDING)
		{
			if (
				stack->data[0] > stack->data[stack->length - 1] && \
				stack->data[0] < stack->data[1]
			)
				return (1);
		}
		else if (order == DESCENDING)
		{
			if (
				stack->data[0] < stack->data[stack->length - 1] && \
				stack->data[0] > stack->data[1]
			)
				return (1);
		}
	}
	return (0);
}

void	algo_max_3(t_push_swap *program)
{
	t_stack	*stack_a;
	char	*instruction;

	stack_a = program->data->stack_a;
	instruction = NULL;
	while (!stack_is_sorted_in_ascending_order(stack_a))
	{
		if (can_rotate(stack_a, ASCENDING))
			instruction = ft_strjoin("r", stack_a->name);
		else if (can_reverse_rotate(stack_a, ASCENDING))
			instruction = ft_strjoin("rr", stack_a->name);
		else
			instruction = ft_strjoin("s", stack_a->name);
		data_execute_instruction(program->data, instruction);
		free(instruction);
	}
}
