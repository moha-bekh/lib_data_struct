#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <stdbool.h>
#include <stdlib.h>

typedef struct s_graph_node {
  int value;
} t_gnode;

typedef struct s_graph {
  bool is_oriented;
} t_graph;

#endif // !_GRAPH_H_
