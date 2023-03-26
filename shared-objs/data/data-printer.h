/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data-printer.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:09:41 by dthan             #+#    #+#             */
/*   Updated: 2023/03/25 20:30:41 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_PRINTER_H
# define DATA_PRINTER_H
# include "data.h"

typedef struct s_printer {
	int max_cols_a;
	int max_cols_b;
	int rows;
  t_data *data;
  char *instruction;
} t_printer;

t_printer *new_printer_object(t_data *data, char *instruction);
void delete_printer_object(t_printer *obj);
void printer_print(t_printer *printer);

#endif
