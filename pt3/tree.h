#ifndef TREE_H
#define TREE_H

#include "stack.h"

struct tree
{
   char elem;
   tree *left;
   tree *right;

   tree(char _elem, tree *_left, tree *_right);
   bool input();
};

#endif