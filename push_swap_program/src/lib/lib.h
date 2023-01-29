/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:25:10 by dthan             #+#    #+#             */
/*   Updated: 2023/01/29 15:18:17 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../objs/push_swap/push_swap.h"
#include "../../../libft/includes/libft.h"
#include "../../../shared-lib/helper.h"

int can_swap(t_stack *stack, int order);
int can_rotate(t_stack *stack, int order);
int	can_reverse_rotate(t_stack *stack, int order);
unsigned int move_node_to_top(t_data *data, t_stack *stack, t_node *node);
unsigned int algo_max_3(t_push_swap *program);
unsigned int algo_min_4(t_push_swap *program);
unsigned int algo_min_10(t_push_swap *program);
