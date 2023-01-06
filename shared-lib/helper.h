/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:35:19 by dthan             #+#    #+#             */
/*   Updated: 2022/11/29 12:36:08 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H
#include "../shared-objs/stack/stack.h"

void	execute_instruction(t_stack *stack_a, t_stack *stack_b, char *command);
#endif
