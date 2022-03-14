#include <stdio.h>

const char separator = ' ';
const char endChar = '.';
char target = NULL;

struct list
{
   char elem;
   list *next;

   list(char _elem = NULL, list *_next = NULL) : elem(_elem), next(_next) {}

   list *getStringEnd()      			//Возвращает конец строки.
   {
      if (!this) return NULL;
      list *c = this;
      for (; c->next && c->next->elem != separator && c->next->elem != endChar; c = c->next);
      return c;
   }

   void print()              			//Печатает список в консоль.
   {
      for (list *c = this; c; c = c->next)
         printf("%c", c->elem);
   }

   list *findElem(char t)    			//Возвращает указатель на первое вхождение элемента t.
   {
      list *c = this;
      for (; c && c->elem != t; c = c->next);
      return c;
   }

   list *findPrev(list *h)   			//Возвращает предыдущий элемент. 
   {                         			//h - первый элемент в списке.
      list *c = h;
      if (h == this) return NULL;
      for (; c && c->next != this; c = c->next)
         return c;
   }

   //Вставляет последовательность элементов от данного до sEnd после t.
   //prev - предыдущий элемент.
   void moveSequenceTo(list *sEnd, list *t, list *prev)
   {
      if (this == sEnd)
      {
         if (prev) prev->next = next;
         next = t->next;
         t->next = this;
      }
      else
      {
         if (prev && sEnd->next) prev->next = sEnd->next;
         sEnd->next = t->next;
         t->next = this;
      }
   }

   list *getSequenceEnd()             //Возвращает конец последовательности одинаковых элементов.
   {
      if (!this) return NULL;
      list *c = this;
      for (; c->next && c->next->elem == elem; c = c->next);
      return c;
   }

   list *moveToStringEnd(char t)      //Перемещает все элементы t в конец строк, в которых находятся.
   {
      if (!next) return this;
      list *h = new list(NULL, this), *first = h, *seqHead = this->findElem(t),
         *seqEnd = seqHead->getSequenceEnd(), *strEnd = seqEnd->getStringEnd();
      for (; seqHead;)
      {
         if (seqEnd != strEnd)
            seqHead->moveSequenceTo(seqEnd, strEnd, seqHead->findPrev(first));
         else
            first = strEnd->next;
         seqHead = first->findElem(t);
         seqEnd = seqHead->getSequenceEnd();
         strEnd = seqEnd->getStringEnd();
      }
      first = h->next;
      delete h;
      return first;
   }
};

list *readFile()                      //Возвращает указатель на новый список, составленный по содержимому файла.
{
   list *p = NULL;
   list *current = NULL;
   FILE *fp;

   fopen_s(&fp, "test.txt", "r");
   if (fp == 0)
      return NULL;

   target = fgetc(fp);
   fgetc(fp);

   for (char c = fgetc(fp); c != EOF; c = fgetc(fp))
   {
      if (!current)
      {
         p = new list();
         current = p;
      }
      else
      {
         current->next = new list();
         current = current->next;
      }
      current->elem = c;
   }
   fclose(fp);

   return p;
}

int main()
{
   readFile()->moveToStringEnd(target)->print();
   return 0;
}