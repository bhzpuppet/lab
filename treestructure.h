#ifndef _TREESTRUCTURE_H_
#define _TREESTRUCTURE_H_
// tree data structure

struct qnode {
  int level,flag;
  double xy[2];
  struct qnode *child[4];

};
typedef struct qnode Node;

#endif
