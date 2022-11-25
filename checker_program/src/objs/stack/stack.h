/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:59:21 by dthan             #+#    #+#             */
/*   Updated: 2022/11/23 18:45:26 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
#define STACK_H
#include "../node/node.h"

typedef struct s_stack {
  t_node *first_node;
  t_node *last_node;
  // can change uint
  uint16_t count;
} t_stack;

t_stack *new_stack(int argc, char** argv);
int stack_constructor_simple(t_stack *stack);
int stack_constructor_complex(t_stack *stack, int argc, char** argv);
t_stack *stack_destructor(t_stack *stack);
t_node *stack_pop(t_stack *stack);
t_node *stack_pop_top(t_stack *stack);
void stack_push(t_stack* stack, t_node *node);
void stack_push_top(t_stack *stack, t_node *node);
void stack_swap(t_stack *stack);
bool is_empty(t_stack *stack);
bool is_sorted(t_stack *stack);

#endif