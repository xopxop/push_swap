/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:24:55 by dthan             #+#    #+#             */
/*   Updated: 2022/11/27 19:15:19 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

t_checker *new_checker(int argc, char **argv) {
	t_checker *checker = (t_checker*)malloc(sizeof(t_checker));
  if (checker_constructor(checker, argc, argv) == CONSTRUCTOR_FAILED)
    return checker_destructor(checker);
  return checker;
}

char **get_instructions()
{
  char *instruction;
  char **instructions;
  char **ptr;
  int size;
  char *ptr2;

  size = 0;
  while(get_next_line(1, &instruction))
  {
    if (instruction && valid_instruction(instruction))
      ft_array_calloc(instructions, instruction);
    else
      break;
  }
  
  return (instructions);
}

int checker_constructor(t_checker *program, int argc, char **argv) {
  program->stack_a = new_stack(argc, argv);
  if (!program->stack_a)
    return CONSTRUCTOR_FAILED;
  program->stack_b = new_stack(0, NULL);
  program->instructions = get_instructions();
  if (!program->instructions)
    return CONSTRUCTOR_FAILED;
  return CONSTRUCTOR_SUCCESS;
}

t_checker *checker_destructor(t_checker *program) {
  int increment;

  if (program->stack_a)
    stack_destructor(program->stack_a);
  if (program->stack_b)
    stack_destructor(program->stack_b);
  if (program->instructions) {
    increment = 0;
    while (program->instructions[increment])
      free(program->instructions[increment++]);
    free(program->instructions);
  }
  return NULL;
}

int checker_execute_instructions(t_checker *program) {
	int i = 0;
  // print_instructions(program->instructions);
	while (program->instructions[i]) {
		checker_execute_instruction(program, program->instructions[i++]);
    printf("stack A: %d : ", program->stack_a->count);
    print_stack(program->stack_a);
    printf("\n");
    printf("stack B: %d : ", program->stack_b->count);
    print_stack(program->stack_b);
    printf("\n");
	}

  if (is_empty(program->stack_b) && is_sorted(program->stack_a)) {
    // need to change to stdout
    printf("OK\n");
    return CHECKER_VALIDATOR_PASSED;
  } else {
    // need to change to stderr
    printf("KO\n");
    return CHECKER_VALIDATOR_FAILED;
  }
}

void print_instructions(char **instructions) {
  while (*instructions) {
    printf("%s ", *instructions);
    (*instructions)++;
  }
}

void checker_execute_instruction(t_checker *program, char *command) {
  printf("%s\n", command);
	if (!strcmp(command, "sa") && program->stack_a->count > 1) {
		stack_swap(program->stack_a);
    return;
	} else if (!strcmp(command, "sb") && program->stack_b->count > 1) {
		stack_swap(program->stack_b);
    return;
	} else if (!strcmp(command, "ss") && program->stack_a->count > 1 && program->stack_b->count > 1) {
		stack_swap(program->stack_a);
		stack_swap(program->stack_b);
    return;
	} else if (!strcmp(command, "pa") && program->stack_b->count > 0) {
		stack_push_top(program->stack_a, stack_pop_top(program->stack_b));
    return;
	} else if (!strcmp(command, "pb") && program->stack_a->count > 0) {
		stack_push_top(program->stack_b, stack_pop_top(program->stack_a));
    return;
	} else if (!strcmp(command, "ra") && program->stack_a->count > 1) {
    stack_push(program->stack_a, stack_pop_top(program->stack_a));
    return;
	} else if (!strcmp(command, "rb") && program->stack_b->count > 1) {
    stack_push(program->stack_b, stack_pop_top(program->stack_b));
    return;
	} else if (!strcmp(command, "rr") && program->stack_a->count > 1 && program->stack_b->count > 1) {
    stack_push(program->stack_a, stack_pop_top(program->stack_a));
    stack_push(program->stack_b, stack_pop_top(program->stack_b));
    return;
	} else if (!strcmp(command, "rra") && program->stack_a->count > 1) {
    stack_push_top(program->stack_a, stack_pop(program->stack_a));
    return;
	} else if (!strcmp(command, "rrb") && program->stack_b->count > 1) {
    stack_push_top(program->stack_b, stack_pop(program->stack_b));
    return;
  } else if (!strcmp(command, "rrr") && program->stack_a->count > 1 && program->stack_b->count > 1) {
    stack_push_top(program->stack_a, stack_pop(program->stack_a));
    stack_push_top(program->stack_b, stack_pop(program->stack_b));
    return;
	}
}

void print_stack(t_stack *stack) {
  t_node *node = stack->first_node;
  while (node) {
    printf("%d ->", node->data);
    node = node->next;
  }
  printf("NULL");
}