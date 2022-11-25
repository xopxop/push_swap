/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:25:10 by dthan             #+#    #+#             */
/*   Updated: 2022/11/23 18:45:32 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

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