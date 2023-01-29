/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:59:21 by dthan             #+#    #+#             */
/*   Updated: 2023/01/29 20:25:58 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "../node/node.h"

typedef struct s_stack {
	t_node			*first_node;
	t_node			*last_node;
	unsigned int	count;
	char			*name;
}	t_stack;

t_stack	*new_stack(char **argv);
t_stack	*stack_destructor(t_stack *stack);
t_node	*stack_pop(t_stack *stack);
t_node	*stack_pop_top(t_stack *stack);
t_node *stack_get_biggest_number_node(t_stack *stack);
t_node *stack_get_smallest_number_node(t_stack *stack);
t_node *stack_get_closet_smaller_number_node(t_stack *stack, const t_node *number_node);
t_node *stack_get_closet_bigger_number_node(t_stack *stack, const t_node *number_node);
t_node *stack_get_node_at(t_stack *stack, unsigned int index_pos);
unsigned int stack_find_index(t_stack *stack, t_node *look_up_node);
void	stack_push(t_stack *stack, t_node *node);
void	stack_push_top(t_stack *stack, t_node *node);
void	stack_swap(t_stack *stack);
int		stack_is_empty(t_stack *stack);
int		stack_is_ascending_sorted(t_stack *stack);
int		stack_is_descending_sorted(t_stack *stack);
#endif