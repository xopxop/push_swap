int main(t_stack *stack_a, t_stack *stack_b) {
  while (!stack_is_ascending(stack_a) && !stack_is_empty(stack_b)) {
    if (can_rotate(stack_a) && !can_rotate(stack_b)) {
      //rr
    } else if (can_rotate(stack_a)) {
      //ra
    } else if (!can_rotate(stack_b)) {
      //rb
    } else if (can_reverse_rotate(stack_a) && !can_reverse_rotate(stack_b)) {
      //rrr
    } else if (can_reverse_rotate(stack_a)) {
      //rra
    } else if (!can_reverse_rotate(stack_b)) {
      ///rrb
    } else if (can_swap(stack_a) && (!can_swap(stack_b))) {
      //ss
    } else if (can_swap(stack_a)) {
      //sa
    } else if (!can_swap(stack_b)) {
      //sb
    } else if (stack_is_ascending(stack_a)){
      //pa
    } else {
      //pb
    }
  }
}

int can_swap(t_stack *stack) {
  if (stack->count < 2) {
    return 0;
  }
  return stack->first_node->data > stack->first_node->next->data;
}

int can_rotate(t_stack *stack) {
  if (stack->count < 3) {
    return 0;
  }
  int first_value = stack->first_node->data;
  int second_value = stack->first_node->next->data;
  int last_value = stack->last_node->data;
  return first_value > second_value < last_value;
}

int can_reverse_rotate(t_stack *stack) {
  if (stack->count < 3) {
    return 0;
  }
  int first_value = stack->first_node->data;
  int second_value = stack->first_node->next->data;
  int last_value = stack->last_node->data;
  return first_value < second_value < last_value;
}

int can_push_back(t_stack *stack_a, t_stack *stack_b) {
  return stack_is_ascending(stack_a) && stack_is_descending(stack_b);
}
