/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack-4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:30:03 by dthan             #+#    #+#             */
/*   Updated: 2023/01/26 23:31:33 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

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
