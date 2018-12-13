#include "buildTree.h"
#include "writeTree.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "treestructure.h"

Node *head;
void test1_1();
void test1_2();
void test2_1();
void test2_2();
void test3_1();
void test3_2();
// main
int main( int argc, char **argv ) {

  // make the head node
	head = makeNode( 0.0,0.0, 0 );

  // make a tree
	test1_1();
  
  // print the tree for Gnuplot
	writeTree( head );
	
  // destroy the tree and free memory
	destroyTree(head);

	return 0;
}
void test1_1(){
	// a full tree at Level 2
	growtree(head);
	growtree(head);
}
void test1_2(){
	// a non-uniform tree that you define.
	growtree(head);
	makeChildren(head->child[2]);
}
void test2_1(){
	// a non-uniform tree that you define.
	test1_1();
	// Remove children from one Level 1 node using your new function.
	removeChildren(head->child[1]);
}
void test2_2(){
	// a non-uniform tree that you define. 
	test1_2();
	makeChildren(head->child[0]);
	// Use  removeChildren() to remove children from one Level 1 node.
	removeChildren(head->child[2]);
}
void test3_1(){
	// a full tree at Level 3
	growtree(head);
	growtree(head);
	growtree(head);
	// Making a data-dependent Quadtree 
	change(head);
}
void test3_2(){
	// a full tree at Level 3
	growtree (head);
	growtree (head);
	growtree (head);
	// running the Task 3 algorithm until the tree does not change
	adapt(head);
} 

