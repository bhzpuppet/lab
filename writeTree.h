#ifndef _WRITETREE_H_
#define _WRITETREE_H_
#include "treestructure.h"
#include "stdio.h"
#include "stdlib.h"
void writeTree( Node *head );
void writeNode( FILE *fp, Node *node );
void printOut( FILE *fp, Node *node );

#endif
