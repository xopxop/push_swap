/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data-printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:26:31 by dthan             #+#    #+#             */
/*   Updated: 2023/03/25 20:33:08 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "data-printer.h"
#include "data-printing-helper.h"

static int count_column(int number)
{
	int column = 0;

	if (number < 0)
	{
		column++;
		number *= -1;
	}
	while (number)
	{
		column++;
		number /= 10;
	}
	return (column);
}

static int get_max_cols(t_stack *stack)
{
	int index = 0;
	int max_cols = 0;
	int cols;

	while (index < stack->length)
	{
		cols = count_digit(stack->data[index]);
		if (cols > max_cols)
			max_cols = cols;
		index++;
	}
	return max_cols;
}

void printer_print(t_printer *printer)
{
	print_separator();
	print_instruction(printer->instruction);
	print_data(*printer);
}

t_printer *new_printer_object(t_data *data, char *instruction)
{
	t_printer *printer;

	printer = (t_printer*)malloc(sizeof(t_printer));
	if (data->stack_a->length > data->stack_b->length)
		printer->rows = data->stack_a->length;
	else
		printer->rows = data->stack_b->length;
	printer->max_cols_a = get_max_cols(data->stack_a);
	printer->max_cols_b = get_max_cols(data->stack_b);
	printer->data = data;
	printer->instruction = instruction;
	return printer;
}

void delete_printer_object(t_printer *obj)
{
	free(obj);
}
