#ifndef CHECKER
#define CHECKER
#include "../stack/stack.h"
#define CONSTRUCTOR_SUCCESS 1
#define CONSTRUCTOR_FAILED 0
#define CHECKER_VALIDATOR_PASSED 1
#define CHECKER_VALIDATOR_FAILED 0

typedef struct s_checker {
	t_stack *stack_a;
	t_stack *stack_b;
	char **instructions;
}	t_checker;

t_checker *new_checker(int argc, char **argv);
int checker_constructor(t_checker *program, int argc, char **argv);
t_checker *checker_destructor(t_checker *program);
int checker_execute_instructions(t_checker *program);
void checker_execute_instruction(t_checker *program, char *command);
void print_stack(t_stack *stack);
void print_instructions(char **instructions);
#endif