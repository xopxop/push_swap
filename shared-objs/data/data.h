/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:28:47 by dthan             #+#    #+#             */
/*   Updated: 2023/03/23 19:55:47 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H
#include "../stack/stack.h"
#include <stdlib.h>

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}   t_data;

t_data	*new_data_object(char **argv);
void delete_data_object(t_data *data);
int	data_execute_instruction(t_data *data, char *command);

#endif