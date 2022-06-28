// � ����� WORK ���������� ���������� ������ ���� �� ����.
// ������� ����� ��������: ���� �������(8 - ���������� ���), ������������ �������, ����������(����).
// ��������� �������, ���������� ���������� ������ �� ����, ������ ������ ���� �������.
// ������� ������� ����� �� �� ���������, ��� � ������� �����.
// ������������ � ������� ���������� � ������� ������� ������ ���� �������� � ������� ���� ��� � ����� ����������� ���� �������.
// ������������ ������� ��� �������������.

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
         printf_s("������� �����.");
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
      if (empty()) printf_s("������� �����.");
      int pos = binary_search(f);
      if (strcmp(f.key, elem[pos].key) != 0)
      {
         printf_s("�������� ��� � �������. ");
         return -1;
      }
      printf_s("������ ��������: %u ", pos);
      return pos;
   }
   
   void input()
   {
      FILE *fp = NULL;
      fopen_s(&fp, "WORK.txt", "r");
      if (!fp)
      {
         printf_s("���� WORK.txt �� ������.");
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
         printf_s("�� ������� ������� ���� output.txt.");
         return;
      } else
      {
         if (empty()) printf_s("������� �����.");
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
