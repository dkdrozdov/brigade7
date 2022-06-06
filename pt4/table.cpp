#include <string.h>
#include "table.h"

bool table::index_at(char key[KEY_SIZE], UINT *i)
{
   UCHAR l = 0, r = size;

   for (; l < r; )
   {
      UCHAR m = (l + r) / 2;
      if (strcmp(data[m]->key, key) < 0)
         l = m + 1;
      else
         r = m;
   }

   return !strcmp(data[l]->key, key) ? *i = l : false;
}

bool table::insert(product *elem)
{
   if (full()) return false;

   UINT p;

   index_at(elem->key, &p);
   if (!strcmp(data[p]->key, elem->key))
      data[p]->amount += elem->amount;
   else
   {
      shift(p, 1);
      data[p] = elem;
   }

   return true;
}

void table::shift(UINT i, UINT o)
{
   if (o < 0)
      for (UINT j = i; j < size; j++)
         if(j-o>=0) data[j - o] = data[j];
   else 
      for (UINT j = size - 1; j < size; j--)
         data[j + 1] = data[j];
   size = size + o > TABLE_CAP ? TABLE_CAP :
      size + o < 0 ? 0 : size + o;
}

bool table::full()
{
   return size == TABLE_CAP;
}