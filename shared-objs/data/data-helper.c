/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data-helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:26:42 by dthan             #+#    #+#             */
/*   Updated: 2023/03/23 19:58:56 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/libft.h"

char **ft_array_join_and_delete_arrays(char **array_a, char **array_b)
{
	char **joint_array;
	int index_temp;
	int index;

	if (!array_a && !array_b)
		return (NULL);
	else if (!array_a)
		return (array_b);
	else if (!array_b)
		return (array_b);
	index = 0;
	index_temp = 0;
	joint_array = (char**)malloc(sizeof(char*) * (ft_arrayct(array_a) + ft_arrayct(array_b) + 1));
	while (array_a[index_temp])
	{
		joint_array[index] = array_a[index_temp];
		index_temp++;
		index++;
	}
	index_temp = 0;
	while (array_b[index_temp])
	{
		joint_array[index] = array_b[index_temp];
		index_temp++;
		index++;
	}
	joint_array[index] = NULL;
	free(array_a);
	free(array_b);
	return (joint_array);
}

char **refine_input_list(char **input_list)
{
	char **splitted_input_list = NULL;
	int index = 0;

	while (input_list[index])
	{
		splitted_input_list = ft_array_join_and_delete_arrays(splitted_input_list, ft_strsplit(input_list[index], ' '));
		index++;
	}
	return splitted_input_list;
}
