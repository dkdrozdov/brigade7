#include <stdio.h>
#include "tree.h"
#include "stack.h"

tree::tree(char _elem, tree *_left, tree *_right) : elem(_elem), left(_left), right(_right) {}
tree::tree() : elem('0'), left(NULL), right(NULL) {}
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