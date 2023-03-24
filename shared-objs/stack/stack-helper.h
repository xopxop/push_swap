/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack-helper.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:12:54 by dthan             #+#    #+#             */
/*   Updated: 2023/03/23 17:20:55 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HELPER_H
# define STACK_HELPER_H
#include "stack.h"

int	is_dup(char *argv, t_stack *stack);
int	is_number(char *argv);

#endif
