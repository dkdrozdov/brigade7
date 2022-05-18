#ifndef LIST_H
#define LIST_H

#include "tree.h"

struct list
{
   tree *elem;
   list *next;

   list(tree *_elem, list *_next);
};

#endif