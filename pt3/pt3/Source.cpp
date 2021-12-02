/*Array4◦.
Дано целое число N (> 1), а также первый член A и знаменатель D геометрической прогрессии.
Сформировать и вывести массив размера N, содержащий N первых членов данной прогрессии.
A, A*D, A*D^2, A*D^3 . . .
*/
#include <stdio.h>
#include <locale.h>                            
#include <conio.h>
#include <iostream>
#include <windows.h>

int main()
{
   setlocale(LC_ALL, "");
   USHORT const N_MAX = 100;
   USHORT N = 0;
   LONG64 A = 0, D = 0, S[N_MAX];
   bool isInputCorrect = false;
   
   while (!isInputCorrect){
      printf_s("Введите размер массива, первый член и знаменатель геометрической прогрессии: ");
      scanf_s("%hu %lld %lld", &N, &A, &D);
      if (N > N_MAX)
         printf_s("Введённый размер массива слишком большой!\n");
      else
         isInputCorrect = true;
   }

   S[0] = A;
   printf_s("%lld ", S[0]);
   for (int i = 1; i < N; i++) {
      S[i] = S[i-1] * D;
      printf_s("%lld ", S[i]);
   }

   return 0 * _getch();
}  