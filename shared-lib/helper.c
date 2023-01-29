/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:32:11 by dthan             #+#    #+#             */
/*   Updated: 2023/01/29 16:56:32 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"
#include <stddef.h>
#include "../libft/includes/libft.h"
#define A_ONLY 1
#define B_ONLY 2
#define BOTH 3

unsigned int do_swap(t_stack *stack_a, t_stack *stack_b, int op)
{
	if (op == A_ONLY)
	{
		if (stack_a->count > 1)
			stack_swap(stack_a);
	}
	else if (op == B_ONLY)
	{
		if (stack_b->count > 1)
			stack_swap(stack_b);
	}
	else if (op == BOTH)
	{
		do_swap(stack_a, NULL, A_ONLY);
		do_swap(NULL, stack_b, B_ONLY);
	}
	return (1);
}

unsigned int	do_push(t_stack *stack_a, t_stack *stack_b, int op)
{
	if (op == A_ONLY)
	{
		if (stack_b->count > 0)
			stack_push_top(stack_a, stack_pop_top(stack_b));
	}
	else if (op == B_ONLY)
	{
		if (stack_a->count > 0)
			stack_push_top(stack_b, stack_pop_top(stack_a));
	}
	return (1);
}

unsigned int	do_rotate(t_stack *stack_a, t_stack *stack_b, int op)
{
	if (op == A_ONLY)
	{
		if (stack_a->count > 1)
			stack_push(stack_a, stack_pop_top(stack_a));
	}
	else if (op == B_ONLY)
	{
		if (stack_b->count > 1)
			stack_push(stack_b, stack_pop_top(stack_b));
	}
	else if (op == BOTH)
	{
		do_rotate(stack_a, stack_b, A_ONLY);
		do_rotate(stack_a, stack_b, B_ONLY);
	}
	return (1);
}

unsigned int	do_reverse_rotate(t_stack *stack_a, t_stack *stack_b, int op)
{
	if (op == A_ONLY)
	{
		if (stack_a->count > 1)
			stack_push_top(stack_a, stack_pop(stack_a));
	}
	else if (op == B_ONLY)
	{
		if (stack_b->count > 1)
			stack_push_top(stack_b, stack_pop(stack_b));
	}
	else if (op == BOTH)
	{
		do_reverse_rotate(stack_a, stack_b, A_ONLY);
		do_reverse_rotate(stack_a, stack_b, B_ONLY);
	}
	return (1);
}

void print_instruction(char *instruction)
{
	if (instruction)
	{
		ft_putstr("Exec ");
		ft_putstr(instruction);
		ft_putendl(":");
	}
	else
		ft_putendl("Init a and b:");
}

int get_max_cols(t_stack *stack)
{
	t_node *node;
	int max_cols = 1;
	int cols;
	int number;

	node = stack->first_node;
	while (node)
	{
		cols = 0;
		number = node->data;
		if (number < 0)
		{
			number *= -1;
			cols++;
		}
		while (number != 0)
		{
			number /= 10;
			cols++;
		}
		if (cols > max_cols)
			max_cols = cols;
		node = node->next;
	}
	return max_cols;
}

#include <stdio.h>

void print_stacks(t_data *data)
{
	t_stack *stack_a = data->stack_a;
	t_stack *stack_b = data->stack_b;
	unsigned int max_cols_stack_a = get_max_cols(stack_a);
	unsigned int max_cols_stack_b = get_max_cols(stack_b);
	unsigned int max_rows = 0;

	if (stack_a->count >= stack_b->count)
		max_rows = stack_a->count;
	else
		max_rows = stack_b->count;
	t_node *node_a = stack_a->first_node;
	t_node *node_b = stack_b->first_node;
	while (max_rows > 0)
	{
		if (stack_a->count >= max_rows)
		{
			printf("%*d", max_cols_stack_a, node_a->data);
			node_a = node_a->next;
		}
		else
		{
			printf("%*s", max_cols_stack_a, "");
		}
		if (stack_b->count >= max_rows)
		{
			printf("%*d\n", max_cols_stack_b, node_b->data);
			node_b = node_b->next;
		}
		else
		{
			printf("\n");
		}
		max_rows--;
	}
	printf("- -\n%c %c\n", 'a', 'b');
	// sleep(1);
}

void print_data(t_data *data, char *instruction)
{
	// clear content
	// isatty(STDIN_FILENO);
	print_instruction(instruction);
	print_stacks(data);
}

unsigned int	execute_instruction_2(t_stack *stack_a, t_stack *stack_b, char *command)
{
	if (!ft_strcmp(command, "sa"))
		return do_swap(stack_a, stack_b, A_ONLY);
	else if (!ft_strcmp(command, "sb"))
		return do_swap(stack_a, stack_b, B_ONLY);
	else if (!strcmp(command, "ss"))
		return do_swap(stack_a, stack_b, BOTH);
	else if (!strcmp(command, "pa"))
		return do_push(stack_a, stack_b, A_ONLY);
	else if (!strcmp(command, "pb"))
		return do_push(stack_a, stack_b, B_ONLY);
	else if (!strcmp(command, "ra"))
		return do_rotate(stack_a, stack_b, A_ONLY);
	else if (!strcmp(command, "rb"))
		return do_rotate(stack_a, stack_b, B_ONLY);
	else if (!strcmp(command, "rr"))
		return do_rotate(stack_a, stack_b, BOTH);
	else if (!strcmp(command, "rra"))
		return do_reverse_rotate(stack_a, stack_b, A_ONLY);
	else if (!strcmp(command, "rrb"))
		return do_reverse_rotate(stack_a, stack_b, B_ONLY);
	else if (!strcmp(command, "rrr"))
		return do_reverse_rotate(stack_a, stack_b, BOTH);
	return (0);
}

unsigned int	execute_instruction(t_data *data, char *instruction)
{
	unsigned int operation_count = execute_instruction_2(data->stack_a, data->stack_b, instruction);
	// if (config)
	// {
	// 	print_data(data);
	// }
	// else
	// 	ft_putendl(instruction);
	print_data(data, instruction);
	return operation_count;
}
