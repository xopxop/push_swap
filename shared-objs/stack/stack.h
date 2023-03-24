/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:02:10 by dthan             #+#    #+#             */
/*   Updated: 2023/03/24 13:42:51 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack
{
	int *data;
	int size;
	int length;
	char *name;
} t_stack;

t_stack	*new_stack_object(char **inputs, int size);
void delete_stack_object(t_stack *stack);
int	stack_is_sorted_in_ascending_order(t_stack *stack);
int stack_get_biggest_number(t_stack *stack);
int stack_get_smallest_number(t_stack *stack);
int stack_get_closet_bigger_number(t_stack *stack, const int number);
int stack_get_index(t_stack *stack, int number);
void	stack_push(t_stack *stack, int element);
int stack_pop(t_stack *stack);
void stack_add(t_stack *stack, int element);
int	stack_reduce(t_stack *stack);
void	stack_swap(t_stack *stack);

#endif