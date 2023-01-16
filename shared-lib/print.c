#include <sys/ioctl.h>
#include <unistd.h>
#include "../libft/includes/libft.h"
#include "../shared-objs/stack/stack.h"
#include "../shared-objs/node/node.h"

void print_separator()
{
	struct winsize w;
	int index;

	index = 0;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	while (index < w.ws_col)
	{
		write(STDOUT_FILENO, "-", 1);
		index++;
	}
}

void print_instruction(char *instruction)
{
	if (instruction)
		ft_printf("Exec %s:\n", instruction);
	else
		write(STDOUT_FILENO, "Init a and b:\n", 14);
}

#include "stdio.h"


void print_row(int max_col_a, t_node *node_a, int max_col_b, t_node *node_b)
{
	if (node_a && node_b)
		ft_printf("%*d %*d\n", max_col_a, node_a->data, max_col_b, node_b->data);
	else if (node_a)
		ft_printf("%*d\n", max_col_a, node_a->data);
	else if (node_b)
		ft_printf("%*c %*d\n", max_col_a, ' ', max_col_b, node_b->data);
	else
		ft_printf("%*c %*s\n%*s %*s\n", max_col_a, ' ', max_col_b, ' ');		
}

void print_execution(t_node *node_a, t_node *node_b, unsigned int n_a, unsigned int n_b, int row_index)
{
	if ((int)(n_a - row_index) >= 0 && (int)(n_b - row_index) >= 0)
	{
		print_row(max_col_a, node_a, max_col_b, node_b);
		node_a = node_a->next;
		node_b = node_b->next;
	}
	else if ((int)(stack_a->count - row_index) >= 0)
	{
		print_row(max_col_a, node_a, max_col_b, node_b);
		node_a = node_a->next;
	}
	else if ((int)(stack_b->count - row_index) >= 0)
	{
		print_row(max_col_a, node_a, max_col_b, node_b);
		node_b = node_b->next;
	}
}

typedef struct s_state_printer {
	unsigned int max_cols_a;
	unsigned int max_cols_b;
	unsigned int rows;
} t_state_printer;

void print_stacks(t_stack* stack_a, t_stack *stack_b)
{
	int row_index;
	t_node *node_a;
	t_node *node_b;

	if (stack_a->count > stack_b->count)
		row_index = stack_a->count;
	else
		row_index = stack_b->count;
	node_a = stack_a->first_node;
	node_b = stack_b->first_node;
	int max_col_a;
	int max_col_b;
	while (row_index > 0)
	{
		if ((int)(stack_a->count - row_index) >= 0 && (int)(stack_b->count - row_index) >= 0)
		{
			print_row(max_col_a, node_a, max_col_b, node_b);
			node_a = node_a->next;
			node_b = node_b->next;
		}
		else if ((int)(stack_a->count - row_index) >= 0)
		{
			print_row(max_col_a, node_a, max_col_b, node_b);
			node_a = node_a->next;
		}
		else if ((int)(stack_b->count - row_index) >= 0)
		{
			print_row(max_col_a, node_a, max_col_b, node_b);
			node_b = node_b->next;
		}
		row_index--;
	}
	print_row(max_col_a, NULL, max_col_b, NULL);
}

int get_max_cols(t_stack *stack)
{
	t_node *node;
	int max_cols;
	int cols;
	int number;

	max_cols = 0;
	node = stack->first_node;
	while (node)
	{
		cols = 0;
		number = node->data;
		if (number < 0)
		{
			number
			cols++;
		}
		if ((node->data % 10))
		node = node->next;
	}
	return max_cols;
}

t_state_printer *new_state_printer(t_stack *stack_a, t_stack *stack_b)
{
	t_state_printer *printer;

	printer = (t_state_printer*)malloc(sizeof(t_state_printer));
	if (stack_a->count > stack_b->count)
		printer->rows = stack_a->count;
	else
		printer->rows = stack_b->count;
	printer->max_cols_a = get_max_cols();
	printer->max_cols_b = get_max_cols();
	return printer;
}

void print_state(t_stack *stack_a, t_stack *stack_b, char *instruction)
{
	t_state_printer *printer;

	printer = new_state_printer(stack_a, stack_b);
	print_separator();
	print_instruction(instruction);
	print_stacks(stack_a, stack_b);
}