/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:25:06 by dthan             #+#    #+#             */
/*   Updated: 2022/11/29 11:36:48 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../../../../shared-objs/stack/stack.h"

typedef struct s_checker {
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**instructions;
}	t_checker;

t_checker	*new_checker(int argc, char **argv);
int			checker_constructor(t_checker *program, int argc, char **argv);
t_checker	*checker_destructor(t_checker *program);
int			checker_execute_instructions(t_checker *program);
void		checker_execute_instruction(t_checker *program, char *command);
#endif