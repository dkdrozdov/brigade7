// Написать операции работы с заданной структурой данных, включив в один модуль. 
// К основным операциям добавить операцию, показывающую содержимое структуры после выполнения какого-либо действия с ней. 
// Эту операцию реализовать на основе базовых операций:
// Основные операции над динамической очередью.
//    Вид очереди - линейный односвязный циклический список двумя указателями.
// Операции:
//    Очистить очередь
//    Поместить элемент в очередь
//    Взять элемент из очереди
//    Проверка очереди на пустоту

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
      if (empty()) return false;   // Очередь пуста

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

   printf_s("\nВыберите команду: \n");
   printf_s("%c - Вывести очередь\n", PRINT);
   printf_s("%c - Очистить очередь\n", CLEAR);
   printf_s("%c - Добавить элемент в очередь\n", PUSH);
   printf_s("%c - Вытолкнуть элемент из очереди\n", POP);
   printf_s("%c - Проверить, пуста ли очередь\n", EMPTY);
   printf_s("%c - Завершить работу\n", EXIT);

   queue *q = new queue;
   bool repeat = true;
   do
   {
      char cmd = 0, elem = 0;

      printf_s("Действие: ");
      scanf_s("\n%c", &cmd, 1);

      switch (cmd)
      {
      case PRINT:
         printf_s("Содержимое очереди:\n");
         q->print();
         break;
      case CLEAR:
         printf_s("Очередь очищена.\n");
         q->clear();
         break;
      case PUSH:
         printf_s("Введите элемент: ");
         scanf_s("\n%c", &elem, 1);
         q->push(elem);
         break;
      case POP:
         q->pop(&elem) ? printf_s("Полученный элемент: %c\n", elem) :
            printf_s("Не удалось получить элемент: очередь пуста.\n");
         break;
      case EMPTY:
         q->empty() ? printf_s("Очередь пуста.\n") :
            printf_s("Очередь не пуста.\n");
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