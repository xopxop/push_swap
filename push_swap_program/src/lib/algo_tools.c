/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:42:03 by dthan             #+#    #+#             */
/*   Updated: 2023/01/27 19:43:47 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int can_swap(t_stack *stack, int order)
{
	if (stack->count > 1)
	{
		if (order == ASCENDING)
		{
			if (stack->first_node->data > stack->first_node->next->data)
				return (1);
		}
		else if (order == DESCENDING)
		{
			if (stack->first_node->data < stack->first_node->next->data)
				return (1);
		}
	}
	return (0);
}

int can_rotate(t_stack *stack, int order)
{
	if (stack->count > 2)
	{
		if (order == ASCENDING)
		{
			if (stack->first_node->data > stack->first_node->next->data && \
			stack->first_node->data > stack->last_node->data)
				return (1);
		}
		else if (order == DESCENDING)
		{
			if (stack->first_node->data < stack->first_node->next->data && \
			stack->first_node->data < stack->last_node->data)
				return (1);
		}
	}
	return (0);
}

int	can_reverse_rotate(t_stack *stack, int order)
{
	if (stack->count > 2)
	{
		if (order == ASCENDING)
		{
			if (stack->first_node->data > stack->last_node->data && \
			stack->first_node->data < stack->first_node->next->data)
				return (1);
		}
		else if (order == DESCENDING)
		{
			if (stack->first_node->data < stack->last_node->data && \
			stack->first_node->data > stack->first_node->next->data)
				return (1);
		}
	}
	return (0);
}

unsigned int move_node_to_top(t_stack *stack, t_node *node)
{
	int node_index = stack_find_index(stack, node);
	int proximity = stack->count / 2;
	char *instruction;
    unsigned int operation_count = 0;
	
	if (node_index >= proximity)
		instruction = "ra";
	else
		instruction = "rra";
	while (stack->first_node == node)
		operation_count += execute_instruction(stack, NULL, instruction);
    return operation_count;
}
