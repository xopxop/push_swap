/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:14:14 by dthan             #+#    #+#             */
/*   Updated: 2023/04/04 21:53:05 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objs/push_swap/push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	*push_swap;

	(void)argc;
	push_swap = new_push_swap_object(&argv[1]);
	if (push_swap)
	{
		push_swap_run(push_swap);
		delete_push_swap_object(push_swap);
		return (1);
	}
	return (0);
}
