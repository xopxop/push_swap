/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_lib.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:59:20 by dthan             #+#    #+#             */
/*   Updated: 2023/04/05 15:52:03 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_LIB_H
# define CHECKER_LIB_H
# include "../objs/checker/checker.h"
# include "./printing_service/printing_service.h"

void	display_stacks(
			t_checker *checker,
			int instruction_index,
			t_execution_info *exec_info);

#endif
