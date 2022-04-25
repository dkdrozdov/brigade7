#pragma once
#include "tree.h"

template<typename T>
struct list
{
   T elem;
   list<T> *next;

   list(T _elem = 0, list *_next = NULL);
};

template<typename T>
struct stack
{
   list<T> *beg;
   list<T> *end;

   stack(list<T> *_beg = NULL, list<T> *_end = NULL);

   bool empty();
   void clear();
   void push(T elem);
   bool pop(T *elem);
   void print();
};