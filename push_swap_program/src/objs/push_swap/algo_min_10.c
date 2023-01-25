/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_min_10.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:09:11 by dthan             #+#    #+#             */
/*   Updated: 2023/01/25 21:25:59 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../../../../libft/includes/libft.h"

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

t_node *biggest_number(t_stack *stack)
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

unsigned int soft_sort(t_stack *from_stack, t_stack *to_stack)
{
	t_node *biggest_number_node = NULL;
	unsigned int operation_count = 0;

	while (from_stack->count == 0)
	{
		biggest_number_node = biggest_number(from_stack);
		operation_count += move_to_top(from_stack, biggest_number_node);
		operation_count += execute_instruction(from_stack, to_stack, "pa");
	}
	return operation_count;
}

unsigned int rough_sort_recursive(t_stack *from_stack, t_stack *to_stack, t_node *selected_note, t_node *biggest_number_node, int quotient_index)
{
	t_node *node = NULL;
	unsigned int operation_count = 0;
	int dirty = 1;

	while (!dirty)
	{
		node = from_stack->first_node;
		dirty = 0;
		while (node)
		{
			if (node->data <= selected_note->data && node != biggest_number_node)
			{
				operation_count += move_to_top();
				operation_count += execute_instruction(from_stack, to_stack, "pb");
				dirty = 1;
				break;
			}
			node = node->next;			
		}
	}
	if (from_stack->count > 1)
	{
		if (from_stack->count <= quotient_index)
			selected_note = from_stack->first_node;
		else
			selected_note = stack_get_node_at(from_stack, quotient_index);
		operation_count += rough_sort_recursive(from_stack, to_stack, from_stack->last_node, selected_note, quotient_index);
		
	}
	return operation_count;
}

// the key is finding the biggest number and left it at stack a
int rough_sort(t_stack *from_stack, t_stack *to_stack)
{
	int divisor = 4;
	int quotient_index = from_stack->count / 4;
	t_node *biggest_number_node = biggest_number(from_stack);
	t_node *selected_node = stack_get_node_at(from_stack, quotient_index);

	return rough_sort_recursive(from_stack, to_stack, selected_node, biggest_number_node, quotient_index);
}

int algo_min_10(t_push_swap *program)
{
	t_stack *stack_a = program->stack_a;
	t_stack *stack_b = program->stack_b;
	return rough_sort(stack_a, stack_b) + soft_sort(stack_b, stack_a);
}
