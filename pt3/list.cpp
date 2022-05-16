#include <stdio.h>
#include "list.h"

list::list(tree *_elem = NULL, list *_next = NULL) :
   elem(_elem), next(_next){}

