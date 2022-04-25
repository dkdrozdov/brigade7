#pragma once
#include "tree.h"
#include "stack.h"

tree::tree(char _elem, tree *_left, tree *_right) : elem(_elem), left(_left), right(_right) {}

tree *tree::input()
{
   tree *t = this;
   stack<tree*> *s = new stack<tree*>();
   FILE *fp;

   fopen_s(&fp, "input.txt", "r");
   if (!fp) return NULL;

   for (char c = fgetc(fp); c != EOF; c = fgetc(fp))
   {
      switch (c)
      {
      case '(':
         t->left = new tree(fgetc(fp));
         s->push(t);
         t = t->left;
         break;
      case ',':
         t->right = new tree(fgetc(fp));
         s->push(t);
         t = t->right;
         break;
      case ')':
         s->pop(&t);
         break;
      default:
         t->elem = c;
         break;
      }
   }

   fclose(fp);

   return t;
}

