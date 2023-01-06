/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:58:34 by dthan             #+#    #+#             */
/*   Updated: 2022/11/28 09:49:54 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objs/checker/checker.h"

int	main(int argc, char **argv)
{
	t_checker	*checker;
	int			ret;

	ret = 1;
	if (argc > 1)
	{
		checker = new_checker(argc - 1, &argv[1]);
		if (checker)
		{
			ret = checker_execute_instructions(checker);
			checker_destructor(checker);
		}
	}
	return (ret);
}
