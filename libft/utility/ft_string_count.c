/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 13:36:33 by dthan             #+#    #+#             */
/*   Updated: 2020/03/26 13:37:24 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_string_count(char **input)
{
	int	ct;

	ct = 0;
	while (*input)
	{
		ct++;
		input++;
	}
	return (ct);
}