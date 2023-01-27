/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:32:11 by dthan             #+#    #+#             */
/*   Updated: 2023/01/27 19:23:53 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"
#include <stddef.h>
#include "../libft/includes/libft.h"
#define A_ONLY 1
#define B_ONLY 2
#define BOTH 3

unsigned int do_swap(t_stack *stack_a, t_stack *stack_b, int op)
{
	if (op == A_ONLY)
	{
		if (stack_a->count > 1)
			stack_swap(stack_a);
	}
	else if (op == B_ONLY)
	{
		if (stack_b->count > 1)
			stack_swap(stack_b);
	}
	else if (op == BOTH)
	{
		do_swap(stack_a, NULL, A_ONLY);
		do_swap(NULL, stack_b, B_ONLY);
	}
	return (1);
}

unsigned int	do_push(t_stack *stack_a, t_stack *stack_b, int op)
{
	if (op == A_ONLY)
	{
		if (stack_b->count > 0)
			stack_push_top(stack_a, stack_pop_top(stack_b));
	}
	else if (op == B_ONLY)
	{
		if (stack_a->count > 0)
			stack_push_top(stack_b, stack_pop_top(stack_a));
	}
	return (1);
}

unsigned int	do_rotate(t_stack *stack_a, t_stack *stack_b, int op)
{
	if (op == A_ONLY)
	{
		if (stack_a->count > 1)
			stack_push(stack_a, stack_pop_top(stack_a));
	}
	else if (op == B_ONLY)
	{
		if (stack_b->count > 1)
			stack_push(stack_b, stack_pop_top(stack_b));
	}
	else if (op == BOTH)
	{
		do_rotate(stack_a, stack_b, A_ONLY);
		do_rotate(stack_a, stack_b, B_ONLY);
	}
	return (1);
}

unsigned int	do_reverse_rotate(t_stack *stack_a, t_stack *stack_b, int op)
{
	if (op == A_ONLY)
	{
		if (stack_a->count > 1)
			stack_push_top(stack_a, stack_pop(stack_a));
	}
	else if (op == B_ONLY)
	{
		if (stack_b->count > 1)
			stack_push_top(stack_b, stack_pop(stack_b));
	}
	else if (op == BOTH)
	{
		do_reverse_rotate(stack_a, stack_b, A_ONLY);
		do_reverse_rotate(stack_a, stack_b, B_ONLY);
	}
	return (1);
}

unsigned int	execute_instruction(t_stack *stack_a, t_stack *stack_b, char *command)
{
	if (!ft_strcmp(command, "sa"))
		return do_swap(stack_a, stack_b, A_ONLY);
	else if (!ft_strcmp(command, "sb"))
		return do_swap(stack_a, stack_b, B_ONLY);
	else if (!strcmp(command, "ss"))
		return do_swap(stack_a, stack_b, BOTH);
	else if (!strcmp(command, "pa"))
		return do_push(stack_a, stack_b, A_ONLY);
	else if (!strcmp(command, "pb"))
		return do_push(stack_a, stack_b, B_ONLY);
	else if (!strcmp(command, "ra"))
		return do_rotate(stack_a, stack_b, A_ONLY);
	else if (!strcmp(command, "rb"))
		return do_rotate(stack_a, stack_b, B_ONLY);
	else if (!strcmp(command, "rr"))
		return do_rotate(stack_a, stack_b, BOTH);
	else if (!strcmp(command, "rra"))
		return do_reverse_rotate(stack_a, stack_b, A_ONLY);
	else if (!strcmp(command, "rrb"))
		return do_reverse_rotate(stack_a, stack_b, B_ONLY);
	else if (!strcmp(command, "rrr"))
		return do_reverse_rotate(stack_a, stack_b, BOTH);
	return (0);
}
/*
unsigned int	execute_instruction_wrapper(t_data *data, t_config *config, char *instruction)
{
	unsigned int operation_count = execute_instruction(data->stack_a, data->stack_b, instruction);
	// if (config)
	// {
		
	// }
	// else
		ft_putendl(instruction);
	return operation_count;
}
*/