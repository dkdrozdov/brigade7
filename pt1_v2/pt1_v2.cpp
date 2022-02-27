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
        list *c = this;
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

    list* moveToStringEnd(char t){
        if (next == NULL) return this;
        list* h = new list(NULL, this);
        list* first = h;
        list* c = this->findElem(t);
        list* last = c->getStringEnd();

        while (c != NULL) {
            if(last != c){
                last = c->getStringEnd();
                c->moveTo(last, c->findPrev(h));
                if(last->elem != t) last = c;
                c = first->next->findElem(t);
            }
            else {
                first = c->getStringEnd()->next;
                c = first->findElem(t);
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