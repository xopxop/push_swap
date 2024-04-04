/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_service_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:04:37 by dthan             #+#    #+#             */
/*   Updated: 2023/04/05 18:01:02 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <unistd.h>
#include "printing_service.h"
#include "../../../../libft/includes/libft.h"
#include "printing_service_helper.h"
#include "../../objs/checker/checker.h"

void	print_separator(void)
{
	struct winsize	w;
	int				index;

	index = 0;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	while (index < w.ws_col)
	{
		write(STDOUT_FILENO, "-", 1);
		index++;
	}
}

void	print_instruction(char *instruction)
{
	if (instruction)
		ft_printf("Exec %s:\n", instruction);
	else
		write(STDOUT_FILENO, "Init a and b:\n", 14);
}

void	display_stacks(
			t_checker *checker,
			int instruction_index,
			t_execution_info *exec_info)
{
	t_printing_service	service;

	init_printing_service(&service, checker, instruction_index, exec_info);
	print_separator();
	print_instruction(service.instruction_ptr);
	while (service.rows > 0)
	{
		reset_printing_service(&service);
		print_row(service.print_row_info_service);
		service.rows--;
	}
	service.print_row_info_service.a = NULL;
	service.print_row_info_service.b = NULL;
	print_row(service.print_row_info_service);
}
