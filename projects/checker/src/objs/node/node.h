#ifndef NODE_H
#define NODE_H
#include <unistd.h>

typedef struct s_node
{
  int data;
  struct s_node *next;
  struct s_node *prev;
} t_node;

t_node *new_node(char *data);
int node_constructor(t_node* node, char *data);
t_node *node_destructor(t_node *node);

#endif