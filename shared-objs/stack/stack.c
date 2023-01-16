/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:59:44 by dthan             #+#    #+#             */
/*   Updated: 2023/01/16 20:31:14 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>
#include "../../libft/includes/libft.h"
#define CONSTRUCTOR_SUCCESS 1
#define CONSTRUCTOR_FAILED 0

int	stack_constructor_simple(t_stack *stack)
{
	stack->first_node = NULL;
	stack->last_node = NULL;
	stack->count = 0;
	return (CONSTRUCTOR_SUCCESS);
}

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

int	is_dup(char *argv, t_node *node)
{
	int	number;

	number = ft_atoi(argv);

	while (node)
	{
		if (number == node->data)
			return (1);
		node = node->next;
	}
	return (0);
}

int	stack_constructor_complex(t_stack *stack, char **argv)
{
	int		i;
	t_node	*node;
	char **temp;

	i = 0;
	temp = ft_strsplit(argv[0], ' ');
	stack->first_node = NULL;
	stack->last_node = NULL;
	stack->count = 0;
	while (temp[i])
	{
		if (is_number(temp[i]) && !is_dup(temp[i], stack->first_node))
		{
			node = new_node(temp[i]);
			stack_push(stack, node);
		}
		else
			return (CONSTRUCTOR_FAILED);
		i++;
	}
	return (CONSTRUCTOR_SUCCESS);
}

t_stack	*new_stack(char **argv)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!argv)
		stack_constructor_simple(stack);
	else
		if (stack_constructor_complex(stack, argv) == CONSTRUCTOR_FAILED)
			return (stack_destructor(stack));
	return (stack);
}
