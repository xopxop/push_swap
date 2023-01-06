/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack-2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:38:27 by dthan             #+#    #+#             */
/*   Updated: 2022/11/28 11:41:00 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stddef.h>

t_node	*stack_pop(t_stack *stack)
{
	t_node	*node;

	if (stack->count == 1)
	{
		node = stack->first_node;
		stack->first_node = NULL;
	}
	else if (stack->count == 2)
	{
		node = stack->last_node;
		stack->first_node->next = NULL;
		stack->last_node = NULL;
		node->prev = NULL;
	}
	else
	{
		node = stack->last_node;
		stack->last_node = stack->last_node->prev;
		stack->last_node->next = NULL;
		node->prev = NULL;
	}
	stack->count--;
	return (node);
}

t_node	*stack_pop_top(t_stack *stack)
{
	t_node	*node;

	node = stack->first_node;
	if (stack->count == 1)
		stack->first_node = NULL;
	else if (stack->count == 2)
	{
		stack->first_node = stack->last_node;
		stack->first_node->prev = NULL;
		stack->last_node = NULL;
		node->next = NULL;
	}
	else
	{
		stack->first_node = stack->first_node->next;
		stack->first_node->prev = NULL;
		node->next = NULL;
	}
	stack->count--;
	return (node);
}

void	stack_push(t_stack *stack, t_node *node)
{
	if (stack->count == 0)
		stack->first_node = node;
	else if (stack->count == 1)
	{
		stack->first_node->next = node;
		node->prev = stack->first_node;
		stack->last_node = node;
	}
	else
	{
		stack->last_node->next = node;
		node->prev = stack->last_node;
		stack->last_node = node;
	}
	stack->count++;
}

void	stack_push_top(t_stack *stack, t_node *node)
{
	if (stack->count == 0)
		stack->first_node = node;
	else if (stack->count == 1)
	{
		stack->last_node = stack->first_node;
		stack->first_node = node;
		stack->first_node->next = stack->last_node;
		stack->last_node->prev = stack->first_node;
	}
	else
	{
		node->next = stack->first_node;
		stack->first_node->prev = node;
		stack->first_node = node;
	}
	stack->count++;
}

void	stack_swap(t_stack *stack)
{
	t_node	*first_node;
	t_node	*second_node;

	first_node = stack->first_node;
	if (stack->count == 2)
	{
		second_node = stack->last_node;
		first_node->next = NULL;
		first_node->prev = second_node;
		second_node->prev = NULL;
		second_node->next = first_node;
		stack->first_node = second_node;
		stack->last_node = first_node;
	}
	else
	{
		second_node = first_node->next;
		first_node->next = second_node->next;
		first_node->prev = second_node;
		first_node->next->prev = first_node;
		second_node->prev = NULL;
		second_node->next = first_node;
		stack->first_node = second_node;
	}
}
