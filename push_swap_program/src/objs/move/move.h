/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:26:37 by dthan             #+#    #+#             */
/*   Updated: 2023/04/04 23:08:21 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

typedef struct s_move
{
	int	rotate_a;
	int	rotate_b;
	int	total_moves;
}	t_move;

t_move	*new_move_object(int rotate_a, int rotate_b);
void	delete_move_object(t_move *option);

#endif
