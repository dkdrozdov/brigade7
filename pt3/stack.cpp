#pragma once
#include "stack.h"
#include <stdio.h>

template<typename T>
list<T>::list(T _elem, list<T> *_next): elem(_elem), next(_next) {}

template<typename T>
stack<T>::stack(list<T> *_beg, list<T> *_end) : beg(_beg), end(_end) {}

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
      } else
      {
         beg = new list<T>(elem, beg);
      }
   }

   template<typename T>
   bool stack<T>::pop(T *elem)
   {
      if (empty()) return false;   // Стек пуст

      *elem = beg->elem;
      list<T> *d = beg;
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
