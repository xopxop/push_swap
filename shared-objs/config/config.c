/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:37:09 by dthan             #+#    #+#             */
/*   Updated: 2023/04/05 00:09:42 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include <stdlib.h>
#include "../../libft/includes/libft.h"
#define CONSTRUCTOR_SUCCESS 1
#define CONSTRUCTOR_FAILED 0
#define DISPLAY_OPTION "-v"
#define COLOUR_OPTION "-c"

static int	config_constructor(t_config *obj, char ***argv)
{
	char	**inputs;

	inputs = *argv;
	while (*inputs)
	{
		if (ft_strequ(*inputs, DISPLAY_OPTION))
		{
			if (!obj->display_stacks)
				obj->display_stacks = 1;
			else
				return (CONSTRUCTOR_FAILED);
		}
		else if (ft_strequ(*inputs, COLOUR_OPTION))
		{
			if (!obj->colour_the_last_operation)
				obj->colour_the_last_operation = 1;
			else
				return (CONSTRUCTOR_FAILED);
		}
		else
			break ;
		inputs++;
	}
	*argv = inputs;
	return (CONSTRUCTOR_SUCCESS);
}

static t_config	*config_destructor(t_config *obj)
{
	free(obj);
	return (NULL);
}

void	delete_config_object(t_config *obj)
{
	config_destructor(obj);
}

t_config	*new_config_object(char ***argv)
{
	t_config	*obj;

	obj = (t_config *)malloc(sizeof(t_config));
	obj->colour_the_last_operation = 0;
	obj->display_stacks = 0;
	obj->read_and_write_from_file = 0;
	if (config_constructor(obj, argv) == CONSTRUCTOR_FAILED)
		return (config_destructor(obj));
	return (obj);
}
