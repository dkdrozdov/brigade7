#include <stdio.h>
#include <locale.h>                            
#include <conio.h>
#include <iostream>
#include <windows.h>

int main()
{
   UINT inCp = GetConsoleCP(), outCp = GetConsoleOutputCP();
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251);
   setlocale(LC_ALL, "");

   USHORT N = 0;
   printf_s("Введите число N: ");
   scanf_s("%hu", &N);


   char S[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   for (int i = 0; i < N; i++) {
      printf_s("%c ", S[i]);
   }

   SetConsoleCP(inCp);
   SetConsoleOutputCP(outCp);

   return 0 * _getch();
}
