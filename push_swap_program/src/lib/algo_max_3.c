/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_max_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:05:12 by dthan             #+#    #+#             */
/*   Updated: 2023/01/29 15:11:51 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

unsigned int algo_max_3(t_push_swap *program)
{
	t_stack *stack_a = program->data->stack_a;
	char *instruction = NULL;
	unsigned int operation_count = 0;

	while (!stack_is_ascending_sorted(stack_a))
	{
		if (can_rotate(stack_a, ASCENDING))
			instruction = ft_strjoin("r", stack_a->name);
		else if (can_reverse_rotate(stack_a, ASCENDING))
			instruction = ft_strjoin("rr", stack_a->name);
		else
			instruction = ft_strjoin("s", stack_a->name);
		operation_count += execute_instruction(program->data, instruction);
		free(instruction);
	}
	return (operation_count);
}
