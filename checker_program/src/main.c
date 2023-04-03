/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:58:34 by dthan             #+#    #+#             */
/*   Updated: 2023/03/27 05:57:17 by dthan            ###   ########.fr       */
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
		checker = new_checker_object(&argv[1]);
		if (checker)
		{
			ret = checker_execute_instructions(checker);
			delete_checker_object(checker);
		}
	}
	return (ret);
}
