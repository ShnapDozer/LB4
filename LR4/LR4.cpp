#include "pch.h"
#include <iostream>
#include <stdio.h>


using namespace System;
const int n = 5, m = 5;

void input(array<int, 2>^ a, Random^ rnd)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i, j] = rnd->Next() / 10000000 -
				100;
			Console::Write(L"{0,4}  ", a[i, j]);
		}
		Console::WriteLine();
	}
}

void printMatr(array<int, 2>^ a)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) { Console::Write(L"{0,4}  ", a[i, j]); }
		Console::WriteLine();
	}
}

void printMass(array<int>^ b, size_t k = m)
{
	for (int i = 0; i < k; i++) { Console::Write(L"{0,4}  ", b[i]); }
	Console::WriteLine();
}

void form(array<int, 2>^ MATR, array<int>^ MASS)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		MASS[i] = 0;

		for (int j = 0; j < m; j++) 
		{
			if (MATR[i, j] > 0)
			{
				MASS[i] += MATR[i, j];
			}
		}
	}
}

int main(array<System::String^>^ args)
{
	Random^ rnd = gcnew Random;

	array<int, 2>^ C = gcnew array<int, 2>(n, m);
	array<int, 2>^ D = gcnew array<int, 2>(n, m);

	array<int>^ X = gcnew array<int>(n * m);
	array<int>^ Y = gcnew array<int>(n * m);

	Console::WriteLine("Матрица C:");

	input(C, rnd);
	form(C, X);

	Console::WriteLine("Массив X:");
	printMass(X);

	Console::WriteLine();
	Console::WriteLine("Матрица D:");

	input(D, rnd);
	form(D, Y);

	Console::WriteLine("Массив Y:");
	printMass(Y);

	return 0;
}
