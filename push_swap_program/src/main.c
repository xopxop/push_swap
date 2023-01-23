/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:14:14 by dthan             #+#    #+#             */
/*   Updated: 2023/01/23 21:44:38 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objs/push_swap/push_swap.h"
#include <stdio.h>
#include "../../libft/includes/libft.h"

int	main(int argc, char **argv)
{
	t_push_swap *push_swap;

	if (argc > 1)
	{
		push_swap = new_push_swap(&argv[1]);
		if (push_swap)
		{
			ft_printf("Total: %d\n", push_swap_run(push_swap));
			push_swap_destructor(push_swap);
		}
	}
	return (1);
}
