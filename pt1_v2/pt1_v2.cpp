#include <stdio.h>

const char separator = ' ';
const char endChar = '.';
char target = NULL;

struct list
{
   char elem;
   list *next;

   list(char _elem = NULL, list *_next = NULL) : elem(_elem), next(_next) {}

   list *getStringEnd()      			// Поиск конца строки
   {
      if (!this) return NULL;
      list *c = this;
      for (; c->next && c->next->elem != separator && c->next->elem != endChar; c = c->next);
      return c;
   }

   list *findElem(char s)    			// Поиск первого вхождения элемента s
   {
      list *c = this;
      for (; c && c->elem != s; c = c->next);
      return c;
   }

   list *findPrev(list *h)   			// Поиск предыдущего элемента
   {                         			// h - первый элемент в списке
      list *c = h;
      if (h == this) return NULL;
      for (; c && c->next != this; c = c->next);
      return c;
   }

   void moveSequenceTo(list *sEnd, list *t, list *prev)
   {                                // Перемещение последовательности элементов
      if (this == sEnd)             // от данного до sEnd на место после t
      {                             // prev - предыдущий элемент
         if (prev) prev->next = next;
         next = t->next;
         t->next = this;
      } else
      {
         if (prev && sEnd->next) prev->next = sEnd->next;
         sEnd->next = t->next;
         t->next = this;
      }
   }

   list *getSequenceEnd()           // Поиск конца последовательности одинаковых элементов
   {
      if (!this) return NULL;
      list *c = this;
      for (; c->next && c->next->elem == elem; c = c->next);
      return c;
   }

   list *moveToStringEnd(char t)    // Перемещение всех элементов t в конец строк, 
   {                                // в которых они находятся
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

   void output()
   {
      FILE *fp;

      fopen_s(&fp, "output.txt", "w");
      if (!fp) return;

      for (list *c = this; c; c = c->next)
         fputc(c->elem, fp);
      fclose(fp);
   }
};

list *input()
{
   list *p = NULL, *current = NULL;
   FILE *fp;

   fopen_s(&fp, "input.txt", "r");
   if (!fp) return NULL;

   target = fgetc(fp);
   fgetc(fp);
   for (char c = fgetc(fp); c != EOF; c = fgetc(fp))
   {
      if (!current)
      {
         p = new list();
         current = p;
      } else
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
   input()->moveToStringEnd(target)->output();
   return 0;
}