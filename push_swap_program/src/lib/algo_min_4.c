/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo-min-4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:15:10 by dthan             #+#    #+#             */
/*   Updated: 2023/04/04 23:03:29 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../objs/push_swap/push_swap.h"
#include "../objs/move/move.h"
#include "algo_tool.h"

static void	organize_stack_a(t_data *data)
{
	int		smallest_number;
	int		index_a;
	int		rotate_a;
	t_move	*move;

	smallest_number = stack_get_smallest_number(data->stack_a);
	index_a = stack_get_index(data->stack_a, smallest_number);
	if (index_a <= data->stack_a->length / 2)
		rotate_a = index_a;
	else
		rotate_a = -(data->stack_a->length - index_a);
	move = new_move_object(rotate_a, 0);
	execute_the_best_move(data, move);
	delete_move_object(move);
}

static void	real_sort(t_push_swap *program)
{
	t_move	*best_move;

	while (program->data->stack_b->length != 0)
	{
		best_move = find_the_best_move(program->data);
		execute_the_best_move(program->data, best_move);
		data_execute_instruction(program->data, "pa");
		delete_move_object(best_move);
	}
}

static void	pre_sort(t_push_swap *program)
{
	int	biggest_number;
	int	smallest_number;
	int	operation_count;

	biggest_number = stack_get_biggest_number(program->data->stack_a);
	smallest_number = stack_get_smallest_number(program->data->stack_a);
	operation_count = 0;
	while (program->data->stack_a->length > 2)
	{
		if (
			program->data->stack_a->data[0] == biggest_number || \
			program->data->stack_a->data[0] == smallest_number
		)
			operation_count += data_execute_instruction(program->data, "ra");
		else
			operation_count += data_execute_instruction(program->data, "pb");
	}
	return (operation_count);
}

void	algo_min_4(t_push_swap *program)
{
	if (stack_is_sorted_in_ascending_order(program->data->stack_a))
		return (0);
	pre_sort(program);
	real_sort(program);
	organize_stack_a(program->data);
}
