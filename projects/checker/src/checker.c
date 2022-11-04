#include "checker.h"

t_checker *new_checker(int **numbers) {
	t_checker *checker = (t_checker*)malloc(sizeof(t_checker));
  checker_constructor(checker, numbers);
}

t_checker *checker_constructor(t_checker *program, int **numbers) {
  program->stack_a = new_stack(1, numbers);
  program->stack_b = new_stack(0);
  // get instructions here
  program->instructions;
}

void *checker_destructor(t_checker *program) {
  // free stack a
  // free stack b
  // free instructions
}

int checker_execute_instructions(t_checker *program) {
	int i = 0;
	while (program->instructions[i]) {
		execute_instruction(program, program->instructions[i]);
		i++;
	}
  if (is_empty(program->stack_b) && is_sorted(program->stack_a)) {
    ft_fprintf(stdout, "OK\n");
    return stdout;
  } else {
    ft_fprintf(stderr, "KO\n");
    return stderr;
  }
}

void checker_execute_instruction(t_checker *program, char *command) {
	if (strcmp(command, OPEARTION_STRING[sa])) {
		stack_swap(program->stack_a);
	} else if (strcmp(command, OPEARTION_STRING[sb])) {
		stack_swap(program->stack_b);
	} else if (strcmp(command, OPEARTION_STRING[ss])) {
		stack_swap(program->stack_a);
		stack_swap(program->stack_b);
	} else if (strcmp(command, OPEARTION_STRING[pa])) {
		stack_push_top(program->stack_a, stack_pop_top(program->stack_b));
	} else if (strcmp(command, OPEARTION_STRING[pb])) {
		stack_push_top(program->stack_b, stack_pop_top(program->stack_a));
	} else if (strcmp(command, OPEARTION_STRING[ra])) {
		stack_rotate(program->stack_a);
	} else if (strcmp(command, OPEARTION_STRING[rb])) {
		stack_rotate(program->stack_b);
	} else if (strcmp(command, OPEARTION_STRING[rr])) {
		stack_rotate(program->stack_a);
		stack_rotate(program->stack_b);
	} else if (strcmp(command, OPEARTION_STRING[rra])) {
		stack_reverse_rotate(program->stack_a);
	} else if (strcmp(command, OPEARTION_STRING[rrb])) {
		stack_reverse_rotate(program->stack_b);
	} else if (strcmp(command, OPEARTION_STRING[rrr])) {
		stack_reverse_rotate(program->stack_a);
		stack_reverse_rotate(program->stack_b);
	}
}
