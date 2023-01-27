/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_min_10.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:09:11 by dthan             #+#    #+#             */
/*   Updated: 2023/01/26 23:39:26 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../../../../libft/includes/libft.h"

#define DIVISOR 4

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

unsigned int rough_sort_recursive(t_stack *from_stack, t_stack *to_stack, t_data_holder data_holder)
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
			if (node->data <= data_holder.selected_node->data && node != data_holder.biggest_number_node)
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
		if (from_stack->count <= data_holder.selected_node_index)
			data_holder.selected_node = from_stack->first_node;
		else
			data_holder.selected_node = stack_get_node_at(from_stack, data_holder.selected_node_index);
		operation_count += rough_sort_recursive(from_stack, to_stack, data_holder);
		
	}
	return operation_count;
}

// the key is finding the biggest number and left it at stack a
int rough_sort(t_stack *from_stack, t_stack *to_stack)
{
	int selected_node_index = from_stack->count / DIVISOR;
	t_node *selected_node = stack_get_node_at(from_stack, data_holder.selected_node_index);

	return rough_sort_recursive(from_stack, to_stack, data_holder);
}

int algo_min_10(t_push_swap *program)
{
	t_stack *stack_a = program->stack_a;
	t_stack *stack_b = program->stack_b;
	return rough_sort(stack_a, stack_b) + soft_sort(stack_b, stack_a);
}
