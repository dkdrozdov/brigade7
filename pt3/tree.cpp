#include <stdio.h>
#include "tree.h"
#include "stack.h"

tree::tree(char _elem, tree *_left, tree *_right) : elem(_elem), left(_left), right(_right) {}
void tree::input(FILE *fp)
{
   tree *current = this;
   stack *s = new stack();

   elem = fgetc(fp);
   for (char c = fgetc(fp); c != EOF; c = fgetc(fp))
   {
      switch (c)
      {
      case '(':
         s->push(current);
         current = current->left = new tree(fgetc(fp));
         break;
      case ',':
         current = s->top();
         current = current->right = new tree(fgetc(fp));
         break;
      default:
         s->pop(&current);
         break;
      }
   }
};

int tree::pathlen(char elem)
{
   stack *s = new stack();
   tree *current = this;
   int len = 0;
   s->push(this);

   bool found = false;
   for (;!s->empty() && !found;)
   {
      s->pop(&current);
      if (current->elem == elem) 
         found = true;
      else
      {
         if (current->right) s->push(current->right);
         if (current->left) s->push(current->left);
      }
   }

   return len;
}

int tree::pathlen_r(char elem)
{
   return 0;
}