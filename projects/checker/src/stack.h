#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_node
{
  int data;
  t_node *next;
} t_node;

typedef struct s_stack {
  t_node *first_node;
  t_node *last_node;
  int count;
} t_stack;

t_stack *new_stack();
t_stack *stack_constructor(t_stack* stack);
void stack_destructor();
void stack_add(t_stack* stack, t_node *node);
t_node stack_pop(t_stack *stack);
void stack_swap(t_stack *stack);
void stack_rotate(t_stack *stack);
void stack_reverse_rotate(t_stack *stack);
bool is_empty(t_stack *stack);
bool is_sorted(t_stack *stack);

#endif