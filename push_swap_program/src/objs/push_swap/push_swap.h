/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:18:08 by dthan             #+#    #+#             */
/*   Updated: 2023/01/29 15:18:30 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../../../../shared-objs/data/data.h"
#define ASCENDING 0
#define DESCENDING 1

typedef struct s_config
{
	const int colour_the_last_operation;
	const int display_stacks;
} t_config;

typedef struct s_push_swap
{
	t_data *data;
	t_config *config;
	const t_node *global_biggest_number_node;
	const t_node *global_smallest_number_node;
}	t_push_swap;

int			push_swap_constructor(t_push_swap *program, char **argv);
t_push_swap	*push_swap_destructor(t_push_swap *program);
t_push_swap	*new_push_swap(char **argv);
unsigned int push_swap_run(t_push_swap *program);

#endif