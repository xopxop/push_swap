#include "stack.h"
#include <stdarg.h>

t_stack *new_stack(int n, ...) {
  t_stack *stack = (t_stack*)malloc(sizeof(t_stack));
  va_list	argv;

  if (argc > 0) {
    va_start(argc);
    stack_constructor_complex
  } else {
    stack_constructor_simple(stack);
  }
  return stack;
}

t_stack *stack_constructor_simple(t_stack *stack) {
  stack->first_node = NULL;
  stack->last_node = NULL;
  stack->count = 0;
}

t_stack *stack_constructor_complex(t_stack, int argc, int argv[]) {
  
}

// need to do this later
void stack_destructor();

void stack_add(t_stack* stack, t_node *node) {
  stack->last_node->next = node;
  stack->last_node = node;
  stack->count++;
}



t_node *stack_pop_top(t_stack *stack) {
  t_node *node = stack->first_node;

  stack->first_node = stack->first_node->next;
  stack->count--;
  node->next = NULL;
  return node;
}

void stack_push_top(t_stack *stack, t_node *node) {
  node->next = stack->first_node;
  stack->first_node = node;
  stack->count++;
}

void stack_swap(t_stack *stack) {
  
}
void stack_rotate(t_stack *stack);
void stack_reverse_rotate(t_stack *stack);

bool is_empty(t_stack *stack) {
  return !!stack->count;
}

// need to have condition more than 1
bool is_sorted(t_stack *stack) {
  t_node *node_a = stack->first_node;
  t_node *node_b = stack->first_node->next;

  while (node_b->next != NULL) {
    if (node_a->data > node_b->data) {
      return false;
    }
    node_a = node_a->next;
    node_b = node_b->next;
  }
  return true;
}
