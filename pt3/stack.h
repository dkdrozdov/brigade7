#ifndef STACK_H
#define STACK_H

#include "list.h"

struct stack
{
   list *beg;

   stack(list *_beg);
   void push(tree *elem);
   bool pop(tree &elem);
   tree *top();
};

#endif