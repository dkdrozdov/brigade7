#ifndef PRODUCT_H
#define PRODUCT_H

#include <windows.h>

const USHORT KEY_SIZE = 9, NAME_SIZE = 10;

struct product
{
   char key[KEY_SIZE] = { },
      name[NAME_SIZE] = { };

   UINT amount = 0;
};

#endif


