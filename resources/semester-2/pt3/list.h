#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include "tree.h"

struct list
{
   tree *elem;
   list *next;

   list(tree *_elem = NULL, list *_next = NULL);
};

#endif