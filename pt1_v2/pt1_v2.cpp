#include <stdio.h>

const char separator = ' ';
const char endChar = '.';
char target = NULL;

struct list {
   char elem;
   list* next;

   list(char _elem = NULL, list* _next = NULL) : elem(_elem), next(_next) {}

   list* getStringEnd() {
      list* c = this;
      while (c->next != NULL && c->next->elem != separator && c->next->elem != endChar)
         c = c->next;
      return c;
   }

   void print() {
      list* c = this;
      while (c != NULL) {
         printf("%c", c->elem);
         c = c->next;
      }
   }

   list* findElem(char t) {
      list* c = this;
      while (c != NULL && c->elem != t) c = c->next;
      return c;
   }

   list* findPrev(list* h) {
      list* c = h;
      if (h == this) return NULL;
      while (c != NULL && c->next != this) c = c->next;
      return c;
   }

   void moveTo(list* t, list* prev) {
      if (prev != NULL) prev->next = next;
      next = t->next;
      t->next = this;
   }

   void moveSequenceTo(list* sEnd, list* t, list* prev) {
      if (this == sEnd) this->moveTo(t, prev);
      else {
         if (prev != NULL && sEnd->next != NULL) prev->next = sEnd->next;
         sEnd->next = t->next;
         t->next = this;
      }
   }

    list* getSequenceEnd() {
       if (this == NULL) return NULL;
       list* c = this;
       while (c->next != NULL && c->next->elem == elem) c = c->next;
       return c;
    }

    bool isInSequence(list* sHead) {
       if (this == NULL) return NULL;
       list* c = sHead;
       while (c->next != NULL && c->next->elem == elem && c != this) c = c->next;
       return c == this ? true : false;
    }

    list* getSequenceHead(list* h) {
       if (this == NULL) return NULL;
       list* sHead = h->findElem(this->elem);
       list* c = sHead;
       while (sHead != NULL) {
         while (c != NULL && c != this && sHead != this) {
            c = c->next;
         }
         if (c == this) return sHead;
         sHead = c->findElem(this->elem);
       }
       return NULL;
    }

    list* moveToStringEnd(char t){
        if (next == NULL) return this;
        list* h = new list(NULL, this);
        list* first = h;
        list* sHead = this->findElem(t);
        list* sEnd = sHead->getSequenceEnd();
        list* lastHead = sHead->getStringEnd();
        if (lastHead != NULL && lastHead->elem == t) {
           lastHead = lastHead->getSequenceHead(first);
        }

        while (sHead != NULL) {
            if(lastHead != sHead && lastHead != sEnd){
                lastHead = sHead->getStringEnd();
                sHead->moveSequenceTo(sEnd, lastHead, sHead->findPrev(h));
                if(lastHead != NULL && lastHead->elem != t) lastHead = sHead;
                sHead = first->next->findElem(t);
            }
            else {
                first = sHead->getStringEnd()->next;
                sHead = first->findElem(t);
                sEnd = sHead->getSequenceEnd();
            }
        }
        first = h->next;
        delete h;
        return first;
    }
};

list* readFile() {
    list *p = NULL;
    list *current = NULL;
    FILE *fp;

    fopen_s(&fp, "test.txt", "r");
    if (fp == 0)
        return NULL;

    target = fgetc(fp);
    fgetc(fp);

    char c = fgetc(fp);

    while (c != EOF) {
        if (current == NULL)
        {
            p = new list();
            current = p;
        }
        else {
            current->next = new list();
            current = current->next;
        }
        current->elem = c;

        c = fgetc(fp);
    }
    fclose(fp);

    return p;
}



int main() {
    readFile()->moveToStringEnd(target)->print();
    return 0;
}