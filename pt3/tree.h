#pragma once
#include <stdio.h>

struct tree
{
   char elem;
   tree *left;
   tree *right;

   tree *input();
   tree(char _elem = 0, tree *_left = NULL, tree *_right = NULL);
};