/*Array4◦.
Дано целое число N (> 1), а также первый член A и знаменатель D геометрической прогрессии.
Сформировать и вывести массив размера N, содержащий N первых членов данной прогрессии.
A, A*D, A*D^2, A*D^3 . . .
*/
#include <stdio.h>
#include <locale.h>
#include <cmath>
#include <iostream>

int main()
{
   setlocale(LC_ALL, "");
   unsigned N = 0;
   int A = 0;
   int D = 0;
   
   printf_s("Введите размер массива, первый член и знаменатель геометрической прогрессии: ");
   scanf_s ("%u %d %d", &N, &A, &D);

   for (int i = 0; i < N; i++) {
       printf_s("%d ", A * (int)pow(D, i));
   }

   return 0;
}  

