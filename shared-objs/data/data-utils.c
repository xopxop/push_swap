/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data-utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:53:38 by dthan             #+#    #+#             */
/*   Updated: 2023/03/25 20:26:12 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data-modification-helper.h"
#include "data.h"
#include "data-printer.h"

int	data_execute_instruction(t_data *data, char *command)
{
	unsigned int ret = execute_instruction(data->stack_a, data->stack_b, command);
	t_printer *printer = new_printer_object(data, command);
	printer_print(printer);
	delete_printer_object(printer);
	return ret;
}
