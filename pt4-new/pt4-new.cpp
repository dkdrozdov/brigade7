// В файле WORK содержатся результаты работы цеха за день.
// Элемент файла включает: шифр изделия(8 - символьный код), наименование изделия, количество(штук).
// Построить таблицу, содержащую результаты работы за день, считая ключом шифр изделия.
// Элемент таблицы имеет ту же структуру, что и элемент файла.
// Содержащаяся в таблице информация с равными ключами должна быть помещена в таблицу один раз с общим количеством штук изделия.
// Организовать таблицу как упорядоченную.

#include <stdio.h>
#include <windows.h>

const UCHAR Emax = 100, Kmax = 9, Nmax = 15;

struct field
{
   UINT quantity = 0;
   char key[Kmax]{ }, name[Nmax]{ };
};

struct table
{
   UINT size = 0;
   field elem[Emax]{ };

   bool empty()
   {
      return size == 0;
   }

   int binary_search(field f)
   {
      UINT l = 0, r = size, m = 0;
      for (; l < r; m = (l + r) / 2)
         if (strcmp(f.key, elem[m].key) > 0)
            l = m + 1;
         else
            r = m;
      return l;
   }

   void shift(int pos)
   {
      size++;
      for (int i = size - 1; i >= pos; i--)
         elem[i + 1] = elem[i];
   }
   
   void insert(field f)
   {
      if (size > Emax)
      {
         printf_s("Таблица полна.");
         return;
      }
      int pos = binary_search(f);
      if (strcmp(f.key, elem[pos].key) == 0)
         elem[pos].quantity += f.quantity;
      else
      {
         shift(pos);
         elem[pos] = f;
      }
   }
   
   int find(field f)
   {
      if (empty()) printf_s("Таблица пуста.");
      int pos = binary_search(f);
      if (strcmp(f.key, elem[pos].key) != 0)
      {
         printf_s("Элемента нет в таблице. ");
         return -1;
      }
      printf_s("Индекс элемента: %u ", pos);
      return pos;
   }
   
   void input()
   {
      FILE *fp = NULL;
      fopen_s(&fp, "WORK.txt", "r");
      if (!fp)
      {
         printf_s("Файл WORK.txt не найден.");
         return;
      } else
      {
         field f;
         for (; fscanf_s(fp, "%s", f.key, _countof(f.key)) != EOF
              && size < Emax; insert(f))
            fscanf_s(fp, "%s %u", f.name, _countof(f.name), &f.quantity);
         fclose(fp);
      }
   }

   void output()
   {
      FILE *fp = NULL;
      fopen_s(&fp, "output.txt", "w");
      if (!fp)
      {
         printf_s("Не удалось открыть файл output.txt.");
         return;
      } else
      {
         if (empty()) printf_s("Таблица пуста.");
         else
            for (UCHAR i = 0; i < size; i++)
               fprintf_s(fp, "%9s %15s %10u \n", elem[i].key, elem[i].name, elem[i].quantity);
         fclose(fp);
      }
   }
};

int main()
{
   table t;

   t.input();
   t.output();

   return 0;
}
