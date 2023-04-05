/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:29:02 by dthan             #+#    #+#             */
/*   Updated: 2023/04/05 17:20:10 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../../lib/algo.h"
#include <stdlib.h>
#define CONSTRUCTOR_SUCCESS 1
#define CONSTRUCTOR_FAILED 0

int	push_swap_constructor(t_push_swap *program, char **input_list)
{
	program->data = new_data_object(input_list);
	if (!program->data)
		return (CONSTRUCTOR_FAILED);
	return (CONSTRUCTOR_SUCCESS);
}

t_push_swap	*push_swap_destructor(t_push_swap *program)
{
	if (program->data)
		delete_data_object(program->data);
	free(program);
	return (NULL);
}

void	delete_push_swap_object(t_push_swap *program)
{
	push_swap_destructor(program);
}

t_push_swap	*new_push_swap_object(char **input_list)
{
	t_push_swap	*push_swap;

	push_swap = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (push_swap_constructor(push_swap, input_list) == CONSTRUCTOR_FAILED)
		return (push_swap_destructor(push_swap));
	return (push_swap);
}

void	push_swap_run(t_push_swap *program)
{
	if (program->data->stack_a->length > 3)
		algo_min_4(program);
	else
		algo_max_3(program);
}
