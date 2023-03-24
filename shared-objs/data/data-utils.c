/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data-utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:53:38 by dthan             #+#    #+#             */
/*   Updated: 2023/03/23 19:55:33 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data-modification-helper.h"
#include "data.h"

int	data_execute_instruction(t_data *data, char *command)
{
  return (execute_instruction(data->stack_a, data->stack_b, command));
}
