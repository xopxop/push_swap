/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:28:43 by dthan             #+#    #+#             */
/*   Updated: 2023/04/05 00:14:52 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "data-helper.h"
#include "../../libft/includes/libft.h"
#define CONSTRUCTOR_SUCCESS 1
#define CONSTRUCTOR_FAILED 0

static int	data_constructor(t_data *data, char **input_list)
{
	char	**refined_input_list;

	if (!*input_list)
		return (CONSTRUCTOR_FAILED);
	refined_input_list = refine_input_list(input_list);
	data->stack_a = \
		new_stack_object(refined_input_list, ft_arrayct(refined_input_list));
	free(refined_input_list);
	if (!data->stack_a)
		return (CONSTRUCTOR_FAILED);
	data->stack_b = new_stack_object(NULL, data->stack_a->size);
	return (CONSTRUCTOR_SUCCESS);
}

static t_data	*data_destructor(t_data *data)
{
	if (data->stack_a)
		delete_stack_object(data->stack_a);
	if (data->stack_b)
		delete_stack_object(data->stack_b);
	free(data);
	return (NULL);
}

void	delete_data_object(t_data *data)
{
	data_destructor(data);
}

t_data	*new_data_object(char **input_list)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data_constructor(data, input_list) == CONSTRUCTOR_FAILED)
		return (data_destructor(data));
	return (data);
}
