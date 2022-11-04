#ifndef CHECKER
#define CHECKER
#include "stack.h"
#define FOREACH_OPERATION(OPERATION) \
	OPERATION(sa) \
	OPERATION(sb) \
	OPERATION(ss) \
	OPERATION(pa) \
	OPERATION(pb) \
	OPERATION(ra) \
	OPERATION(rb) \
	OPERATION(rr) \
	OPERATION(rra) \
	OPERATION(rrb) \
	OPERATION(rrr)

#define GENERATE_ENUM(ENUM) ENUM,
#define GENERATE_STRING(STRING) #STRING,

enum OPERATION_ENUM {
	FOREACH_OPERATION(GENERATE_ENUM)
};

static const char *OPEARTION_STRING[] = {
	FOREACH_OPERATION(GENERATE_STRING)
};

enum OPERATION_ENUM {
	sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr
};

static const char *OPEARTION_STRING[] = {
	"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"
};

typedef struct s_checker {
	t_stack *stack_a;
	t_stack *stack_b;
	char **instructions;
}	t_checker;

t_checker *new_checker(int **numbers);
t_checker *checker_constructor(t_checker *program, int **numbers);
void *checker_destructor(t_checker *program);
int checker_execute_instructions(t_checker *program);
void checker_execute_instruction(t_checker *program, char *command);

#endif