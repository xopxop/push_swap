/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing-service-helper.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:06:28 by dthan             #+#    #+#             */
/*   Updated: 2023/04/03 05:41:32 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTING_SERVICE_HELPER_H
#define PRINTING_SERVICE_HELPER_H
#include "printing-service.h"

void print_row(t_printing_row_info_service info);
void reset_printing_service(t_printing_service *printing_service);
void init_printing_service(t_printing_service *service, t_data *data, char *instruction, t_execution_info *exec_info, t_config *config);

#endif
