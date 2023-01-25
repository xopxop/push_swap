/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_min_10.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:09:11 by dthan             #+#    #+#             */
/*   Updated: 2023/01/25 00:26:22 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../../../../libft/includes/libft.h"

t_node *stack_get_node_at(t_stack *stack, unsigned int index_pos)
{
	unsigned int index = 0;
	t_node *node = stack->first_node;

	while (index != index_pos)
	{
		node = node->next;
		index++;		
	}
	return node;
}

int soft_sort(t_stack *from_stack, t_stack *to_stack)
{
	
}

int sth(t_stack *from_stack, t_stack *to_stack, int max)
{
	t_node *node = NULL;
	unsigned int operation_count = 0;
	int dirty = 0;

	while (from_stack->count > 1 || dirty)
	{
		node = from_stack->first_node;
		if (!node)
			break;
		while (node)
		{
			if (node->data <= max)
			{
				operation_count += move_to_top();
				operation_count += execute_instruction(from_stack, to_stack, "pb");
				dirty = 1;
				break;
			}
			dirty = 0;
			node = node->next;			
		}
	}


}

int rough_sort(t_stack *from_stack, t_stack *to_stack)
{
	int divisor = 4;
	int quotient_index = from_stack->count / 4;
	t_node *node = NULL;
	
	node = stack_get_node_at(from_stack, quotient_index);

}

int algo_min_10(t_push_swap *program)
{
	t_stack *stack_a = program->stack_a;
	t_stack *stack_b = program->stack_b;
	return rough_sort(stack_a, stack_b) + algo_max3(program) + soft_sort(stack_b, stack_a);
}
