/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:18:08 by dthan             #+#    #+#             */
/*   Updated: 2023/03/25 01:39:18 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../../../../shared-objs/data/data.h"
#define ASCENDING 0
#define DESCENDING 1

typedef struct s_config
{
	int colour_the_last_operation;
	int display_stacks;
	int read_and_write_from_file;
} t_config;

typedef struct s_push_swap
{
	t_data *data;
	t_config *config;
}	t_push_swap;

t_push_swap	*new_push_swap_object(char **argv);
void delete_push_swap_object(t_push_swap *program);
int push_swap_run(t_push_swap *program);

#endif