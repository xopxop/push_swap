/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_max_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:05:12 by dthan             #+#    #+#             */
/*   Updated: 2023/01/23 21:22:11 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../../../../libft/includes/libft.h"

int algo_max_3(t_push_swap *program)
{
	t_stack *stack_a;
	char *instunction;
	char *steps = 0;

	while (!stack_is_ascending_sorted(stack_a))
	{
		if (can_rotate(stack, ASCENDING))
			instunction = ft_strjoin("r", stack_a->name);
		else if (can_reverse_rotate(stack, ASCENDING))
			instunction = ft_strjoin("rr", stack_a->name);
		else
			instunction = ft_strjoin("s", stack_a->name);
		free(instunction);
		steps++;
	}
	return (steps);
}
