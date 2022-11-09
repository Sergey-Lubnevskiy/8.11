#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <tchar.h>

using namespace std;

void space(_TCHAR* a)
{
	for (int i = 0; i < _tcslen(a); i++)
	{
		if (a[i] == ' ')
		{
			a[i] = '\t';
		}
	}
}

void Print(_TCHAR* a)
{
	for (int i = 0; i < _tcslen(a); i++)
	{
		wcout << a[i];
	}
	wcout << endl;
}

void simvolCount(_TCHAR* a)
{
	int s = 0, n = 0, c = 0;
	for (int i = 0; i < _tcslen(a); i++)
	{
		if ((int)a[i] >= 48 && (int)a[i] <= 57)
			n++;
		else if ((int)a[i] >= 65 && (int)a[i] <= 90 || (int)a[i] >= 97 && (int)a[i] <= 122)
			c++;
		else if ((int)a[i] >= 1040 && (int)a[i] <= 1103)
			c++;
		else
			s++;
	}
	cout << endl << "simvol: " << s;
	cout << endl << "nomer: " << n;
	cout << endl << "char: " << c;
}

void Cword(_TCHAR* a)
{
	int word = 0;
	for (int i = 0; i < _tcslen(a); i++)
	{
		if ((int)a[i] == ' ' || (int)a[i] == '\t' || (int)a[i] == '\n')
		{
			word++;
			while (true)
			{
				if ((int)a[i + 1] == ' ' || (int)a[i + 1] == '\t' || (int)a[i + 1] == '\n')
					i++;
				else
					break;
			}
		}
	}
	word++;
	cout << "\nWords: " << word;
}

void Mir(_TCHAR* a)
{
	_TCHAR buf[100];
	_tcscpy(buf, a);
	bool mir = false;
	int i = 0, k = _tcslen(a) - 1;
	while (true)
	{
		if (i > k)
			break;
		if (a[i] == buf[k])
			mir = true;
		else
		{
			mir = false;
			break;
		}
		i++;
		k--;
	}
	cout << endl << "mirror: " << mir;
}

void PosDel(_TCHAR* a, int pos)
{
	_TCHAR buf[100];
	int i, k;
	pos--;
	for (i = k = 0; i < _tcslen(a); i++)
		if (pos != i)
			buf[k++] = a[i];
	buf[k] = '\0';
	_tcscpy(a, buf);
}

void PutChar(_TCHAR* a, int pos, char ch)
{
	_TCHAR buf[100];
	int i, k;
	pos--;
	for (i = k = 0; i < _tcslen(a); i++)
	{
		if (pos == i)
		{
			if (ch >= 0)
			{
				if ((int)a[i] == (int)ch)
					buf[k++] = ch;
			}
			else
			{
				if ((int)a[i] == (int)ch + 789)
					buf[k++] = ch + 789;
			}
		}
		else
			buf[k++] = a[i];
	}
	buf[k++] = '\0';
	_tcscpy(a, buf);
}

void charDel(_TCHAR* a, const char ch)
{
	_TCHAR buf[100];
	int i, k;
	for (i = k = 0; i < _tcslen(a); i++)
	{
		if (ch >= 0)
		{
			if ((int)a[i] != (int)ch)
				buf[k++] = a[i];
		}
		else
		{
			if ((int)a[i] != (int)ch + 789)
				buf[k++] = a[i];
		}
	}
	buf[k] = '\0';
	_tcscpy(a, buf);
}



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	_TCHAR arr[100] = _TEXT("buf");
	Print(arr);
	space(arr);
	Print(arr);
	simvolCount(arr);
	Cword(arr);
	Mir(arr);
	PosDel(arr, 12);
	cout << endl;
	Print(arr);
	charDel(arr, 'o');
	Print(arr);
	PutChar(arr, 9, 'o');
	Print(arr);
}