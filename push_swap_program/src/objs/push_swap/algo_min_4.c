/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_min_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:22:24 by dthan             #+#    #+#             */
/*   Updated: 2023/01/25 00:26:24 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../../../../libft/includes/libft.h"

unsigned int move_to_top(t_stack *stack, t_node *node)
{
	int node_index = get_index(stack, node);
	int proximity = stack->count / 2;
	char *instruction;
    unsigned int operation_count = 0;
	
	if (node_index >= proximity)
		instruction = "ra";
	else
		instruction = "rra";
	while (stack->first_node == node)
		operation_count += execute_instruction(stack, NULL, instruction);
    return operation_count;
}

t_node *smallest_number(t_stack *stack)
{
	t_node *smallest_number_node = NULL;
	t_node *node = stack->first_node;

	while (node)
	{
		if (!smallest_number_node || smallest_number_node->data < node->data)
			smallest_number_node = node;
		node = node->next;
	}
	return smallest_number_node;
}

int move_smallest_numbers_to_stack_b(t_push_swap *program)
{
    t_stack *stack_a = program->stack_a;
    t_stack *stack_b = program->stack_b;
    t_node *smallest_number_node = NULL;
    int operation_count = 0;

    while (stack_a->count > 3)
    {
        smallest_number_node = smallest_number(stack_a);
        operation_count += move_to_top(stack_a, smallest_number_node);
        operation_count += execute_instruction(stack_a, stack_b, "pb");
    }
    return operation_count;    
}

int move_back_all_numbers_to_stack_a(t_push_swap *program)
{
    int operation_count = 0;

    return operation_count;
}

int algo_min_4(t_push_swap *program)
{
    int operation_nbr_step_1;
    int operation_nbr_step_2;
    int operation_nbr_step_3;
    
    operation_nbr_step_1 = move_smallest_numbers_to_stack_b(program);
    operation_nbr_step_2 = algo_max_3(program);
    operation_nbr_step_3 = move_back_all_numbers_to_stack_a(program);
    return operation_nbr_step_1 + operation_nbr_step_2 + operation_nbr_step_3;
}
