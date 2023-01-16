/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap-1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:45:41 by dthan             #+#    #+#             */
/*   Updated: 2023/01/16 20:22:35 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#define CONSTRUCTOR_SUCCESS 1
#define CONSTRUCTOR_FAILED 0

int	push_swap_constructor(t_push_swap *program, char **argv)
{
	program->stack_a = new_stack(argv);
	if (!program->stack_a)
		return (CONSTRUCTOR_FAILED);
	program->stack_b = new_stack(NULL);
	return (CONSTRUCTOR_SUCCESS);
}

t_push_swap	*push_swap_destructor(t_push_swap *program)
{
	if (program->stack_a)
		stack_destructor(program->stack_a);
	if (program->stack_b)
		stack_destructor(program->stack_b);
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
