/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:28:47 by dthan             #+#    #+#             */
/*   Updated: 2023/01/27 19:09:07 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack/stack.h"
#include <stdlib.h>

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}   t_data;

t_data	*new_data(char **argv);
t_data	*data_destructor(t_data *data);