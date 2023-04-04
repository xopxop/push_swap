/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing-service-1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:04:37 by dthan             #+#    #+#             */
/*   Updated: 2023/04/04 21:49:45 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <unistd.h>
#include "printing-service.h"
#include "../../../../libft/includes/libft.h"
#include "printing-service-helper.h"

void print_separator()
{
	struct winsize w;
	int index;

	index = 0;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	while (index < w.ws_col)
	{
		write(STDOUT_FILENO, "-", 1);
		index++;
	}
}

void print_instruction(char *instruction)
{
	if (instruction)
		ft_printf("Exec %s:\n", instruction);
	else
		write(STDOUT_FILENO, "Init a and b:\n", 14);
}

void display_stacks(t_config *config, t_data *data, char *instruction, t_execution_info *exec_info)
{
	t_printing_service service;

	init_printing_service(&service, data, instruction, exec_info, config);
	print_separator();
	print_instruction(instruction);
	while (service.rows > 0)
	{
		reset_printing_service(&service);
		print_row(service.print_row_info_service);
		service.rows--;
	}
	service.print_row_info_service.a = NULL;
	service.print_row_info_service.a = NULL;
	print_row(service.print_row_info_service);
}
