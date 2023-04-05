/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:35:21 by dthan             #+#    #+#             */
/*   Updated: 2023/04/05 00:10:27 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

typedef struct s_config
{
	int	colour_the_last_operation;
	int	display_stacks;
	int	read_and_write_from_file;
}	t_config;

t_config	*new_config_object(char ***argv);
void		delete_config_object(t_config *obj);

#endif
