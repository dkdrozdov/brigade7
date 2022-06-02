#include <stdio.h>
#include "tree.h"
#include "stack.h"

tree::tree(char _elem, tree *_left, tree *_right) : elem(_elem), left(_left), right(_right) {}
void tree::input(FILE *fp)
{
   tree *t = this;
   stack *s = new stack();

   elem = fgetc(fp);
   for (char c = fgetc(fp); c != EOF; c = fgetc(fp))
   {
      switch (c)
      {
      case '(':
         s->push(t);
         t = t->left = new tree(fgetc(fp));
         break;
      case ',':
         t = s->top();
         t = t->right = new tree(fgetc(fp));
         break;
      default:
         s->pop(&t);
         break;
      }
   }
};

int tree::pathlen(char tar)
{
   stack *s = new stack();
   tree *t = this;
   int len = 0;
   s->push(this);

   for ( ; !s->empty() && t->elem != tar; )
   {
      if (t->left)
      {
         s->push(t);
         t = t->left;
         len++;
      }
      else
      {
         for ( ; !s->empty() && !(t == s->top()->left && s->top()->right); len--,
              s->pop(&t));
         if (!s->empty() && s->top()->right)
            t = s->top()->right;
      }
   }

   return t->elem == tar ? len : -1;
}

int tree::pathlen_r(char tar)
{
   if (elem == tar) return 0;

   if (left)
   {
      int l = left->pathlen_r(tar);
      if (l != -1)
         return l + 1;
   }

   if (right)
   {
      int r = right->pathlen_r(tar);
      if (r != -1)
         return r + 1;
   }

   return -1;
}