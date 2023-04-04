/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo-min-4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:15:10 by dthan             #+#    #+#             */
/*   Updated: 2023/04/04 15:49:32 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../objs/push_swap/push_swap.h"
#include "../objs/move/move.h"
#include "algo-tool.h"
#include <stdio.h>


static int organize_stack_a(t_data *data)
{
	int smallest_number = stack_get_smallest_number(data->stack_a);
	int index_a = stack_get_index(data->stack_a, smallest_number);
	int rotate_a = (index_a <= data->stack_a->length / 2) ? index_a : -(data->stack_a->length - index_a);
	t_move *move = new_move_object(rotate_a, 0);
	int operation_count = execute_the_best_move(data, move);
	free(move);
	return operation_count;
}

static int real_sort(t_push_swap *program)
{
	t_move *best_move;
	int operation_count = 0;

	while (program->data->stack_b->length != 0)
	{
		best_move = find_the_best_move(program->data);
		operation_count += execute_the_best_move(program->data, best_move);
		operation_count	+= data_execute_instruction(program->data, "pa");
		// use delete object not free
		free(best_move);
	}
	return operation_count;
}

static int pre_sort(t_push_swap *program)
{
	int biggest_number = stack_get_biggest_number(program->data->stack_a);
	int smallest_number = stack_get_smallest_number(program->data->stack_a);
	int operation_count = 0;

	while (program->data->stack_a->length > 2)
	{
		if (program->data->stack_a->data[0] == biggest_number || program->data->stack_a->data[0] == smallest_number)
			operation_count += data_execute_instruction(program->data, "ra");
		else
			operation_count += data_execute_instruction(program->data, "pb");
	}
	return operation_count;
}

int algo_min_4(t_push_swap *program)
{
	if (stack_is_sorted_in_ascending_order(program->data->stack_a))
		return (0);
	int operation_count_step_1 = pre_sort(program);
	int operation_count_step_2 = real_sort(program);
	int operation_count_step_3 = organize_stack_a(program->data);

	return operation_count_step_1 + operation_count_step_2 + operation_count_step_3;
}