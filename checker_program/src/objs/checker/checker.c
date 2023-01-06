/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:24:55 by dthan             #+#    #+#             */
/*   Updated: 2022/11/28 11:30:40 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stddef.h>
#include "../../../../libft/includes/libft.h"
#define CONSTRUCTOR_SUCCESS 1
#define CONSTRUCTOR_FAILED 0

t_checker	*new_checker(int argc, char **argv)
{
	t_checker	*checker;

	checker = (t_checker *)malloc(sizeof(t_checker));
	if (checker_constructor(checker, argc, argv) == CONSTRUCTOR_FAILED)
		return (checker_destructor(checker));
	return (checker);
}

int	valid_instruction(char *instruction)
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
	return (0);
}

char	**get_instructions(void)
{
	char	*instruction;
	char	**instructions;

	instructions = NULL;
	while (get_next_line(1, &instruction))
	{
		if (valid_instruction(instruction))
			instructions = ft_array_calloc(instructions, instruction);
		else
		{
			ft_dprintf(1, "Error\n");
			if (instructions)
				ft_arraydel(instructions);
			return (NULL);
		}
	}
	return (instructions);
}

int	checker_constructor(t_checker *program, int argc, char **argv)
{
	program->stack_a = new_stack(argc, argv);
	if (!program->stack_a)
		return (CONSTRUCTOR_FAILED);
	program->stack_b = new_stack(0, NULL);
	program->instructions = get_instructions();
	if (!program->instructions)
		return (CONSTRUCTOR_FAILED);
	return (CONSTRUCTOR_SUCCESS);
}

t_checker	*checker_destructor(t_checker *program)
{
	int	increment;

	if (program->stack_a)
		stack_destructor(program->stack_a);
	if (program->stack_b)
		stack_destructor(program->stack_b);
	if (program->instructions)
	{
		increment = 0;
		while (program->instructions[increment])
			free(program->instructions[increment++]);
		free(program->instructions);
	}
	return (NULL);
}
