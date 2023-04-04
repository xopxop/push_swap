/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tool.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:54:55 by dthan             #+#    #+#             */
/*   Updated: 2023/04/04 23:02:53 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_TOOL_H
# define ALGO_TOOL_H
# include "../../../shared-objs/data/data.h"
# include "../objs/move/move.h"

int		execute_the_best_move(t_data *data, t_move *move);
t_move	*find_the_best_move(t_data *data);

#endif
