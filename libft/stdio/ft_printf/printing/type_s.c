/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 04:34:28 by dthan             #+#    #+#             */
/*   Updated: 2020/05/21 21:40:00 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

void	type_s(t_info *info, va_list arg, size_t *ct, int fd)
{
	char	*ctemp;
	char	*str;

	ctemp = va_arg(arg, char *);
	if (!ctemp)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(ctemp);
	prec_ctrl_str(info, &str);
	width_ctrl(info, &str);
	write(fd, str, *ct = ft_strlen(str));
	free(str);
}
