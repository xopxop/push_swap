/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:28:41 by dthan             #+#    #+#             */
/*   Updated: 2023/03/23 16:28:28 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"
#include <stdlib.h>

int ft_abs(int number)
{
	if (number < 0)
		return (-number);
	return (number);
}

t_move *new_move_object(int rotate_a, int rotate_b)
{
	t_move *move = (t_move*)malloc(sizeof(t_move));

	move->rotate_a = rotate_a;
	move->rotate_b = rotate_b;
	move->total_moves = ft_abs(rotate_a) + ft_abs(rotate_b);
	return (move);
}

void delete_instruction(t_move *move)
{
	free(move);
}
