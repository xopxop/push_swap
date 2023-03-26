/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data-printing-helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:06:01 by dthan             #+#    #+#             */
/*   Updated: 2023/03/25 20:31:53 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <sys/ioctl.h>
#include <unistd.h>
#include "data.h"
#include "data-printer.h"

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


static void print_row(int max_col_a, int *a, int max_col_b, int *b)
{
	if (a && b)
		ft_printf("%*d %*d\n", max_col_a, *a, max_col_b, *b);
	else if (a)
		ft_printf("%*d\n", max_col_a, *a);
	else if (b)
		ft_printf("%*c %*d\n", max_col_a, ' ', max_col_b, *b);
	else
		ft_printf("%*c %*s\n%*s %*s\n", max_col_a, ' ', max_col_b, ' ');		
}

void print_datat_printer printer)
{
	t_data *data = printer.data;
	int index_a = 0;
	int index_b = 0;

	while (printer.rows > 0)
	{
		if ((data->stack_a->length - printer.rows) >= 0 && (data->stack_b->length - printer.rows) >= 0)
		{
			print_row(printer.max_cols_a, &data->stack_a->data[index_a], printer.max_cols_b, &data->stack_b->data[index_b]);
			index_a++;
			index_b++;
		}
		else if ((data->stack_a->length - printer.rows) >= 0)
		{
			print_row(printer.max_cols_a, &data->stack_a->data[index_a], printer.max_cols_b, NULL);
			index_a++;
		}
		else if ((data->stack_b->length - printer.rows) >= 0)
		{
			print_row(printer.max_cols_a, NULL, printer.max_cols_b, &data->stack_b->data[index_b]);
			index_b++;
		}
		printer.rows--;
	}
	print_row(printer.max_cols_a, NULL, printer.max_cols_b, NULL);
}
