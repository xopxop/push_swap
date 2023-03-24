/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack-helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:09:38 by dthan             #+#    #+#             */
/*   Updated: 2023/03/23 17:20:37 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/libft.h"
#include "stack.h"

int	is_number(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-')
		i++;
	while (argv[i])
		if (!ft_isdigit(argv[i++]))
			return (0);
	return (1);
}

int	is_dup(char *argv, t_stack *stack)
{
	int	number = ft_atoi(argv);
	int index = 0;

	while (index < stack->length)
	{
		if (number == stack->data[index])
			return (1);
		index++;
	}
	return (0);
}
