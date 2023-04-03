/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker-helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:42:47 by dthan             #+#    #+#             */
/*   Updated: 2023/04/03 06:40:15 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "../../../../libft/includes/libft.h"

static int	is_valid_instruction(char *instruction)
{
	const char	*valid_instructions[] = {
		"sa", "sb", "ss", "pa", "pb", "ra", \
		"rb", "rr", "rra", "rrb", "rrr", NULL
	};
	int			i;

	i = 0;
	while (valid_instructions[i])
	{
		if (!ft_strcmp(instruction, valid_instructions[i]))
			return (1);			
		i++;
	}
	ft_printf("%s\n", instruction);
	return (0);
}

char	**get_instructions(void)
{
	char	*instruction;
	char	**instructions;

	instructions = NULL;
	while (get_next_line(STDIN_FILENO, &instruction))
	{
		if (is_valid_instruction(instruction))
			instructions = ft_array_calloc(instructions, instruction);
		else
		{
			ft_dprintf(STDERR_FILENO, "Error\n");
			if (instructions)
				ft_arraydel(instructions);
			return (NULL);
		}
	}
	return (instructions);
}
