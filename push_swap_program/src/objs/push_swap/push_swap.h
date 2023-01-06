/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:18:08 by dthan             #+#    #+#             */
/*   Updated: 2022/11/29 15:58:28 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../../../../shared-objs/stack/stack.h"

typedef struct s_push_swap
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_push_swap;

int			push_swap_constructor(t_push_swap *program, char **argv);
t_push_swap	*push_swap_destructor(t_push_swap *program);
t_push_swap	*new_push_swap(char **argv);
void		push_swap_run(t_push_swap *program);

#endif