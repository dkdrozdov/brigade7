#include <stdio.h>                      
#include <conio.h>
#include <windows.h>

const USHORT Nmax = 5;

void Invert(float* A, float C[Nmax], USHORT N)
{
   for (USHORT i = 0; i < N / 2; i++)
   {
      float temp = A[i];
      A[i] = A[N - i - 1];
      A[N - i - 1] = temp;
   }
}

int main()
{
   UINT inCp = GetConsoleCP(), outCp = GetConsoleOutputCP();
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251);

   USHORT N = 0;
   float A[Nmax] = { };

   printf_s("Введите размер массива: ");
   scanf_s("%hu", &N);

   for (USHORT i = 0; i < N; i++)
   {
      printf_s("Введите %d элемент массива: ", i);
      scanf_s("%f", &A[i]);
   }

   Invert(A, A, N);

   for (USHORT i = 0; i < N; i++)
      printf_s("%f ", A[i]);

   SetConsoleCP(inCp);
   SetConsoleOutputCP(outCp);

   return 0 * _getch();
}