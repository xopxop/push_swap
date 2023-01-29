/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack-4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:30:03 by dthan             #+#    #+#             */
/*   Updated: 2023/01/29 21:02:43 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>
#include "../../libft/includes/libft.h"

t_node *stack_get_biggest_number_node(t_stack *stack)
{
	t_node *node = stack->first_node;
	t_node *biggest_number_node = NULL;

	while (node)
	{
		if (!biggest_number_node || biggest_number_node->data < node->data)
			biggest_number_node = node;
		node = node->next;
	}
	return biggest_number_node;
}

t_node *stack_get_smallest_number_node(t_stack *stack)
{
	t_node *smallest_number_node = NULL;
	t_node *node = stack->first_node;

	while (node)
	{
		if (!smallest_number_node || smallest_number_node->data > node->data)
			smallest_number_node = node;
		node = node->next;
	}
	return smallest_number_node;
}

t_node *stack_get_node_at(t_stack *stack, unsigned int index_pos)
{
	unsigned int index = 0;
	t_node *node = stack->first_node;

	while (index != index_pos)
	{
		node = node->next;
		index++;		
	}
	return node;
}

t_node *stack_get_closet_smaller_number_node(t_stack *stack, const t_node *number_node)
{
	t_node *node;
	t_node *closet_smaller_number_node;

	node = stack->first_node;
	closet_smaller_number_node = stack_get_smallest_number_node(stack);
	while (node)
	{
		if (node->data > closet_smaller_number_node->data && node->data < number_node->data)
			closet_smaller_number_node = node;
		node = node->next;
	}
	return (closet_smaller_number_node);
}

t_node *stack_get_closet_bigger_number_node(t_stack *stack, const t_node *number_node)
{
	t_node *node;
	t_node *closet_bigger_number_node;

	node = stack->first_node;
	closet_bigger_number_node = stack_get_biggest_number_node(stack);
	while (node)
	{
		if (node->data < closet_bigger_number_node->data && node->data > number_node->data)
			closet_bigger_number_node = node;
		node = node->next;
	}
	return (closet_bigger_number_node);
}

unsigned int stack_find_index(t_stack *stack, t_node *look_up_node)
{
	unsigned int index = 0;
	t_node *node = stack->first_node;

	while (node)
	{
		if (node == look_up_node)
			break;
		index++;
		node = node->next;
	}
	return index;
}
