/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 04:43:51 by dthan             #+#    #+#             */
/*   Updated: 2020/05/21 21:40:00 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

void	type_di(t_info *info, va_list arg, size_t *ct, int fd)
{
	long long	num;
	char		*str;
	int			negative;

	negative = 0;
	num = get_signed_argument(info, arg);
	if (num < 0)
		negative = 1;
	str = ft_itoa_signed_longlong(num);
	flag_ignore(info, str);
	prec_ctrl_nums(info, &str, negative);
	flag_control(info, &str, negative);
	width_ctrl(info, &str);
	write(fd, str, *ct = ft_strlen(str));
	free(str);
}
