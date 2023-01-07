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
	
	while (row_index > 0)
	{
		if ((int)(stack_a->count - row_index) >= 0)
		{
			ft_printf("%d", node_a->data);
			node_a = node_a->next;
		}
		else
			write(STDOUT_FILENO, " ", 1);
		if ((int)(stack_b->count - row_index) >= 0)
		{
			ft_printf(" %d\n", node_b->data);
			node_b = node_b->next;
		}
		else
			write (STDOUT_FILENO, "\n", 1);
		row_index--;
	}
	write (STDOUT_FILENO, "_ _\n", 4);
	write (STDOUT_FILENO, "a b\n", 4);
}

void print_state(t_stack *stack_a, t_stack *stack_b, char *instruction)
{
	print_separator();
	print_instruction(instruction);
	print_stacks(stack_a, stack_b);
}