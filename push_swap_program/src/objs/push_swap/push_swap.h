/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:18:08 by dthan             #+#    #+#             */
/*   Updated: 2023/04/03 06:02:20 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../../../../shared-objs/data/data.h"
#define ASCENDING 0
#define DESCENDING 1

typedef struct s_push_swap
{
	t_data *data;
}	t_push_swap;

t_push_swap	*new_push_swap_object(char **argv);
void delete_push_swap_object(t_push_swap *program);
int push_swap_run(t_push_swap *program);

#endif