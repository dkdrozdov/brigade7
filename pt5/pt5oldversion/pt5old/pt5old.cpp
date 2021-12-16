/*
Param4.
Описать процедуру Invert(A,N), меняющую порядок следования элементов вещественного массива A размера N на противоположный (инвертирование массива).
Массив A является входным и выходным параметром.
С помощью этой процедуры инвертировать массивы A, B, C размера NA, NB, NC соответственно.
*/

#include <stdio.h>                      
#include <conio.h>
#include <windows.h>
#include <limits.h>

void Invert(float *A, USHORT N)
{
   for (int i = 0; i < N / 2; i++)
   {
      float temp = A[i];
      A[i] = A[N - i];
      A[N - i] = temp;
   }
}

int main()
{
   UINT inCp = GetConsoleCP(), outCp = GetConsoleOutputCP();
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251);

   USHORT N = 0;
   float A[UCHAR_MAX] = { };

   printf_s("Введите размер массива: ");
   scanf_s("%hu", &N);

   for (int i = 0; i < N; i++)
   {
      printf_s("Введите %d элемент массива: ", i);
      scanf_s("%f", &A[i]);
   }

   Invert(A, N);

   for (int i = 0; i < N; i++)
      printf_s("%f ", A[i]);

   SetConsoleCP(inCp);
   SetConsoleOutputCP(outCp);

   return 0 * _getch();
}