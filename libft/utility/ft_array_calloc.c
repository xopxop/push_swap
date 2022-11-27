/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_calloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:15:05 by dthan             #+#    #+#             */
/*   Updated: 2022/11/27 19:16:54 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utility.h"

char  **ft_array_calloc(char **old_array, char *item)
{
  char **new_array;
  int increment;

  increment = 0;
  new_array = (char**)malloc(sizeof(char*) * (ft_arrayct(old_array) + 2));
  while (old_array && old_array[increment]) {
    new_array[increment] = old_array[increment];
    increment++;
  }
  new_array[increment++] = item;
  new_array[increment] = NULL;
  free(old_array);
  return new_array;
}
