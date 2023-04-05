/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data-utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:53:38 by dthan             #+#    #+#             */
/*   Updated: 2023/04/05 16:37:21 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_modification_helper.h"
#include "data.h"
#include "execution_info.h"
#include "../../libft/includes/libft.h"

void	data_execute_instruction(t_data *data, char *command)
{
	ft_printf("%s\n", command);
	execute_instruction(data->stack_a, data->stack_b, command);
}

void	set_exec_info(t_execution_info *exec_info, int ret, int *color)
{
	exec_info->increment = ret;
	exec_info->color_a1 = color[0];
	exec_info->color_a2 = color[1];
	exec_info->color_b1 = color[2];
	exec_info->color_b2 = color[3];
}

static int	*set_colors(char *cmd, t_stack *stack_a, t_stack *stack_b)
{
	if (cmd == NULL)
		return ((int []){-1, -1, -1, -1});
	else if (ft_strequ(cmd, "sa"))
		return ((int []){0, 1, -1, -1});
	else if (ft_strequ(cmd, "sb"))
		return ((int []){-1, -1, 0, 1});
	else if (ft_strequ(cmd, "ss"))
		return ((int []){0, 1, 0, 1});
	else if (ft_strequ(cmd, "pa"))
		return ((int []){0, -1, -1, -1});
	else if (ft_strequ(cmd, "pb"))
		return ((int []){-1, -1, 0, -1});
	else if (ft_strequ(cmd, "ra"))
		return ((int []){0, stack_a->length - 1, -1});
	else if (ft_strequ(cmd, "rb"))
		return ((int []){-1, -1 -0, stack_b->length - 1});
	else if (ft_strequ(cmd, "rr"))
		return ((int []){0, stack_a->length - 1, 0, stack_b->length - 1});
	else if (ft_strequ(cmd, "rra"))
		return ((int []){0, stack_a->length - 1, -1});
	else if (ft_strequ(cmd, "rrb"))
		return ((int []){-1, -1 -0, stack_b->length - 1});
	return ((int []){0, stack_a->length - 1, 0, stack_b->length - 1});
}

void	data_execute_instruction_extended(
	t_data *data, t_execution_info *exec_info, char *instruction)
{
	unsigned int	ret;

	ret = execute_instruction(data->stack_a, data->stack_b, instruction);
	if (!ret)
		set_exec_info(exec_info, ret,
			set_colors(NULL, data->stack_a, data->stack_b));
	else
		set_exec_info(exec_info, ret,
			set_colors(instruction, data->stack_a, data->stack_b));
}
