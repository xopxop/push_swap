/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_service_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:06:01 by dthan             #+#    #+#             */
/*   Updated: 2023/04/05 15:43:24 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing_service.h"
#include "../../../../libft/includes/libft.h"
#include "../../objs/checker/checker.h"

static int	count_column(int number)
{
	int	column;

	column = 0;
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

static int	get_max_cols(t_stack *stack)
{
	int	index;
	int	max_cols;
	int	cols;

	index = 0;
	max_cols = 0;
	while (index < stack->length)
	{
		cols = count_column(stack->data[index]);
		if (cols > max_cols)
			max_cols = cols;
		index++;
	}
	return (max_cols);
}

static int	get_rows(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->length > stack_b->length)
		return (stack_a->length);
	return (stack_b->length);
}

void	init_printing_service(
	t_printing_service *service,
	t_checker *checker,
	int instruction_index,
	t_execution_info *exec_info)
{
	int	max_cols_a;
	int	max_cols_b;

	max_cols_a = get_max_cols(checker->data->stack_a);
	max_cols_b = get_max_cols(checker->data->stack_b);
	service->data_ptr = checker->data;
	service->exec_info_ptr = exec_info;
	service->config_ptr = checker->config;
	if (instruction_index == -1)
		service->instruction_ptr = NULL;
	else
		service->instruction_ptr = checker->instructions[instruction_index];
	service->print_row_info_service.max_cols_a = max_cols_a;
	service->print_row_info_service.max_cols_b = max_cols_b;
	service->print_row_info_service.a = NULL;
	service->print_row_info_service.b = NULL;
	service->print_row_info_service.color_info.color_a = 0;
	service->print_row_info_service.color_info.color_b = 0;
	service->rows = get_rows(checker->data->stack_a, checker->data->stack_b);
	service->index_a = 0;
	service->index_b = 0;
}
