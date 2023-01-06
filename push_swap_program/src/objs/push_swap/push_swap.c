/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:29:02 by dthan             #+#    #+#             */
/*   Updated: 2023/01/06 14:24:07 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../../../../libft/includes/libft.h"
#include "../../../../shared-lib/helper.h"
#define ASCENDING 0
#define DESCENDING 1

int can_swap(t_stack *stack, int order)
{
	if (stack->count > 1)
	{
		if (order == ASCENDING)
		{
			if (stack->first_node->data > stack->first_node->next->data)
				return (1);
		}
		else if (order == DESCENDING)
		{
			if (stack->first_node->data < stack->first_node->next->data)
				return (1);
		}
	}
	return (0);
}

int can_rotate(t_stack *stack, int order)
{
	if (stack->count > 2)
	{
		if (order == ASCENDING)
		{
			if (stack->first_node->data > stack->first_node->next->data && \
			stack->first_node->data > stack->last_node->data)
				return (1);
		}
		else if (order == DESCENDING)
		{
			if (stack->first_node->data < stack->first_node->next->data && \
			stack->first_node->data < stack->last_node->data)
				return (1);
		}
	}
	return (0);
}

int	can_reverse_rotate(t_stack *stack, int order)
{
	if (stack->count > 2)
	{
		if (order == ASCENDING)
		{
			if (stack->first_node->data > stack->last_node->data && \
			stack->first_node->data < stack->first_node->next->data)
				return (1);
		}
		else if (order == DESCENDING)
		{
			if (stack->first_node->data < stack->last_node->data && \
			stack->first_node->data > stack->first_node->next->data)
				return (1);
		}
	}
	return (0);
}

int can_swap_simple(t_stack *stack, int order)
{
	if (stack->count > 1)
	{
		if (order == ASCENDING)
		{
			if (stack->first_node->data > stack->first_node->next->data)
				return (1);
		}
		else if (order == DESCENDING)
		{
			if (stack->first_node->data < stack->first_node->next->data)
				return (1);
		}
	}
	return (0);
}

// rotate: first > next && first < last (condition n > 2)
// reverse rotate: first < next && first > last (condition n > 2)
// swap: first > next (condition n > 1)

char *push_swap_generate_instructions2(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a && stack_b) {
		if (can_rotate(stack_a, ASCENDING) && can_rotate(stack_b, DESCENDING))
			return (ft_strdup("rr"));
		else if (can_reverse_rotate(stack_a, ASCENDING) && can_reverse_rotate(stack_b, DESCENDING))
			return (ft_strdup("rrr"));
		else if (can_swap(stack_a, ASCENDING) && can_swap(stack_b, DESCENDING))
			return (ft_strdup("ss"));
		if (stack_a->count > stack_b->count) {
			return (push_swap_generate_instructions2(NULL, stack_b));
		}
		return (push_swap_generate_instructions2(stack_a, NULL));
	} else if (stack_a) {
		if (can_rotate(stack_a, ASCENDING))
			return (ft_strdup("ra"));
		else if (can_reverse_rotate(stack_a, ASCENDING))
			return (ft_strdup("rra"));
		else if (can_swap(stack_a, ASCENDING))
			return (ft_strdup("sa"));
		return (ft_strdup("pb"));
	} else if (stack_b) {
		if (can_rotate(stack_b, DESCENDING))
			return (ft_strdup("rb"));
		else if (can_reverse_rotate(stack_b, DESCENDING))
			return (ft_strdup("rrb"));
		else if (can_swap(stack_b, DESCENDING))
			return (ft_strdup("sb"));
		return (ft_strdup("pa"));
	}
	return ft_strdup("pa");
}

char *push_swap_generate_instructions(t_stack *stack_a, t_stack *stack_b)
{
	int stack_a_ascending_sorted;
	int stack_b_descending_sorted;

	stack_a_ascending_sorted = stack_is_ascending_sorted(stack_a);
	stack_b_descending_sorted = stack_is_descending_sorted(stack_b);

	if (stack_a_ascending_sorted && stack_b_descending_sorted) {
		return  push_swap_generate_instructions2(NULL, NULL);
	} else if (stack_a_ascending_sorted) {
		return push_swap_generate_instructions2(NULL, stack_b);
	} else if (stack_b_descending_sorted) {
		return push_swap_generate_instructions2(stack_a, NULL);
	} else {
		return push_swap_generate_instructions2(stack_a, stack_b);
	}
}

#include "../../../../shared-objs/node/node.h"
void print_stack(t_stack *stack)
{
	t_node *node = stack->first_node;

	while (node) {
		ft_printf("%d ->", node->data);
		node = node->next;
	}
	ft_printf("NULL\n");
}

void push_swap_run(t_push_swap *program)
{
	t_stack *stack_a;
	t_stack *stack_b;
	char *instruction;
	int i;

	i = 0;
	stack_a = program->stack_a;
	stack_b = program->stack_b;
	while ("looping")
	{
		if (stack_is_empty(stack_b) && stack_is_ascending_sorted(stack_a))
			break ;
		// ft_printf("STACK A:\n");
		// print_stack(stack_a);
		// ft_printf("STACK B:\n");
		// print_stack(stack_b);
		instruction = push_swap_generate_instructions(stack_a, stack_b);
		// ft_printf("%s\n", instruction);
		execute_instruction(stack_a, stack_b, instruction);
		free(instruction);
		i++;
		// sleep(1);
	}
	ft_printf("Total: %d\n", i);
}

// if stackA and/or stackB are not sorted
// 	if stackA and stackB are not sorted
// 		if do swap both -> do ss
// 		else if do rotate both -> do rr
// 		else if do reverse rotate both -> do rrr
// 	else if stackA is not sorted
// 		if do swap -> do sa
// 		else if do rotate -> do ra
// 		else if do revere rotate -> do rra
// 	else if stackB is not sorted
// 		if do swap -> do sb
// 		else if do rotate -> do rb
// 		else if do revere rotate -> do rrb
// 	push from stackA to stackB -> do pb
// else
// 	push stackB to stackA -> do pa