#pragma once
#include "tree.h"
#include <stdio.h>


tree::tree(char _elem = '0', tree *_left = NULL, tree *_right = NULL) : elem(_elem), left(_left), right(_right) {}

bool tree::input()
{
   tree *current = this;
   FILE *fp;

   fopen_s(&fp, "input.txt", "r");
   if (!fp) return false;

   elem = fgetc(fp);
   for (char c = fgetc(fp); c != EOF; c = fgetc(fp))
   {
      switch (c)
      {
      case '(':

         break;

      case ',':
         break;

      default:
         break;
      }
   }

   return true;
};