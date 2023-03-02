/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_min_10_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:09:11 by dthan             #+#    #+#             */
/*   Updated: 2023/01/29 17:22:24 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

#define DIVISOR 4

static unsigned int move_back_all_numbers_to_stack_a(t_push_swap *program)
{
	t_node *local_biggest_number_node = NULL;
	unsigned int operation_count = 0;

	while (program->data->stack_b->count > 0)
	{
		local_biggest_number_node = stack_get_biggest_number_node(program->data->stack_b);
		if (program->data->stack_b->first_node != local_biggest_number_node)
			operation_count += move_node_to_top(program->data, program->data->stack_b, local_biggest_number_node);
		operation_count += execute_instruction(program->data, "pa");
	}
	return operation_count;
}

static unsigned int rough_sort_stack_b_recursive(t_push_swap *program, int selected_number)
{
	t_node *node = NULL;
	unsigned int operation_count = 0;
	int dirty = 1;

	while (dirty)
	{
		node = program->data->stack_a->first_node;
		dirty = 0;
		while (node)
		{
			if (node->data <= selected_number && \
				node != program->global_biggest_number_node && \
				node != program->global_second_biggest_number_node && \
				node != program->global_third_biggest_number_node)
			{
				if (program->data->stack_a->first_node != node)
					operation_count += move_node_to_top(program->data, program->data->stack_a, node);
				operation_count += execute_instruction(program->data, "pb");
				dirty = 1;
				break;
			}
			node = node->next;			
		}
	}
	if (selected_number < 100)
		operation_count += rough_sort_stack_b_recursive(program, selected_number + 30);	
	return operation_count;
}

static unsigned int move_all_numbers_to_stack_b_except_the_biggest_number(t_push_swap *program)
{
	int selected_number = 30;

	return rough_sort_stack_b_recursive(program, selected_number);
}

unsigned int algo_min_10_4(t_push_swap *program)
{
	unsigned int operation_count_step_1 = move_all_numbers_to_stack_b_except_the_biggest_number(program);
	unsigned int operation_count_step_2 = algo_max_3(program);
	unsigned int operation_count_step_3 = move_back_all_numbers_to_stack_a(program);
	return operation_count_step_1 + operation_count_step_2 + operation_count_step_3;
}

#define STACK_A 0
#define STACK_B 1

int is_optimized_swap(t_stack *stack, int order)
{
	int first_node_number;
	int second_node_number;
	if (stack->count > 1)
	{
		first_node_number = stack->first_node->data;
		second_node_number = stack->first_node->next->data;
		if ((order == ASCENDING && first_node_number > second_node_number) || \
		(order == DESCENDING && first_node_number < second_node_number))
			return (1);
	}
	return (0);
}

int is_optimized_rotate(t_stack *stack, int order)
{
	int first_node_number;
	int last_node_number;

	if ()
	return (0);
}


// move numbers to stack b with chunks
//   ra - yes
//   rra - yes
//   sa - yes
//   pb - no
// left only 3
// move back numbers in stack b to stack a
//   rb, rrb, sb, pa

// ss, rrr, rr