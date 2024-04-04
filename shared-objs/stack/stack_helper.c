/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:09:38 by dthan             #+#    #+#             */
/*   Updated: 2023/04/06 12:26:21 by dthan            ###   ########.fr       */
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
	int	number;
	int	index;

	index = 0;
	number = ft_atoi(argv);
	while (index < stack->length)
	{
		if (number == stack->data[index])
			return (1);
		index++;
	}
	return (0);
}

int is_greater_than_max_int(char **str)
{
	int negative;
	int n;
	int index;

	index = 0;
	negative = 0;
	n = 0;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index == '-'])
			negative = 1;
		index++;
	}
	while (str[index])
	{
		n = n * 10 
		index++;
	}
}
