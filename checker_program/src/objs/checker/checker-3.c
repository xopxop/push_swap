/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker-3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:13:03 by dthan             #+#    #+#             */
/*   Updated: 2022/11/29 12:32:19 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../../../../libft/includes/libft.h"
#define A_ONLY 1
#define B_ONLY 2
#define BOTH 3

void	do_swap(t_stack *stack_a, t_stack *stack_b, int op)
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
}

void	do_push(t_stack *stack_a, t_stack *stack_b, int op)
{
	if (op == A_ONLY)
	{
		if (stack_a->count > 0)
			stack_push_top(stack_a, stack_pop_top(stack_b));
	}
	else if (op == B_ONLY)
	{
		if (stack_b->count > 0)
			stack_push_top(stack_b, stack_pop_top(stack_a));
	}
}

void	do_rotate(t_stack *stack_a, t_stack *stack_b, int op)
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
}

void	do_reverse_rotate(t_stack *stack_a, t_stack *stack_b, int op)
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
}

void	checker_execute_instruction(t_checker *program, char *command)
{
	if (!ft_strcmp(command, "sa"))
		do_swap(program->stack_a, program->stack_b, A_ONLY);
	else if (!ft_strcmp(command, "sb"))
		do_swap(program->stack_a, program->stack_b, B_ONLY);
	else if (!strcmp(command, "ss"))
		do_swap(program->stack_a, program->stack_b, BOTH);
	else if (!strcmp(command, "pa"))
		do_push(program->stack_a, program->stack_b, A_ONLY);
	else if (!strcmp(command, "pb"))
		do_push(program->stack_a, program->stack_b, B_ONLY);
	else if (!strcmp(command, "ra"))
		do_rotate(program->stack_a, program->stack_b, A_ONLY);
	else if (!strcmp(command, "rb"))
		do_rotate(program->stack_a, program->stack_b, B_ONLY);
	else if (!strcmp(command, "rr"))
		do_rotate(program->stack_a, program->stack_b, BOTH);
	else if (!strcmp(command, "rra"))
		do_reverse_rotate(program->stack_a, program->stack_b, A_ONLY);
	else if (!strcmp(command, "rrb"))
		do_reverse_rotate(program->stack_a, program->stack_b, B_ONLY);
	else if (!strcmp(command, "rrr"))
		do_reverse_rotate(program->stack_a, program->stack_b, BOTH);
}
