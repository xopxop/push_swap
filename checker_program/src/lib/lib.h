/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:59:20 by dthan             #+#    #+#             */
/*   Updated: 2023/03/29 18:23:38 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_LIB_H
#define CHECKER_LIB_H
#include "../../../shared-objs/config/config.h"
#include "../../../shared-objs/data/data.h"
#include "./printing-service/printing-service.h"

void display_stacks(t_config *config, t_data *data, char *instruction, t_execution_info *exec_info);

#endif
