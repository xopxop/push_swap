/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_calloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:15:05 by dthan             #+#    #+#             */
/*   Updated: 2023/04/05 17:58:57 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utility.h"
#include "../includes/ft_stdio.h"

char	**ft_array_calloc(char **old_array, char *item)
{
	char	**new_array;
	int		increment;

	increment = 0;
	if (old_array)
	{
		new_array = (char **)malloc(sizeof(char *) * \
			(ft_arrayct(old_array) + 2));
		while (old_array && old_array[increment])
		{
			new_array[increment] = old_array[increment];
			increment++;
		}
		free(old_array);
	}
	else
		new_array = (char **)malloc(sizeof(char *) * 2);
	new_array[increment++] = item;
	new_array[increment] = NULL;
	return (new_array);
}
