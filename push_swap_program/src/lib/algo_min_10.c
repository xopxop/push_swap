/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_min_10.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:09:11 by dthan             #+#    #+#             */
/*   Updated: 2023/01/29 17:22:24 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

#define DIVISOR 4

static unsigned int move_back_all_numbers_to_stack_a(t_push_swap *program)
{
	t_node *local_biggest_number_node = NULL;
	unsigned int operation_count = 0;

	while (program->data->stack_b->count > 0)
	{
		local_biggest_number_node = stack_get_biggest_number_node(program->data->stack_b);
		if (program->data->stack_b->first_node != local_biggest_number_node)
			operation_count += move_node_to_top(program->data, program->data->stack_b, local_biggest_number_node);
		operation_count += execute_instruction(program->data, "pa");
	}
	return operation_count;
}

static unsigned int rough_sort_stack_b_recursive(t_push_swap *program, t_node *selected_node, unsigned int selected_node_index)
{
	t_node *node = NULL;
	unsigned int operation_count = 0;
	int dirty = 1;

	while (dirty)
	{
		node = program->data->stack_a->first_node;
		dirty = 0;
		while (node)
		{
			if (node->data <= selected_node->data && \
				node != program->global_biggest_number_node && \
				node != program->global_second_biggest_number_node && \
				node != program->global_third_biggest_number_node)
			{
				if (program->data->stack_a->first_node != node)
					operation_count += move_node_to_top(program->data, program->data->stack_a, node);
				operation_count += execute_instruction(program->data, "pb");
				dirty = 1;
				break;
			}
			node = node->next;			
		}
	}
	if (program->data->stack_a->count > 3)
	{
		if (program->data->stack_a->count <= selected_node_index - 1)
			selected_node = program->data->stack_a->first_node;
		else
			selected_node = stack_get_node_at(program->data->stack_a, selected_node_index);
		operation_count += rough_sort_stack_b_recursive(program, selected_node, selected_node_index);
		
	}
	return operation_count;
}

static unsigned int move_all_numbers_to_stack_b_except_the_biggest_number(t_push_swap *program)
{
	unsigned int selected_node_index = program->data->stack_a->count / DIVISOR;
	t_node *selected_node = stack_get_node_at(program->data->stack_a, selected_node_index);

	return rough_sort_stack_b_recursive(program, selected_node, selected_node_index);
}

unsigned int algo_min_10(t_push_swap *program)
{
	unsigned int operation_count_step_1 = move_all_numbers_to_stack_b_except_the_biggest_number(program);
	unsigned int operation_count_step_2 = algo_max_3(program);
	unsigned int operation_count_step_3 = move_back_all_numbers_to_stack_a(program);
	return operation_count_step_1 + operation_count_step_2 + operation_count_step_3;
}
