#include "node.h"
#include <stdlib.h>

t_node *new_node(char *data) {
  t_node *node = (t_node*)malloc(sizeof(t_node));
  node_constructor(node, data);
  return node;
}

int node_constructor(t_node* node, char *data) {
  node->data = atoi(data);
  node->next = NULL;
  node->prev = NULL;
  return 1;
}

t_node *node_destructor(t_node *node) {
  free(node);
  return NULL;
}