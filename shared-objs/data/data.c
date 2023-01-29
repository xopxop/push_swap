/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:28:43 by dthan             #+#    #+#             */
/*   Updated: 2023/01/29 15:23:31 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "../../shared-lib/helper.h"
#define CONSTRUCTOR_SUCCESS 1
#define CONSTRUCTOR_FAILED 0

int data_constructor(t_data *data, char **input_list)
{
	if (!*input_list)
		return (CONSTRUCTOR_FAILED);
	data->stack_a = new_stack(input_list);
	if (!data->stack_a)
		return (CONSTRUCTOR_FAILED);
	data->stack_b = new_stack(NULL);
	print_data(data, NULL);
	return (CONSTRUCTOR_SUCCESS);
}

t_data	*data_destructor(t_data *data)
{
	if (data->stack_a)
		stack_destructor(data->stack_a);
	if (data->stack_b)
		stack_destructor(data->stack_b);
	return (NULL);
}

t_data	*new_data(char **input_list)
{
	t_data *data;

	data = (t_data*)malloc(sizeof(t_data));
	if (data_constructor(data, input_list) == CONSTRUCTOR_FAILED)
		return (data_destructor(data));
	return (data);
}
