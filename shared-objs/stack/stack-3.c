/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack-3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:42:10 by dthan             #+#    #+#             */
/*   Updated: 2023/01/27 17:12:15 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

t_stack	*stack_destructor(t_stack *stack)
{
	t_node	*node;

	if (stack->first_node)
	{
		while (stack->first_node)
		{
			node = stack->first_node;
			stack->first_node = stack->first_node->next;
			free(node);
		}
	}
	free(stack->name);
	free(stack);
	return (NULL);
}

int	stack_is_empty(t_stack *stack)
{
	return (!stack->count);
}

int	stack_is_ascending_sorted(t_stack *stack)
{
	t_node	*node_a;
	t_node	*node_b;

	node_a = stack->first_node;
	while (node_a && node_a->next)
	{
		node_b = node_a->next;
		if (node_a->data > node_b->data)
			return (0);
		node_a = node_a->next;
	}
	return (1);
}

int	stack_is_descending_sorted(t_stack *stack)
{
	t_node	*node_a;
	t_node	*node_b;

	node_a = stack->first_node;
	while (node_a && node_a->next)
	{
		node_b = node_a->next;
		if (node_a->data < node_b->data)
			return (0);
		node_a = node_a->next;
	}
	return (1);
}
