/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo-min-4-helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:08:32 by dthan             #+#    #+#             */
/*   Updated: 2023/04/03 06:33:33 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../shared-objs/data/data.h"
#include "../objs/move/move.h"
#include "../../../libft/includes/libft.h"

static int execute_rotate_double_stacks(t_data *data, t_move *move, int reverse)
{
	int operation_count = 0;
	int max;

	if (!reverse)
	{
		max = (move->rotate_a <= move->rotate_b) ? move->rotate_a : move->rotate_b;
		for (int i = 0; i < max; i++)
		{
			operation_count += data_execute_instruction(data, "rr");
			move->rotate_a--;
			move->rotate_b--;
		}
	}
	else
	{
		max = (move->rotate_a >= move->rotate_b) ? move->rotate_a : move->rotate_b;
		for (int i = 0; i > max; i--)
		{
			operation_count += data_execute_instruction(data, "rrr");
			move->rotate_a++;
			move->rotate_b++;
		}
	}
	return operation_count;
}

static int execute_rotate_singular_stack(t_data *data, int *rotate, const char *stack_name)
{
	int operation_count = 0;
	char instruction[4];

	if (*rotate != 0)
	{
		if (*rotate > 0)
			ft_strcat(ft_strcpy(instruction, "r"), stack_name);
		else
			ft_strcat(ft_strcpy(instruction, "rr"), stack_name);
		while (*rotate != 0)
		{
			operation_count += data_execute_instruction(data, instruction);
			if (*rotate > 0)
				(*rotate)--;
			else
				(*rotate)++;
		}
	}
	return operation_count;
}

int execute_the_best_move(t_data *data, t_move *move)
{
	int operation_count = 0;

	if (move->rotate_a > 0 && move->rotate_b > 0)
		operation_count += execute_rotate_double_stacks(data, move, 0);
	else if (move->rotate_a < 0 && move->rotate_b < 0)
		operation_count += execute_rotate_double_stacks(data, move, 1);
	if (move->rotate_a != 0)
		operation_count += execute_rotate_singular_stack(data, &move->rotate_a, data->stack_a->name);		
	if (move->rotate_b != 0)
		operation_count += execute_rotate_singular_stack(data, &move->rotate_b, data->stack_b->name);	
	return operation_count;
}

static t_move *get_move(t_data *data, int number)
{
	int index_a;
	int index_b;
	int rotate_a = 0;
	int rotate_b = 0;

	index_a = stack_get_index(data->stack_a, stack_get_closet_bigger_number(data->stack_a, number));
	index_b = stack_get_index(data->stack_b, number);
	if (index_b != 0)
		rotate_b = (index_b <= data->stack_b->length / 2) ? index_b : -(data->stack_b->length - index_b);
	if (index_a != 0)
		rotate_a = (index_a <= data->stack_a->length / 2) ? index_a : -(data->stack_a->length - index_a);
	return new_move_object(rotate_a, rotate_b);
}

t_move *find_the_best_move(t_data *data)
{
	int index = 0;
	t_move *temp_strategy;
	t_move *best_move;
	t_move *current_move;
	
	while (index < data->stack_b->length)
	{
		if (index == 0)
			best_move = get_move(data, data->stack_b->data[index]);
		else
		{
			current_move = get_move(data, data->stack_b->data[index]);
			if (best_move->total_moves > current_move->total_moves)
			{
				temp_strategy = best_move;
				best_move = current_move;
				free(temp_strategy);
			}
			else
				free(current_move);
		}
		index++;
	}
	return best_move;
}
