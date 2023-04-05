/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_service_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:31:47 by dthan             #+#    #+#             */
/*   Updated: 2023/04/05 15:36:17 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing_service.h"
#include <unistd.h>

static void	reset_printing_service_3(t_printing_service *printing_service)
{
	if ((printing_service->data_ptr->stack_b->length - printing_service->rows)
		>= 0)
	{
		printing_service->print_row_info_service.b = \
		&(printing_service->data_ptr->stack_b->data[printing_service->index_b]);
		if (\
		printing_service->config_ptr->colour_the_last_operation && (\
		(printing_service->index_b == \
		printing_service->exec_info_ptr->color_b1) || \
		(printing_service->index_b == \
		printing_service->exec_info_ptr->color_b2)) \
		)
			printing_service->print_row_info_service.color_info.color_b = 1;
		printing_service->index_b++;
	}
}

static void	reset_printing_service_2(t_printing_service *printing_service)
{
	if ((printing_service->data_ptr->stack_a->length - printing_service->rows)
		>= 0)
	{
		printing_service->print_row_info_service.a = \
		&(printing_service->data_ptr->stack_a->data[printing_service->index_a]);
		if (\
		printing_service->config_ptr->colour_the_last_operation && (\
		(printing_service->index_a == \
		printing_service->exec_info_ptr->color_a1) || \
		(printing_service->index_a == \
		printing_service->exec_info_ptr->color_a2)) \
		)
			printing_service->print_row_info_service.color_info.color_a = 1;
		printing_service->index_a++;
	}
}

void	reset_printing_service(t_printing_service *printing_service)
{
	printing_service->print_row_info_service.a = NULL;
	printing_service->print_row_info_service.b = NULL;
	printing_service->print_row_info_service.color_info.color_a = 0;
	printing_service->print_row_info_service.color_info.color_b = 0;
	reset_printing_service_2(printing_service);
	reset_printing_service_3(printing_service);
}
