/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:42:03 by dthan             #+#    #+#             */
/*   Updated: 2023/01/26 20:47:24 by dthan            ###   ########.fr       */
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

t_node *biggest_number_node(t_stack *stack)
{
	t_node *node = stack->first_node;
	t_node *biggest_number_node = NULL;

	while (node)
	{
		if (!biggest_number_node || biggest_number_node->data < node->data)
			biggest_number_node = node;
		node = node->next;
	}
	return biggest_number_node;
}

t_node *smallest_number_node(t_stack *stack)
{
	t_node *smallest_number_node = NULL;
	t_node *node = stack->first_node;

	while (node)
	{
		if (!smallest_number_node || smallest_number_node->data > node->data)
			smallest_number_node = node;
		node = node->next;
	}
	return smallest_number_node;
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
