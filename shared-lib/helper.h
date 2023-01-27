/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:35:19 by dthan             #+#    #+#             */
/*   Updated: 2023/01/27 19:30:41 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H
#include "../shared-objs/data/data.h"

unsigned int	execute_instruction(t_stack *stack_a, t_stack *stack_b, char *command);
// unsigned int	execute_instruction_wrapper(t_data *data, t_config *config, char *instruction);
void	print_state(t_stack *stack_a, t_stack *stack_b, char *instruction);
#endif
