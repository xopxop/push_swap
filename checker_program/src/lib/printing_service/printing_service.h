/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_service.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:08:03 by dthan             #+#    #+#             */
/*   Updated: 2023/04/05 15:52:46 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTING_SERVICE_H
# define PRINTING_SERVICE_H
# include "../../objs/checker/checker.h"

typedef struct s_color_info
{
	int	color_a;
	int	color_b;
}	t_color_info;

typedef struct s_printing_row_info_service
{
	int				*a;
	int				*b;
	int				max_cols_a;
	int				max_cols_b;
	t_color_info	color_info;
}	t_printing_row_info_service;

typedef struct s_printing_service
{
	t_data						*data_ptr;
	t_execution_info			*exec_info_ptr;
	t_config					*config_ptr;
	char						*instruction_ptr;
	t_printing_row_info_service	print_row_info_service;
	int							index_a;
	int							index_b;
	int							rows;
}	t_printing_service;

void	display_stacks(t_checker *checker, int instruction_index, t_execution_info *exec_info);

#endif
