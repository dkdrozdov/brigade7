#include <stdio.h>
#include "tree.h"

bool input(tree *t, char *tar)
{
   FILE *fp;
   fopen_s(&fp, "input.txt", "r");
   if (!fp) return false;

   *tar = fgetc(fp);
   fgetc(fp);
   t->input(fp);

   return true;
}

bool output(int l)
{
   FILE *fp;
   fopen_s(&fp, "output.txt", "w");
   if (!fp) return false;

   fprintf_s(fp, (l==-1) ? "Заданный элемент не найден." : "%d", l);

   return true;

}

int main()
{
   tree *t = new tree();
   char c;
   if (!input(t, &c)) return 1;
   output(t->pathlen_r(c));

   return 0;
}