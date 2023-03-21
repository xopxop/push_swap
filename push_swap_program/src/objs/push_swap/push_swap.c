/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:29:02 by dthan             #+#    #+#             */
/*   Updated: 2023/03/20 17:07:56 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../../lib/lib.h"

// rotate: first > next && first < last (condition n > 2)
// reverse rotate: first < next && first > last (condition n > 2)
// swap: first > next (condition n > 1)

#define CONSTRUCTOR_SUCCESS 1
#define CONSTRUCTOR_FAILED 0

int	push_swap_constructor(t_push_swap *program, char **input_list)
{
	// create config later
	program->config = NULL;
	//
	program->data = new_data(input_list);
	if (!program->data)
		return (CONSTRUCTOR_FAILED);
	program->global_biggest_number_node = stack_get_biggest_number_node(program->data->stack_a);
	if (program->data->stack_a->count > 1)
		program->global_second_biggest_number_node = stack_get_closet_smaller_number_node(program->data->stack_a, program->global_biggest_number_node);
	else
		program->global_second_biggest_number_node = NULL;
	if (program->data->stack_a->count > 2)
		program->global_third_biggest_number_node = stack_get_closet_smaller_number_node(program->data->stack_a, program->global_second_biggest_number_node);
	else
		program->global_third_biggest_number_node = NULL;
	program->global_smallest_number_node = stack_get_smallest_number_node(program->data->stack_a);
	return (CONSTRUCTOR_SUCCESS);
}

t_push_swap	*push_swap_destructor(t_push_swap *program)
{
	if (program->data)
		data_destructor(program->data);
	// free config later
	free(program);
	return (NULL);
}

t_push_swap *new_push_swap(char **input_list)
{
	t_push_swap *push_swap;

	push_swap = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (push_swap_constructor(push_swap, input_list) == CONSTRUCTOR_FAILED)
		return (push_swap_destructor(push_swap));
	return (push_swap);
}

unsigned int push_swap_run(t_push_swap *program)
{
	if (program->data->stack_a->count > 3)
		return algo_min_10_5(program);
	else if (program->data->stack_a->count > 3)
		return algo_min_4(program);
	return algo_max_3(program);
}
