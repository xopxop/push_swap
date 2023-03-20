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

	if (stack->count > 1)
	{
		first_node_number = stack->first_node->data;
		last_node_number = stack->last_node->data;
		if ((order == ASCENDING && first_node_number > last_node_number) || \
		(order == DESCENDING && first_node_number < last_node_number))
			return (1);
	}
	return (0);
}

int is_optimized_reverse_rotate(t_stack *stack, int order)
{
	int first_node_number;
	int last_node_number;

	if (stack->count > 1)
	{
		first_node_number = stack->first_node->data;
		last_node_number = stack->last_node->data;
		if ((order == ASCENDING && last_node_number < first_node_number) || \
		(order == DESCENDING && last_node_number > first_node_number))
			return (1);
	}
	return (0);
}

unsigned int move_node_to_top_optimized(t_data *data, t_stack *targeted_stack, t_stack *secondary_stack, t_node *targeted_node, int target_stack_order)
{
	char instruction[4];
	unsigned int operation_count = 0;
	int node_index = stack_find_index(targeted_stack, targeted_node);
	int proximity = targeted_stack->count / 2;

	while (targeted_stack->first_node != targeted_node)
	{
		if (targeted_stack->first_node->next == targeted_node && is_optimized_swap(secondary_stack, !target_stack_order))
			ft_strcpy(instruction, "ss");
		else if (node_index <= proximity)
		{
			ft_strcpy(instruction, "r");
			if (is_optimized_rotate(secondary_stack, !target_stack_order))
				ft_strcat(instruction, "r");
			else
				ft_strcat(instruction, targeted_stack->name);
		}
		else
		{
			ft_strcpy(instruction, "rr");
			if (is_optimized_reverse_rotate(secondary_stack, !target_stack_order))
				ft_strcat(instruction, "r");
			else
				ft_strcat(instruction, targeted_stack->name);
		}
		operation_count += execute_instruction(data, instruction);
	}
	return operation_count;
}

static unsigned int move_back_all_numbers_to_stack_a(t_push_swap *program)
{
	t_node *local_biggest_number_node = NULL;
	unsigned int operation_count = 0;

	while (program->data->stack_b->count > 0)
	{
		local_biggest_number_node = stack_get_biggest_number_node(program->data->stack_b);
		if (program->data->stack_b->first_node != local_biggest_number_node)
			operation_count += move_node_to_top_optimized(program->data, program->data->stack_b, program->data->stack_a, local_biggest_number_node, DESCENDING);
		operation_count += execute_instruction(program->data, "pa");
	}
	return operation_count;
}

// static unsigned int rough_sort_stack_b_recursive(t_push_swap *program, int selected_number)
// {
// 	t_node *node = NULL;
// 	unsigned int operation_count = 0;
// 	int dirty = 1;

// 	while (dirty)
// 	{
// 		node = program->data->stack_a->first_node;
// 		dirty = 0;
// 		while (node)
// 		{
// 			if (node->data <= selected_number && \
// 				node != program->global_biggest_number_node && \
// 				node != program->global_second_biggest_number_node && \
// 				node != program->global_third_biggest_number_node)
// 			{
// 				if (program->data->stack_a->first_node != node)
// 					operation_count += move_node_to_top_optimized(program->data, program->data->stack_a, program->data->stack_b, node, ASCENDING);
// 				operation_count += execute_instruction(program->data, "pb");
// 				dirty = 1;
// 				break;
// 			}
// 			node = node->next;			
// 		}
// 	}
// 	if (selected_number < 99)
// 		operation_count += rough_sort_stack_b_recursive(program, selected_number + 20);	
// 	return operation_count;
// }


t_node *find_closet_node(t_push_swap *program, t_stack *stack, int selected_number)
{
	t_node *top_down_node = stack->first_node;
	t_node *bottom_up_node = stack->last_node;

	if (top_down_node->data <= selected_number && \
	top_down_node != program->global_biggest_number_node && \
	top_down_node != program->global_second_biggest_number_node && \
	top_down_node != program->global_third_biggest_number_node)
		return top_down_node;
	else
		top_down_node = top_down_node->next;
	while ("finding closet node which smaller or equal than selected node")
	{
		if (top_down_node->data <= selected_number && \
		top_down_node != program->global_biggest_number_node && \
		top_down_node != program->global_second_biggest_number_node && \
		top_down_node != program->global_third_biggest_number_node)
			return top_down_node;
		else if (bottom_up_node->data <= selected_number && \
		bottom_up_node != program->global_biggest_number_node && \
		bottom_up_node != program->global_second_biggest_number_node && \
		bottom_up_node != program->global_third_biggest_number_node)
			return bottom_up_node;
		if (top_down_node == bottom_up_node)
			break;
		top_down_node = top_down_node->next;
		if (top_down_node == bottom_up_node)
			break;
		bottom_up_node = bottom_up_node->prev;
	}
	return NULL;
}

static unsigned int rough_sort_stack_b_recursive(t_push_swap *program, int selected_number)
{
	t_node *targeted_node;
	unsigned int operation_count = 0;

	while (program->data->stack_a->count > 3)
	{
 		targeted_node = find_closet_node(program, program->data->stack_a, selected_number);
		if (!targeted_node)
			break;
		if (program->data->stack_a->first_node != targeted_node)
			operation_count += move_node_to_top_optimized(program->data, program->data->stack_a, program->data->stack_b, targeted_node, ASCENDING);
		operation_count += execute_instruction(program->data, "pb");
	}
	if (program->data->stack_a->count > 3)
		operation_count += rough_sort_stack_b_recursive(program, selected_number + 25);	
	return operation_count;
}

static unsigned int move_all_numbers_to_stack_b_except_the_biggest_number(t_push_swap *program)
{
	int selected_number = 25;

	return rough_sort_stack_b_recursive(program, selected_number);
}

unsigned int algo_min_10_4(t_push_swap *program)
{
	unsigned int operation_count_step_1 = move_all_numbers_to_stack_b_except_the_biggest_number(program);
	unsigned int operation_count_step_2 = algo_max_3(program);
	unsigned int operation_count_step_3 = move_back_all_numbers_to_stack_a(program);
	return operation_count_step_1 + operation_count_step_2 + operation_count_step_3;
}
