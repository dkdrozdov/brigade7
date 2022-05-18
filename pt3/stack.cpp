#include <stdio.h>
#include "stack.h"
#include "tree.h"

stack::stack(list *_beg) : beg(_beg) {};

void stack::push(tree *elem)
{
   beg = new list(elem, beg);
}

bool stack::pop(tree &elem)
{
   return true;
}

tree *stack::top()
{
   return NULL;
}