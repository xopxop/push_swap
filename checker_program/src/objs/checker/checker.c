/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:24:55 by dthan             #+#    #+#             */
/*   Updated: 2023/04/05 15:51:16 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stddef.h>
#include "../../../../libft/includes/libft.h"
#include "checker_helper.h"
#include "../../lib/checker_lib.h"
#define CONSTRUCTOR_SUCCESS 1
#define CONSTRUCTOR_FAILED 0
#define CHECKER_VALIDATOR_PASSED 1
#define CHECKER_VALIDATOR_FAILED 0

int	checker_execute_instructions(t_checker *program)
{
	int					i;
	t_execution_info	exec_info;

	i = 0;
	while (program->instructions[i])
	{
		data_execute_instruction_extended(
			program->data, &exec_info, program->instructions[i]);
		if (program->config->display_stacks)
			display_stacks(program, i, &exec_info);
		i++;
	}
	if (stack_is_empty(program->data->stack_b) && \
		stack_is_sorted_in_ascending_order(program->data->stack_a))
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

static int	checker_constructor(t_checker *program, char **argv)
{
	program->config = new_config_object(&argv);
	if (!program->config)
		return (CONSTRUCTOR_FAILED);
	program->data = new_data_object(argv);
	if (!program->data)
		return (CONSTRUCTOR_FAILED);
	program->instructions = get_instructions();
	if (!program->instructions)
		return (CONSTRUCTOR_FAILED);
	return (CONSTRUCTOR_SUCCESS);
}

static t_checker	*checker_destructor(t_checker *program)
{
	int	index;

	if (program->data)
		delete_data_object(program->data);
	if (program->instructions)
	{
		index = 0;
		while (program->instructions[index])
			free(program->instructions[index++]);
		free(program->instructions);
	}
	delete_config_object(program->config);
	free(program);
	return (NULL);
}

void	delete_checker_object(t_checker *object)
{
	checker_destructor(object);
}

t_checker	*new_checker_object(char **argv)
{
	t_checker			*checker;
	t_execution_info	exec_info;

	checker = (t_checker *)malloc(sizeof(t_checker));
	if (checker_constructor(checker, argv) == CONSTRUCTOR_FAILED)
		return (checker_destructor(checker));
	if (checker->config->display_stacks)
	{
		set_exec_info(&exec_info, 0, (int []){-1, -1, -1, -1});
		display_stacks(checker, -1, &exec_info);
	}
	return (checker);
}
