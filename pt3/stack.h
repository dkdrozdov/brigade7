#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include "list.h"

struct stack
{
   list *beg;

   stack(list *_beg = NULL);
   void push(tree *elem);
   bool pop(tree **elem);
   bool empty();
   tree *peek();
};

#endif