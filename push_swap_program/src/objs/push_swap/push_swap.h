/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:18:08 by dthan             #+#    #+#             */
/*   Updated: 2023/01/27 14:29:19 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../../../../shared-objs/stack/stack.h"

typedef struct s_important_data
{

} 

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_node *biggest_number_node;
	t_node *smallest_number_node;
} t_data;

typedef struct s_range
{

} t_range;

typedef struct s_push_swap
{
	t_push_swap_option
}	t_push_swap;

int			push_swap_constructor(t_push_swap *program, char **argv);
t_push_swap	*push_swap_destructor(t_push_swap *program);
t_push_swap	*new_push_swap(char **argv);
void		push_swap_run(t_push_swap *program);

#endif