#include "buildTree.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "treestructure.h"

// make a node at given location (x,y) and level

Node *makeNode( double x, double y, int level ) {

  int i;

  Node *node = (Node *)malloc(sizeof(Node));

  node->level = level;

  node->xy[0] = x;
  node->xy[1] = y;

  for( i=0;i<4;++i )
    node->child[i] = NULL;

  return node;
}

// split a leaf nodes into 4 children

void makeChildren( Node *parent ) {

  double x = parent->xy[0];
  double y = parent->xy[1];

  int level = parent->level;

  double hChild = pow(2.0,-(level+1));

  parent->child[0] = makeNode( x,y, level+1 );
  parent->child[1] = makeNode( x+hChild,y, level+1 );
  parent->child[2] = makeNode( x+hChild,y+hChild, level+1 );
  parent->child[3] = makeNode( x,y+hChild, level+1 );

  return;
}

//  visit every leaf node in the tree and add children.

void growtree( Node *head) {
	if (head->child[0] != NULL)
		growtree(head->child[0]);
	if (head->child[1] != NULL)
		growtree(head->child[1]);
	if (head->child[2] != NULL)
		growtree(head->child[2]);
	if (head->child[3] != NULL)
		growtree(head->child[3]);
	if (head->child[0] == NULL && head->child[1] == NULL && head->child[2] == NULL && head->child[3] == NULL)
		makeChildren(head);
}

// destroy tree

void destroyTree(Node *head) {
	int i;
	if (head != NULL){
		for( i=0;i<4;++i )
    		destroyTree(head->child[i]);
		free(head);
	}
}

// remove children

void removeChildren( Node *parent ){
	int i;
	for( i=0;i<4;++i )
    free(parent->child[i]);
	for( i=0;i<4;++i )
    parent->child[i] = NULL;
}
// Evaluate function at centre of quadtree node

double nodeValue( Node *node, double time ) {

  int level = node->level;
  double x = node->xy[0];
  double y = node->xy[1];

  double h = pow(2.0,-level);

  return( value( x+0.5*h, y+0.5*h, time ) );
}

// Data function

double value( double x, double y, double time ) {

  return( 2.0*exp(-8.0*(x-time)*(x-time)) - 1.0 ) ;
}

//change
int add_num = 0;
int remove_num = 0;
void change (Node *head){
	calculate(head);
	add_remove(head);
	printf("add:%d remove:%d\n",add_num,remove_num);
}

//give flag value

void calculate (Node *head){
	int i;
	if (head->child[0] == NULL){
		if (nodeValue(head,0.0) > 0.5)
			head->flag = 1;
		else if (nodeValue(head,0.0) < -0.5)
			head->flag = -1;
		}
	else { 
		head->flag = 0;
		for( i=0;i<4;++i )
		calculate(head->child[i]);
		}
}

// make change
void add_remove (Node *head) {
	int i;
	if (head->child[0] == NULL){
		if ( head->flag == 1){
			makeChildren(head);
			add_num = add_num + 4;
		}
	}
	else{
		if (head->child[0]->flag == -1 && head->child[1]->flag == -1 && head->child[2]->flag == -1 && head->child[3]->flag == -1){
			removeChildren(head);
			remove_num = remove_num + 4;
		}
		else {
			for( i=0;i<4;++i )
			add_remove(head->child[i]);
		}
	}
}
// auto change
void adapt( Node *head ) {
	calculate(head);
	add_remove_limit(head);
	printf("add:%d remove:%d\n",add_num,remove_num);
	while (1){
		if(add_num == 0 || remove_num == 0){
			break;
		}
		add_num = 0;
		remove_num = 0;
		calculate(head);
		add_remove_limit(head);
		printf("add:%d remove:%d\n",add_num,remove_num);
	}
}

void add_remove_limit( Node *head){
	int i;
	if (head->child[0] == NULL){
		if ( head->flag == 1 && head->level <6){
			makeChildren(head);
			add_num = add_num + 4;
		}
	}
	else{
		if (head->child[0]->flag == -1 && head->child[1]->flag == -1 && head->child[2]->flag == -1 && head->child[3]->flag == -1){
			removeChildren(head);
			remove_num = remove_num + 4;
		}
		else {
			for( i=0;i<4;++i )
			add_remove(head->child[i]);
		}
	}
}
