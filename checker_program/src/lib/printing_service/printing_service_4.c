/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_service_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:34:27 by dthan             #+#    #+#             */
/*   Updated: 2023/04/05 15:35:13 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../libft/includes/libft.h"
#include "printing_service.h"
#define AC_YELLOW "\x1b[33m"
#define AC_NORMAL "\x1b[m"

void	print_row(t_printing_row_info_service info)
{
	if (info.a || info.b)
	{
		if (info.a && info.color_info.color_a)
			ft_printf("%s%*d%s ",
				AC_YELLOW, info.max_cols_a, *info.a, AC_NORMAL);
		else if (info.a)
			ft_printf("%*d ", info.max_cols_a, *info.a);
		else
			ft_printf("%*s ", info.max_cols_a, "");
		if (info.b && info.color_info.color_b)
			ft_printf("%s%*d%s\n",
				AC_YELLOW, info.max_cols_b, *info.b, AC_NORMAL);
		else if (info.b)
			ft_printf("%*d\n", info.max_cols_b, *info.b);
		else
			ft_putendl("");
	}
	else
	{
		// need to improve this
		ft_printf("%.*s %.*s\n", info.max_cols_a,
			"--------------", info.max_cols_b, "--------------");
		ft_printf("%-*c %-*c\n", info.max_cols_a, 'a', info.max_cols_b, 'b');
	}
}
