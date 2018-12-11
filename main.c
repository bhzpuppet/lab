#include "buildTree.h"
#include "writeTree.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "treestructure.h"
// main

int main( int argc, char **argv ) {

  Node *head;

  // make the head node
  head = makeNode( 0.0,0.0, 0 );

  // make a tree

  
  growtree (head);

  makeChildren(head->child[0]);
  	destroyTree(head);
  // print the tree for Gnuplot
	writeTree( head );


  return 0;
}

