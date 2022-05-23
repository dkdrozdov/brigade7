#include <stdio.h>
#include "stack.h"
#include "tree.h"

stack::stack(list *_beg) : beg(_beg) {};

void stack::push(tree *elem)
{
   beg = new list(elem, beg);
}

bool stack::empty()
{
   return !beg;
}

bool stack::pop(tree **elem)
{
   bool is_empty = empty();
   if (!is_empty)
   {
      *elem = beg->elem;
      list *d = beg;
      beg = beg->next;

      delete d;
   }

   return is_empty;
}

tree *stack::peek()
{
   return beg->elem;
}