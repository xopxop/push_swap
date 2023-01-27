/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:42:03 by dthan             #+#    #+#             */
/*   Updated: 2023/01/26 23:32:23 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

unsigned int move_node_to_top(t_stack *stack, t_node *node)
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
