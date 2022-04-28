// В заданном бинарном дереве найти длину (число ветвей) пути от корня до ближайшей вершины со значением равным заданному
// а) прямой обход
// б) рекурсивный обход

#include <stdio.h>
//#include "tree.h"

// STACK.H
template<typename T>
struct list
{
   T elem;
   list<T>* next;

   list(T _elem = 0, list* _next = NULL);
};

template<typename T>
struct stack
{
   list<T>* beg;
   list<T>* end;

   stack(list<T>* _beg = NULL, list<T>* _end = NULL);

   bool empty();
   void clear();
   void push(T elem);
   bool pop(T* elem);
   void print();
};
// STACK.H

// TREE.H
struct tree
{
   char elem;
   tree* left;
   tree* right;

   tree* input();
   tree(char _elem = 0, tree* _left = NULL, tree* _right = NULL);
};
// TREE.H


// STACK.CPP
template<typename T>
list<T>::list(T _elem, list<T>* _next) : elem(_elem), next(_next) {}

template<typename T>
stack<T>::stack(list<T>* _beg, list<T>* _end) : beg(_beg), end(_end) {}

template<typename T>
bool stack<T>::empty()
{
   return !beg;
}

template<typename T>
void stack<T>::clear()
{
   for (T elem; pop(&elem); );
}

template<typename T>
void stack<T>::push(T elem)
{
   if (empty())
   {
      end = new list<T>(elem);
      beg = end;
   }
   else
   {
      beg = new list<T>(elem, beg);
   }
}

template<typename T>
bool stack<T>::pop(T* elem)
{
   if (empty()) return false;   // Стек пуст

   *elem = beg->elem;
   list<T>* d = beg;
   beg = beg->next;
   delete d;

   return true;
}

template<typename T>
void stack<T>::print()
{
   stack q;
   T i = 0;
   for (; pop(&i); q.push(i))
      printf_s("%c ", i);
   for (; q.pop(&i); push(i));
   printf_s("\n");
}
// STACK.CPP

// TREE.CPP
tree::tree(char _elem, tree* _left, tree* _right) : elem(_elem), left(_left), right(_right) {}

tree* tree::input()
{
   tree* t = this;
   stack<tree*>* s = new stack<tree*>();
   FILE* fp;

   fopen_s(&fp, "input.txt", "r");
   if (!fp) return NULL;

   for (char c = fgetc(fp); c != EOF; c = fgetc(fp))
   {
      switch (c)
      {
      case '(':
         c = fgetc(fp);
         s->push(t);
         if (c == '0') break;
         t->left = new tree(c);
         t = t->left;
         break;
      case ',':
         c = fgetc(fp);
         if (c == '0') break;
         t->right = new tree(c);
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
// TREE.CPP

int main()
{
   tree *t = new tree();
   t->input();

   return 0;
}