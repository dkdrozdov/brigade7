/*Array4◦.
Дано целое число N (> 1), а также первый член A и знаменатель D геометрической прогрессии.
Сформировать и вывести массив размера N, содержащий N первых членов данной прогрессии.
A, A*D, A*D^2, A*D^3 . . .
*/
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
   LONG64 A = 0, D = 0, S[nmax];

   printf_s("Введите размер массива, первый член и знаменатель геометрической прогрессии: ");
   scanf_s("%hu %lld %lld", &N, &A, &D);

   S[0] = A;
   printf_s("%lld ", S[0]);
   for (int i = 1; i < N; i++) {
      S[i] = S[i - 1] * D;
      printf_s("%lld ", S[i]);
   }

   SetConsoleCP(inCp);
   SetConsoleOutputCP(outCp);

   return 0 * _getch();
}  