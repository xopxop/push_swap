/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:35:19 by dthan             #+#    #+#             */
/*   Updated: 2023/01/07 01:40:40 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H
#include "../shared-objs/stack/stack.h"

void	execute_instruction(t_stack *stack_a, t_stack *stack_b, char *command);
void	print_state(t_stack *stack_a, t_stack *stack_b, char *instruction);
#endif
