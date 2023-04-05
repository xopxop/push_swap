/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:28:47 by dthan             #+#    #+#             */
/*   Updated: 2023/04/05 00:12:16 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H
# include "../stack/stack.h"
# include "execution-info.h"

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_data;

t_data	*new_data_object(char **argv);
void	delete_data_object(t_data *data);
int		data_execute_instruction(t_data *data, char *command);
void	data_execute_instruction_extended(
			t_data *data, t_execution_info *exec_info, char *instruction);
void	set_exec_info(t_execution_info *exec_info, int ret, int *color);

#endif