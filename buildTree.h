#ifndef _BUILDTREE_H_
#define _BUILDTREE_H_
#include "treestructure.h"

Node *makeNode( double x, double y, int level );
void makeChildren( Node *parent );
void growtree( Node *head);
void destroyTree(Node *head);
void removeChildren( Node *parent );
double nodeValue( Node *node, double time );
double value( double x, double y, double time );
void change (Node *head);
void calculate (Node *head);
void add_remove (Node *head); 
void adapt( Node *head ) 
#endif
