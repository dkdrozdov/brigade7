// В заданном бинарном дереве найти длину (число ветвей) 
// пути от корня до ближайшей вершины со значением равным заданному
// а) прямой обход
// б) рекурсивный обход
#include <stdio.h>
#include "tree.h"

bool input(tree *t, char *target)
{
   FILE *fp;
   fopen_s(&fp, "input.txt", "r");
   if (!fp) return false;

   *target = fgetc(fp);
   fgetc(fp);
   t->input(fp);

   return true;
}

bool output(int l)
{
   FILE *fp;
   fopen_s(&fp, "input.txt", "w");
   if (!fp) return false;

   if (l == -1)
      fprintf_s(fp, "Заданный элемент не найден.");
   else
      fprintf_s(fp, "%d", l);

   return true;

}

int main()
{
   tree *t = new tree();
   char c;
   if (!input(t, &c)) return 1;
   output(t->pathlen(c));

   return 0;
}