/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data-printing-helper.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:08:03 by dthan             #+#    #+#             */
/*   Updated: 2023/03/25 20:32:17 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_PRINTING_HELPER_H
# define DATA_PRINTING_HELPER_H
#include "data.h"
#include "data-printer.h"

void	print_separator();
void	print_instruction(char *instruction);
void	print_data(t_printer printer);

#endif
