/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing-service-2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:06:01 by dthan             #+#    #+#             */
/*   Updated: 2023/04/03 05:49:11 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing-service.h"
#include "../../../../libft/includes/libft.h"
#define AC_YELLOW "\x1b[33m"
#define AC_NORMAL "\x1b[m"

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
		cols = count_column(stack->data[index]);
		if (cols > max_cols)
			max_cols = cols;
		index++;
	}
	return max_cols;
}

static int get_rows(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->length > stack_b->length)
		return (stack_a->length);
	return (stack_b->length);
}

void init_printing_service(t_printing_service *service, t_data *data, char *instruction, t_execution_info *exec_info, t_config* config)
{
	int max_cols_a;
	int max_cols_b;

	max_cols_a = get_max_cols(data->stack_a);
	max_cols_b = get_max_cols(data->stack_b);
	service->data_ptr = data;
	service->exec_info_ptr = exec_info;
	service->config_ptr = config;
	service->instruction_ptr = instruction;
	service->print_row_info_service.max_cols_a = max_cols_a;
	service->print_row_info_service.max_cols_b = max_cols_b;
	service->print_row_info_service.a = NULL;
	service->print_row_info_service.b = NULL;
	service->print_row_info_service.color_info.color_a = 0;
	service->print_row_info_service.color_info.color_b = 0;
	service->rows = get_rows(data->stack_a, data->stack_b);
	service->index_a = 0;
	service->index_b = 0;
}

void reset_printing_service(t_printing_service *printing_service)
{
	printing_service->print_row_info_service.a = NULL;
	printing_service->print_row_info_service.b = NULL;
	printing_service->print_row_info_service.color_info.color_a = 0;
	printing_service->print_row_info_service.color_info.color_b = 0;
	if ((printing_service->data_ptr->stack_a->length - printing_service->rows) >= 0)
	{
		printing_service->print_row_info_service.a = &(printing_service->data_ptr->stack_a->data[printing_service->index_a]);
		if ( \
			printing_service->config_ptr->colour_the_last_operation && ( \
			(printing_service->index_a == printing_service->exec_info_ptr->color_a1) || \
			(printing_service->index_a == printing_service->exec_info_ptr->color_a2)) \
		)
			printing_service->print_row_info_service.color_info.color_a = 1;
		printing_service->index_a++;
	}
	if ((printing_service->data_ptr->stack_b->length - printing_service->rows) >= 0)
	{
		printing_service->print_row_info_service.b = &(printing_service->data_ptr->stack_b->data[printing_service->index_b]);
		if ( \
			printing_service->config_ptr->colour_the_last_operation && ( \
			(printing_service->index_b == printing_service->exec_info_ptr->color_b1) || \
			(printing_service->index_b && printing_service->exec_info_ptr->color_b2)) \
		)
			printing_service->print_row_info_service.color_info.color_b = 1;
		printing_service->index_b++;
	}
}

void print_row(t_printing_row_info_service info)
{
	if (info.a || info.b)
	{
		if (info.a && info.color_info.color_a)
			ft_printf("%s%*d%s ", AC_YELLOW, info.max_cols_a, *info.a, AC_NORMAL);
		else if (info.a)
			ft_printf("%*d ", info.max_cols_a, *info.a);
		else
			ft_printf("%*s ", info.max_cols_a, "");		
		if (info.b && info.color_info.color_b)
			ft_printf("%s%*d%s\n", AC_YELLOW, info.max_cols_b, *info.b, AC_NORMAL);
		else if (info.b)
			ft_printf("%*d\n", info.max_cols_b, *info.b);
		else
			ft_putendl("");
	}
	else
	{
		// need to improve this
		ft_printf("%.*s %.*s\n", info.max_cols_a, "--------------", info.max_cols_b, "--------------");
		ft_printf("%-*c %-*c\n", info.max_cols_a, 'a', info.max_cols_b, 'b');
	}
}
