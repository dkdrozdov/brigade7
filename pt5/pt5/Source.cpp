/*
Param4. 
������� ��������� Invert(A,N), �������� ������� ���������� ��������� ������������� ������� A ������� N �� ��������������� (�������������� �������). 
������ A �������� ������� � �������� ����������.
� ������� ���� ��������� ������������� ������� A, B, C ������� NA, NB, NC ��������������.
*/

#include <stdio.h>                      
#include <conio.h>
#include <windows.h>

const USHORT Nmax = 100;

void Invert(float* A, USHORT N)
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
   float A[nmax] = {};

   printf_s("������� ������ �������: ");
   scanf_s("%hu", &N);

   for (int i = 0; i < N; i++)
   {
      printf_s("������� %d ������� �������: ", i);
      scanf_s("%f", &A[i]);
   }

   Invert(A, N);

   for (int i = 0; i < N; i++)
   {
      printf_s("%4.2f ", A[i]);
   }

   SetConsoleCP(inCp);
   SetConsoleOutputCP(outCp);

   return 0 * _getch();
}