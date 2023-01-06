/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker-2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:23:29 by dthan             #+#    #+#             */
/*   Updated: 2022/11/28 11:32:16 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../../../../libft/includes/libft.h"
#define CHECKER_VALIDATOR_PASSED 1
#define CHECKER_VALIDATOR_FAILED 0

int	checker_execute_instructions(t_checker *program)
{
	int	i;

	i = 0;
	while (program->instructions[i])
		checker_execute_instruction(program, program->instructions[i++]);
	if (stack_is_empty(program->stack_b) && stack_is_sorted(program->stack_a))
	{
		ft_printf("OK\n");
		return (CHECKER_VALIDATOR_PASSED);
	}
	else
	{
		ft_dprintf(1, "KO\n");
		return (CHECKER_VALIDATOR_FAILED);
	}
}
