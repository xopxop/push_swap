/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data-utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:53:38 by dthan             #+#    #+#             */
/*   Updated: 2023/04/04 15:45:28 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data-modification-helper.h"
#include "data.h"
#include "execution-info.h"
#include "../../libft/includes/libft.h"

#include <stdio.h>
int	data_execute_instruction(t_data *data, char *command)
{
	ft_printf("%s\n", command);
	return execute_instruction(data->stack_a, data->stack_b, command);
}

void set_exec_info(t_execution_info *exec_info, int ret, int *color)
{
	exec_info->increment = ret;
	exec_info->color_a1 = color[0];
	exec_info->color_a2 = color[1];
	exec_info->color_b1 = color[2];
	exec_info->color_b2 = color[3];
}

void data_execute_instruction_extended(t_data *data, t_execution_info *exec_info, char *instruction)
{
	unsigned int ret = execute_instruction(data->stack_a, data->stack_b, instruction);

	if (!ret)
		set_exec_info(exec_info, ret, (int[]){-1, -1, -1, -1});
	else if (!ft_strcmp(instruction, "sa"))
		set_exec_info(exec_info, ret, (int[]){0, 1, -1, -1});
	else if (!ft_strcmp(instruction, "sb"))
		set_exec_info(exec_info, ret, (int[]){-1, -1, 0, 1});
	else if (!strcmp(instruction, "ss"))
		set_exec_info(exec_info, ret, (int[]){0, 1, 0, 1});
	else if (!strcmp(instruction, "pa"))
		set_exec_info(exec_info, ret, (int[]){0, -1, -1, -1});
	else if (!strcmp(instruction, "pb"))
		set_exec_info(exec_info, ret, (int[]){-1, -1, 0, -1});
	else if (!strcmp(instruction, "ra"))
		set_exec_info(exec_info, ret, (int[]){0, data->stack_a->length - 1, -1 });
	else if (!strcmp(instruction, "rb"))
		set_exec_info(exec_info, ret, (int[]){-1, -1 -0, data->stack_b->length - 1});
	else if (!strcmp(instruction, "rr"))
		set_exec_info(exec_info, ret, (int[]){0, data->stack_a->length - 1, 0, data->stack_b->length - 1});
	else if (!strcmp(instruction, "rra"))
		set_exec_info(exec_info, ret, (int[]){0, data->stack_a->length - 1, -1 });
	else if (!strcmp(instruction, "rrb"))
		set_exec_info(exec_info, ret, (int[]){-1, -1 -0, data->stack_b->length - 1});
	else
		set_exec_info(exec_info, ret, (int[]){0, data->stack_a->length - 1, 0, data->stack_b->length - 1});
}
