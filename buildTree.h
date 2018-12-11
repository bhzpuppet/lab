#ifndef _BUILDTREE_H_
#define _BUILDTREE_H_
#include "treestructure.h"

Node *makeNode( double x, double y, int level );
void makeChildren( Node *parent );
void growtree( Node *head);
void destroyTree(Node *head);
void removeChildren( Node *parent );
#endif
