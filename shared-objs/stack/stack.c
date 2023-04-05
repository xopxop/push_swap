/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:05:50 by dthan             #+#    #+#             */
/*   Updated: 2023/04/05 16:42:00 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "stack_helper.h"
#include "../../libft/includes/libft.h"
#include <stdlib.h>
#define CONSTRUCTOR_SUCCESS 1
#define CONSTRUCTOR_FAILED 0

static int	stack_constructor_simple(t_stack *stack, int size)
{
	stack->data = (int *)malloc(sizeof(int) * size);
	stack->length = 0;
	stack->size = size;
	stack->name = ft_strdup("b");
	return (CONSTRUCTOR_SUCCESS);
}

static int	stack_constructor_complex(t_stack *stack, char **inputs, int size)
{
	int	index;

	index = 0;
	stack->size = size;
	stack->data = (int *)malloc(sizeof(int) * size);
	stack->length = 0;
	stack->name = ft_strdup("a");
	while (inputs[index])
	{
		if (is_number(inputs[stack->length]) && \
			!is_dup(inputs[stack->length], stack))
			stack_add(stack, ft_atoi(inputs[index]));
		else
			return (CONSTRUCTOR_FAILED);
		index++;
	}
	return (CONSTRUCTOR_SUCCESS);
}

static t_stack	*stack_destructor(t_stack *stack)
{
	free(stack->data);
	free(stack->name);
	free(stack);
	return (NULL);
}

void	delete_stack_object(t_stack *stack)
{
	stack_destructor(stack);
}

t_stack	*new_stack_object(char **inputs, int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!inputs)
		stack_constructor_simple(stack, size);
	else if (stack_constructor_complex(stack, inputs, size) == \
		CONSTRUCTOR_FAILED)
		return (stack_destructor(stack));
	return (stack);
}
