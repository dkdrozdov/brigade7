#ifndef TABLE_H
#define TABLE_H

#include <windows.h>
#include "product.h"

const UINT TABLE_CAP = 10;

struct table
{
   UINT size = 0;
   product *data[TABLE_CAP] = { };

   bool index_at(char key[KEY_SIZE], UINT *i);
   bool insert(product *elem);
   void shift(UINT i, UINT o);
   bool full();
};

#endif



