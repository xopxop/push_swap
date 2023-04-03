/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing-service.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:08:03 by dthan             #+#    #+#             */
/*   Updated: 2023/03/29 18:56:56 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTING_SERVICE_H
# define PRINTING_SERVICE_H
#include "../../../../shared-objs/data/data.h"
#include "../../../../shared-objs/config/config.h"

typedef struct s_color_info
{
	int color_a;
	int color_b;
} t_color_info;

typedef struct s_printing_row_info_service
{
	int *a;
	int *b;
	int max_cols_a;
	int max_cols_b;
	t_color_info color_info;
} t_printing_row_info_service;

typedef struct s_printing_service
{
	t_data *data_ptr;
	t_execution_info *exec_info_ptr;
	t_config *config_ptr;
	char* instruction_ptr;
	t_printing_row_info_service print_row_info_service;
	int index_a;
	int index_b;
	int rows;
} t_printing_service;

void display_stacks(t_config *config, t_data *data, char *instruction, t_execution_info *exec_info);

#endif
