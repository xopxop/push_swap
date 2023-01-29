/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_min_10_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:15:11 by dthan             #+#    #+#             */
/*   Updated: 2023/01/29 21:03:28 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

unsigned int organize_stack_b(t_data *data, t_node *will_be_pushed_node)
{
	unsigned int operation_count = 0;
	t_node *closet_bigger_number_node;

	if (data->stack_b->count > 1)
	{
		closet_bigger_number_node = stack_get_closet_bigger_number_node(data->stack_b, will_be_pushed_node);
		if (closet_bigger_number_node != data->stack_b->last_node)
			operation_count = move_node_to_top(data, data->stack_b, closet_bigger_number_node);
	}
	return operation_count;	
}

unsigned int move_most_of_the_node_to_stack_b(t_push_swap *program)
{
	t_node *node;
	unsigned int operation_count = 0;

	while (program->data->stack_a->count > 3)
	{
		node = program->data->stack_a->first_node;
		if (node == program->global_biggest_number_node || \
			node == program->global_second_biggest_number_node || \
			node == program->global_third_biggest_number_node
		)
			operation_count = execute_instruction(program->data, "ra");
		else
		{
			operation_count = organize_stack_b(program->data, node);
			operation_count = execute_instruction(program->data, "pb");
		}
	}
	t_node *local_biggest_number_node = stack_get_biggest_number_node(program->data->stack_b);
	operation_count = move_node_to_top(program->data, program->data->stack_b, local_biggest_number_node);	
	return operation_count;
}

static unsigned int move_back_all_numbers_to_stack_a(t_push_swap *program)
{
	unsigned int operation_count = 0;
	while (program->data->stack_b->count > 0)
		operation_count = execute_instruction(program->data, "pa");
	return operation_count;
}

unsigned int algo_min_10_2(t_push_swap *program)
{
	unsigned int operation_count_step_1 = move_most_of_the_node_to_stack_b(program);
	unsigned int operation_count_step_2 = algo_max_3(program);
	unsigned int operation_count_step_3 = move_back_all_numbers_to_stack_a(program);

	return operation_count_step_1 + operation_count_step_2 + operation_count_step_3;
}
