#include <stdio.h>
#include <conio.h>
#include <windows.h>

USHORT const nmax = 100;

int main()
{
   UINT inCp = GetConsoleCP(), outCp = GetConsoleOutputCP();
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251);
   USHORT N = 0;
   float A = 0, D = 0, S[nmax];

   printf_s("Введите размер массива, первый член и знаменатель геометрической прогрессии: ");
   scanf_s("%hu %f %f", &N, &A, &D);

   S[0] = A;
   printf_s("%4.2f ", S[0]);
   for (int i = 1; i < N; i++) {
      S[i] = S[i - 1] * D;
      printf_s("%4.2f ", S[i]);
   }

   SetConsoleCP(inCp);
   SetConsoleOutputCP(outCp);

   return 0 * _getch();
}  