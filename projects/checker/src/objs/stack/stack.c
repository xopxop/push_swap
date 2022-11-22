/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:59:44 by dthan             #+#    #+#             */
/*   Updated: 2022/11/22 14:59:45 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#define CONSTRUCTOR_SUCCESS 1
#define CONSTRUCTOR_FAILED 0
#include <stdio.h>

t_stack *new_stack(int argc, char** argv) {
  t_stack *stack = (t_stack*)malloc(sizeof(t_stack));

  if (argc == 0 && !argv) {
    stack_constructor_simple(stack);
  } else {
    if (stack_constructor_complex(stack, argc, argv) == CONSTRUCTOR_FAILED) {
      return stack_destructor(stack);
    }
  }
  return stack;
}

int stack_constructor_simple(t_stack *stack) {
  stack->first_node = NULL;
  stack->last_node = NULL;
  stack->count = 0;
  return CONSTRUCTOR_SUCCESS;
}

int is_number(char *argv) {
  (void)argv;
  return 1;
}

int is_dup(char *argv) {
  (void)argv;
  return 0;
}

int stack_constructor_complex(t_stack *stack, int argc, char** argv) {
  int i = 0;
  while(i < argc) {
    if (is_number(argv[i]) && !is_dup(argv[i])) {
      t_node* node = new_node(argv[i]);
      stack_push(stack, node);
    } else {
      return CONSTRUCTOR_FAILED;
    }
    i++;
  }
  return CONSTRUCTOR_SUCCESS;
}

t_stack *stack_destructor(t_stack *stack) {
  t_node *node;

  if (stack->first_node) {
    while (stack->first_node) {
      node = stack->first_node;
      stack->first_node = stack->first_node->next;
      free(node);
    }
  }
  free(stack);
  return NULL;
}

// condition stack not empty
t_node *stack_pop(t_stack *stack) {
  t_node *node;

  if (stack->count == 1) {
    node = stack->first_node;
    stack->first_node = NULL;
  } else if (stack->count == 2) {
    node = stack->last_node;
    stack->first_node->next = NULL;
    stack->last_node = NULL;
    node->prev = NULL;
  } else {
    node = stack->last_node;
    stack->last_node = stack->last_node->prev;
    stack->last_node->next = NULL;
    node->prev = NULL;
  }
  stack->count--;
  return node;
}

// need condition stack is not empty
t_node *stack_pop_top(t_stack *stack) {
  t_node *node;

  node = stack->first_node;
  if (stack->count == 1) {
    stack->first_node = NULL;
  } else if (stack->count == 2) {
    stack->first_node = stack->last_node;
    stack->first_node->prev = NULL;
    stack->last_node = NULL;
    node->next = NULL;
  } else {
    stack->first_node = stack->first_node->next;
    stack->first_node->prev = NULL;
    node->next = NULL;
  }
  stack->count--;
  return node;
}

// no condition or max limit
void stack_push(t_stack* stack, t_node *node) {
  if (stack->count == 0) {
    stack->first_node = node;
  } else if (stack->count == 1) {
    stack->first_node->next = node;
    node->prev = stack->first_node;
    stack->last_node = node;
  } else {
    stack->last_node->next = node;
    node->prev = stack->last_node;
    stack->last_node = node;
  }
  stack->count++;
}

// condition if there is a max limit or no
void stack_push_top(t_stack *stack, t_node *node) {
  if (stack->count == 0) {
    stack->first_node = node;
  } else if (stack->count == 1) {
    stack->last_node = stack->first_node;
    stack->first_node = node;
    stack->first_node->next = stack->last_node;
    stack->last_node->prev = stack->first_node;
  } else {
    node->next = stack->first_node;
    stack->first_node->prev = node;
    stack->first_node = node;
  }
  stack->count++;
}

// condition stack-> count >= 2
void stack_swap(t_stack *stack) {
  t_node *first_node;
  t_node *second_node;
  
  first_node = stack->first_node;
  if (stack->count == 2) {
    second_node = stack->last_node;
    first_node->next = NULL;
    first_node->prev = second_node;
    second_node->prev = NULL;
    second_node->next = first_node;
    stack->first_node = second_node;
    stack->last_node = first_node;
  } else {
    second_node = first_node->next;
    first_node->next = second_node->next;
    first_node->prev = second_node;
    first_node->next->prev = first_node;
    second_node->prev = NULL;
    second_node->next = first_node;
    stack->first_node = second_node;
  }
}

// Do we need second_last? for the reverse rotate

bool is_empty(t_stack *stack) {
  return !stack->count;
}

// need to have condition more than 1
bool is_sorted(t_stack *stack) {
  t_node *node_a = stack->first_node;
  t_node *node_b;

  while (node_a != NULL && node_a->next != NULL) {
    node_b = node_a->next;
    if (node_a->data > node_b->data) {
      return false;
    }
    printf("A: %d - B: %d\n", node_a->data, node_b->data);
    node_a = node_a->next;
  }
  return true;
}
