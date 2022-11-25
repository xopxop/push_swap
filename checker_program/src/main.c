/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:58:34 by dthan             #+#    #+#             */
/*   Updated: 2022/11/24 12:46:58 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objs/checker/checker.h"

int main(int argc, char **argv) {
	t_checker *checker;
	int ret;

	ret = 0;
	if (argc > 1) {
		(void)argv;
		checker = new_checker(argc - 1, &argv[1]);
		if (checker) {
			ret = checker_execute_instructions(checker);
			checker_destructor(checker);
		} else {
			ret = 1;
		}
	}
	return ret;
}
