/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:25:06 by dthan             #+#    #+#             */
/*   Updated: 2023/03/24 16:56:51 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../../../../shared-objs/data/data.h"

typedef struct s_checker {
	t_data *data;
	char	**instructions;
}	t_checker;

t_checker	*new_checker_object(char **argv);
void delete_checker_object(t_checker *object);
int	checker_execute_instructions(t_checker *program);

#endif