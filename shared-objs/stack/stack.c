/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:59:44 by dthan             #+#    #+#             */
/*   Updated: 2023/01/28 20:32:38 by dthan            ###   ########.fr       */
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
	stack->name = ft_strdup("b");
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

char **ft_array_dub(char **array)
{
	int index;
	char **dup_array;

	if (!array)
		return (NULL);
	index = 0;
	dup_array = (char**)malloc(sizeof(char*) * (ft_arrayct(array) + 1));
	while (array[index])
	{
		dup_array[index] = ft_strdup(array[index]);
		index++;
	}
	dup_array[index] = NULL;
	return dup_array;
}

char **ft_array_join(char **array_a, char **array_b)
{
	char **joint_array;
	int index_temp;
	int index;

	if (!array_a && !array_b)
		return (NULL);
	else if (!array_a)
		return ft_array_dub(array_b);
	else if (!array_b)
		return ft_array_dub(array_a);
	index = 0;
	index_temp = 0;
	joint_array = (char**)malloc(sizeof(char*) * (ft_arrayct(array_a) + ft_arrayct(array_b) + 1));
	while (array_a[index_temp])
	{
		joint_array[index] = ft_strdup(array_a[index_temp]);
		index_temp++;
		index++;
	}
	index_temp = 0;
	while (array_b[index_temp])
	{
		joint_array[index] = ft_strdup(array_b[index_temp]);
		index_temp++;
		index++;
	}
	joint_array[index] = NULL;
	return (joint_array);
}

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

char **get_splitted_input_list(char **input_list)
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

int	stack_constructor_complex(t_stack *stack, char **input_list)
{
	int		i;
	t_node	*node;
	char **splitted_input_list;

	i = 0;
	splitted_input_list = get_splitted_input_list(input_list);
	stack->first_node = NULL;
	stack->last_node = NULL;
	stack->count = 0;
	stack->name = ft_strdup("a");
	while (splitted_input_list[i])
	{
		if (is_number(splitted_input_list[i]) && !is_dup(splitted_input_list[i], stack->first_node))
		{
			node = new_node(splitted_input_list[i]);
			stack_push(stack, node);
		}
		else
			return (CONSTRUCTOR_FAILED);
		i++;
	}
	return (CONSTRUCTOR_SUCCESS);
}

t_stack	*new_stack(char **input_list)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!input_list)
		stack_constructor_simple(stack);
	else
		if (stack_constructor_complex(stack, input_list) == CONSTRUCTOR_FAILED)
			return (stack_destructor(stack));
	return (stack);
}
