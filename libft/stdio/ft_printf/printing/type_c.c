/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 04:33:24 by dthan             #+#    #+#             */
/*   Updated: 2020/05/21 21:40:00 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

void	type_c(t_info *info, va_list arg, size_t *ct, int fd)
{
	char	chr;
	char	*str;
	int		null;
	int		null_position;

	null_position = 0;
	chr = va_arg(arg, int);
	str = ft_strnew(1);
	if (chr == '\0')
		null = 1;
	else
		null = 0;
	str[0] = chr + null;
	width_ctrl(info, &str);
	*ct = ft_strlen(str);
	if (null)
	{
		while (str[null_position] != chr + null)
			null_position++;
		str[null_position] = 0;
	}
	write(fd, str, *ct);
	free(str);
}
