/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:25:14 by dthan             #+#    #+#             */
/*   Updated: 2022/11/23 18:25:14 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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