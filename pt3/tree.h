#ifndef TREE_H
#define TREE_H

struct tree
{
   char elem;
   tree *left;
   tree *right;

   tree(char _elem, tree *_left, tree *_right);
   tree();
   bool input();
};

#endif