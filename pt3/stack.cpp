#pragma once
#include "stack.h"
#include <stdio.h>


stack::stack(list *_beg = NULL) : beg(_beg) {};

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