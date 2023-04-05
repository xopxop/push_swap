/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_modification_helper.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:48:34 by dthan             #+#    #+#             */
/*   Updated: 2023/04/05 16:35:39 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack/stack.h"
#include "data_modification_helper.h"
#include "../../libft/includes/libft.h"

static int	do_swap(t_stack *stack_a, t_stack *stack_b, int op)
{
	if (op == A_ONLY && stack_a->length > 1)
		stack_swap(stack_a);
	else if (op == B_ONLY && stack_b->length > 1)
		stack_swap(stack_b);
	else if (op == BOTH && stack_a->length > 1 && stack_b->length > 1)
	{
		stack_swap(stack_a);
		stack_swap(stack_b);
	}
	else
		return (0);
	return (1);
}

static int	do_push(t_stack *stack_a, t_stack *stack_b, int op)
{
	if (op == A_ONLY && stack_b->length > 0)
		stack_push(stack_a, stack_pop(stack_b));
	else if (op == B_ONLY && stack_a->length > 0)
		stack_push(stack_b, stack_pop(stack_a));
	else
		return (0);
	return (1);
}

static int	do_rotate(t_stack *stack_a, t_stack *stack_b, int op)
{
	if (op == A_ONLY && stack_a->length > 1)
		stack_add(stack_a, stack_pop(stack_a));
	else if (op == B_ONLY && stack_b->length > 1)
		stack_add(stack_b, stack_pop(stack_b));
	else if (op == BOTH && stack_a->length > 1 && stack_b->length > 1)
	{
		stack_add(stack_a, stack_pop(stack_a));
		stack_add(stack_b, stack_pop(stack_b));
	}
	else
		return (0);
	return (1);
}

static int	do_reverse_rotate(t_stack *stack_a, t_stack *stack_b, int op)
{
	if (op == A_ONLY && stack_a->length > 1)
		stack_push(stack_a, stack_reduce(stack_a));
	else if (op == B_ONLY && stack_b->length > 1)
		stack_push(stack_b, stack_reduce(stack_b));
	else if (op == BOTH && stack_a->length > 1 && stack_b->length > 1)
	{
		stack_push(stack_a, stack_reduce(stack_a));
		stack_push(stack_b, stack_reduce(stack_b));
	}
	else
		return (0);
	return (1);
}

int	execute_instruction(t_stack *stack_a, t_stack *stack_b, char *command)
{
	if (!ft_strcmp(command, "sa"))
		return (do_swap(stack_a, stack_b, A_ONLY));
	else if (!ft_strcmp(command, "sb"))
		return (do_swap(stack_a, stack_b, B_ONLY));
	else if (!strcmp(command, "ss"))
		return (do_swap(stack_a, stack_b, BOTH));
	else if (!strcmp(command, "pa"))
		return (do_push(stack_a, stack_b, A_ONLY));
	else if (!strcmp(command, "pb"))
		return (do_push(stack_a, stack_b, B_ONLY));
	else if (!strcmp(command, "ra"))
		return (do_rotate(stack_a, stack_b, A_ONLY));
	else if (!strcmp(command, "rb"))
		return (do_rotate(stack_a, stack_b, B_ONLY));
	else if (!strcmp(command, "rr"))
		return (do_rotate(stack_a, stack_b, BOTH));
	else if (!strcmp(command, "rra"))
		return (do_reverse_rotate(stack_a, stack_b, A_ONLY));
	else if (!strcmp(command, "rrb"))
		return (do_reverse_rotate(stack_a, stack_b, B_ONLY));
	return (do_reverse_rotate(stack_a, stack_b, BOTH));
}
