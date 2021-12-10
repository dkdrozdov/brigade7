/*
Param4. 
Описать процедуру Invert(A,N), меняющую порядок следования элементов вещественного массива A размера N на противоположный (инвертирование массива). 
Массив A является входным и выходным параметром.
С помощью этой процедуры инвертировать массивы A, B, C размера NA, NB, NC соответственно.
*/


#include <stdio.h>                      
#include <conio.h>
#include <windows.h>
const USHORT nmax = 500;

void Invert(float* A, int N) 
{
   float temp = 0;
   for (int i = 0, j = N - 1; i < N/2; i++, j--)
   {
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
   }
}

int main()
{
   UINT inCp = GetConsoleCP(), outCp = GetConsoleOutputCP();
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251);

   USHORT N = 0;
   float A[nmax];

   printf_s("Введите размер массива: ");
   scanf_s("%hu", &N);

   for (int i = 0; i < N; i++)
   {
      printf_s("Введите %d элемент массива: ", i);
      scanf_s("%f", &A[i]);
   }

   Invert(A, N);
   for (int i = 0; i < N; i++)
   {
      printf_s("%d: %4.2f", i, A[i]);
   }

   SetConsoleCP(inCp);
   SetConsoleOutputCP(outCp);

   return 0 * _getch();
}
