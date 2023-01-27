/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:29:02 by dthan             #+#    #+#             */
/*   Updated: 2023/01/27 19:14:04 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotate: first > next && first < last (condition n > 2)
// reverse rotate: first < next && first > last (condition n > 2)
// swap: first > next (condition n > 1)

#define CONSTRUCTOR_SUCCESS 1
#define CONSTRUCTOR_FAILED 0

int	push_swap_constructor(t_push_swap *program, char **argv)
{
	program->data = new_data(argv);
	if (!program->data)
		return (CONSTRUCTOR_FAILED);
	program->global_biggest_number_node = stack_get_biggest_number_node(program->data->stack_a);
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

t_push_swap *new_push_swap(char **argv)
{
	t_push_swap *push_swap;

	push_swap = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (push_swap_constructor(push_swap, argv) == CONSTRUCTOR_FAILED)
		return (push_swap_destructor(push_swap));
	return (push_swap);
}

unsigned int push_swap_run(t_push_swap *program)
{
	if (program->data->stack_a->count > 9)
		return algo_min_10(program);
	else if (program->data->stack_a->count > 3)
		return algo_min_4(program);
	return algo_max_3(program);
}
