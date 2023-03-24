/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data-modification-helper.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:42:07 by dthan             #+#    #+#             */
/*   Updated: 2023/03/23 19:56:07 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_MODIFICATION_HELPER_H
# define DATA_MODIFICATION_HELPER_H
#define A_ONLY 1
#define B_ONLY 2
#define BOTH 3
#include "../stack/stack.h"

int	execute_instruction(t_stack *stack_a, t_stack *stack_b, char *command);

#endif