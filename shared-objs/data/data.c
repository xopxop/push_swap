/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:28:43 by dthan             #+#    #+#             */
/*   Updated: 2023/01/27 19:08:53 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#define CONSTRUCTOR_SUCCESS 1
#define CONSTRUCTOR_FAILED 0

int data_constructor(t_data *data, char **argv)
{
	data->stack_a = new_stack(argv);
	if (!data->stack_a)
		return (CONSTRUCTOR_FAILED);
	data->stack_b = new_stack(NULL);
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

t_data	*new_data(char **argv)
{
	t_data *data;

	data = (t_data*)malloc(sizeof(t_data));
	if (data_consturctor(data, argv) == CONSTRUCTOR_FAILED)
		return (data_destructor(data));
	return (data);
}
