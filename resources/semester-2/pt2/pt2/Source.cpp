// �������� �������� ������ � �������� ���������� ������, ������� � ���� ������. 
// � �������� ��������� �������� ��������, ������������ ���������� ��������� ����� ���������� ������-���� �������� � ���. 
// ��� �������� ����������� �� ������ ������� ��������:
// �������� �������� ��� ������������ ��������.
//    ��� ������� - �������� ����������� ����������� ������ ����� �����������.
// ��������:
//    �������� �������
//    ��������� ������� � �������
//    ����� ������� �� �������
//    �������� ������� �� �������

#include <stdio.h>
#include <windows.h>
#include <conio.h>

enum command { PRINT = '0', CLEAR, PUSH, POP, EMPTY, EXIT };

struct list
{
   char elem;
   list *next;

   list(char _elem = 0, list *_next = NULL) : elem(_elem), next(_next) {}
};

struct queue
{
   list *beg;
   list *end;

   queue(list *_beg = NULL, list *_end = NULL) : beg(_beg), end(_end) {}

   bool empty()
   {
      return !beg;
   }

   void clear()
   {
      for (char elem; pop(&elem); );
   }

   void push(char elem)
   {
      if (empty())
      {
         end = new list(elem);
         beg = end;
      } else
      {
         end->next = new list(elem);
         end = end->next;
      }
   }

   bool pop(char *elem)
   {
      if (empty()) return false;   // ������� �����

      *elem = beg->elem;
      list *d = beg;
      beg = beg->next;
      delete d;

      return true;
   }

   void print()
   {
      queue q;
      char i = 0;
      for (; pop(&i); q.push(i))
         printf_s("%c ", i);
      for (; q.pop(&i); push(i));
      printf_s("\n");
   }
};

int main()
{
   UINT inCp = GetConsoleCP(), outCp = GetConsoleOutputCP();
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251);

   printf_s("\n�������� �������: \n");
   printf_s("%c - ������� �������\n", PRINT);
   printf_s("%c - �������� �������\n", CLEAR);
   printf_s("%c - �������� ������� � �������\n", PUSH);
   printf_s("%c - ���������� ������� �� �������\n", POP);
   printf_s("%c - ���������, ����� �� �������\n", EMPTY);
   printf_s("%c - ��������� ������\n", EXIT);

   queue *q = new queue;
   bool repeat = true;
   do
   {
      char cmd = 0, elem = 0;

      printf_s("��������: ");
      scanf_s("\n%c", &cmd, 1);

      switch (cmd)
      {
      case PRINT:
         printf_s("���������� �������:\n");
         q->print();
         break;
      case CLEAR:
         printf_s("������� �������.\n");
         q->clear();
         break;
      case PUSH:
         printf_s("������� �������: ");
         scanf_s("\n%c", &elem, 1);
         q->push(elem);
         break;
      case POP:
         q->pop(&elem) ? printf_s("���������� �������: %c\n", elem) :
            printf_s("�� ������� �������� �������: ������� �����.\n");
         break;
      case EMPTY:
         q->empty() ? printf_s("������� �����.\n") :
            printf_s("������� �� �����.\n");
         break;
      case EXIT:
         repeat = false;
         break;
      default:
         break;
      }
   } while (repeat);

   SetConsoleCP(inCp);
   SetConsoleOutputCP(outCp);

   return 0;
}