#include "lib.h"

static unsigned int pre_sort(t_push_swap *program)
{
	t_node *biggest_node = stack_get_biggest_number_node(program->data->stack_a);
	t_node *smallest_node = stack_get_smallest_number_node(program->data->stack_a);
	t_node *node = program->data->stack_a->first_node;
	unsigned int operation_count = 0;

	while (program->data->stack_a->count > 2)
	{
		if (node == biggest_node || node == smallest_node)
			operation_count += execute_instruction(program->data, "ra");
		else
			operation_count += execute_instruction(program->data, "pb");
		node = node->next;
	}
	return operation_count;
}

void sth(t_push_swap *program)
{
	int max_moves = program->data->stack_a->count + program->data->stack_b->count;
	t_node *node = program->data->stack_b->first_node;
	t_node *best_node_in_stack_a;
	t_node *best_node_in_stack_b;

	while (node)
	{
		best_node_in_stack_b = node;
		
		node = node->next;
	}
}

static unsigned int real_sort(t_push_swap *program)
{
	while (program->data->stack_b->count)
	{

	}
}

unsigned int algo_min_10_5(t_push_swap *program)
{
	unsigned int operation_count_step_1 = pre_sort(program);
}