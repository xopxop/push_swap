#include "lib.h"

static unsigned int pre_sort(t_push_swap *program)
{
	t_node *biggest_node = stack_get_biggest_number_node(program->data->stack_a);
	t_node *smallest_node = stack_get_smallest_number_node(program->data->stack_a);
	t_node *node;
	unsigned int operation_count = 0;

	while (program->data->stack_a->count > 2)
	{
		node = program->data->stack_a->first_node;
		if (node == biggest_node || node == smallest_node)
			operation_count += execute_instruction(program->data, "ra");
		else
			operation_count += execute_instruction(program->data, "pb");
		node = node->next;
	}
	return operation_count;
}

// 
typedef struct s_strategy
{
	int rotate_a;
	int rotate_b;
	unsigned int total_moves;
	t_node *node;
} t_strategy;

#include <stdio.h>
t_strategy *get_strategy(t_data *data, t_node *node)
{
	t_strategy *strategy = (t_strategy*)malloc(sizeof(t_strategy));
	strategy->rotate_a = 0;
	strategy->rotate_b = 0;
	strategy->total_moves = 1;
	t_stack *stack_a = data->stack_a;
	t_stack *stack_b = data->stack_b;
	unsigned int index_a;
	unsigned int index_b;

	index_b = stack_find_index(data->stack_b, node);
	if (index_b != 0)
		strategy->rotate_b = (index_b <= stack_b->count / 2) ? index_b : -(stack_b->count - index_b);
	index_a = stack_find_index(stack_a, stack_get_closet_bigger_number_node(stack_a, node));
	if (index_a != 0)
		strategy->rotate_a = (index_a <= stack_a->count / 2) ? index_a : -(stack_a->count - index_a);
	// need to create abs function
	strategy->total_moves += abs(strategy->rotate_a) + abs(strategy->rotate_b);
	strategy->node = node;
	printf("[number:%d][index_b:%d]-[index_a:%d]-[rotate_a:%d]-[rotate_b:%d]-[total:%d]\n", strategy->node->data, index_b, index_a, strategy->rotate_a, strategy->rotate_b, strategy->total_moves);
	return strategy;
}

// finding the best strategy
t_strategy *find_best_strategy(t_data *data)
{
	t_node *node = data->stack_b->first_node;
	t_strategy *temp_strategy;
	t_strategy *best_strategy;
	t_strategy *current_strategy;

	while (node)
	{
		if (node == data->stack_b->first_node)
			best_strategy = get_strategy(data, node);
		else
		{
			current_strategy = get_strategy(data, node);
			if (best_strategy->total_moves > current_strategy->total_moves)
			{
				temp_strategy = best_strategy;
				best_strategy = current_strategy;
				free(temp_strategy);
			}
			else
				free(current_strategy);
		}
		node = node->next;
	}
	return best_strategy;
}

unsigned int execute_rotate_double_stacks(t_data *data, t_strategy *strategy, int reverse)
{
	unsigned int operation_count = 0;
	int max;

	if (!reverse)
	{
		max = (strategy->rotate_a <= strategy->rotate_b) ? strategy->rotate_a : strategy->rotate_b;
		for (int i = 0; i < max; i++)
		{
			operation_count += execute_instruction(data, "rr");
			strategy->rotate_a--;
			strategy->rotate_b--;
		}
	}
	else
	{
		max = (strategy->rotate_a >= strategy->rotate_b) ? strategy->rotate_a : strategy->rotate_b;
		for (int i = 0; i > max; i--)
		{
			operation_count += execute_instruction(data, "rrr");
			strategy->rotate_a++;
			strategy->rotate_b++;
		}
	}
	return operation_count;
}

unsigned int execute_rotate_singular_stack(t_data *data, int *rotate, char *stack_name)
{
	unsigned int operation_count = 0;
	char instruction[4];

	if (*rotate != 0)
	{
		if (*rotate > 0)
			ft_strcat(ft_strcpy(instruction, "r"), stack_name);
		else
			ft_strcat(ft_strcpy(instruction, "rr"), stack_name);
		while (*rotate != 0)
		{
			operation_count += execute_instruction(data, instruction);
			if (*rotate > 0)
				(*rotate)--;
			else
				(*rotate)++;
		}
	}
	return operation_count;
}

unsigned int execute_strategy(t_data *data, t_strategy *strategy)
{
	unsigned int operation_count = 0;

	if (strategy->rotate_a > 0 && strategy->rotate_b > 0)
		operation_count += execute_rotate_double_stacks(data, strategy, 0);
	else if (strategy->rotate_a < 0 && strategy->rotate_b < 0)
		operation_count += execute_rotate_double_stacks(data, strategy, 1);
	if (strategy->rotate_a != 0)
		operation_count += execute_rotate_singular_stack(data, &strategy->rotate_a, data->stack_a->name);		
	if (strategy->rotate_b != 0)
		operation_count += execute_rotate_singular_stack(data, &strategy->rotate_b, data->stack_b->name);	
	operation_count	+= execute_instruction(data, "pa");
	return operation_count;
}

static unsigned int real_sort(t_push_swap *program)
{
	t_strategy *strategy;
	unsigned int operation_count = 0;

	while (program->data->stack_b->count)
	{
		strategy = find_best_strategy(program->data);
		operation_count += execute_strategy(program->data, strategy);
		free(strategy);	
	}
	return operation_count;
}

unsigned int algo_min_10_5(t_push_swap *program)
{
	unsigned int operation_count_step_1 = pre_sort(program);
	unsigned int operation_count_step_2 = real_sort(program);
	unsigned int operation_count_step_3 = move_node_to_top(program->data, program->data->stack_a, stack_get_smallest_number_node(program->data->stack_a));

	return operation_count_step_1 + operation_count_step_2 + operation_count_step_3;
}