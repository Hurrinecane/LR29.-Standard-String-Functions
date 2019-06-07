/*
9.	В заданном тексте удалить все части текста, заключенные в скобки (вместе со скобками).
18.	Дан текст. Найдите наибольшее количество подряд идущих пробелов в нем.
27.	Исключить из строки группы символов, расположенные между символами «\*», «*\» включая границы.Предполагается, что нет вложенных скобок.
*/
#include<iostream>
#include <conio.h>

const int length = 256;
char *s = (char*)malloc(length * sizeof(char));
char *parenthesis1 = NULL;
char *parenthesis2 = NULL;

void first()
{
	do
	{
		parenthesis1 = strchr(s, '(');
		parenthesis2 = strchr(s, ')');

		if (parenthesis1 == 0 || parenthesis2 == 0)
			break;

		if (*parenthesis2 > *parenthesis1)
			parenthesis2 = strchr(&parenthesis2[1], ')');

		int len = strlen(s);
		if (parenthesis1 && parenthesis2 && parenthesis1 < parenthesis2) //mozno li?
		{
			char *s1 = (char*)calloc(length, sizeof(char));
			int n;
			for (int i = 0; i < len; i++)
			{
				if (s[i] == '(')
				{
					n = i;
					break;
				}
			}
			strncat_s(s1, length, s, n);
			strcat_s(s1, length, parenthesis2 + 1);
			strcpy_s(s, length, s1);
			free(s1);
		}

		puts(s);

	} while (true);
	_getch();
}

void second()
{
	int quantity = 0, max = 0;
	int len = strlen(s);

	for (int i = 0; i < len; i++)
	{
		bool space = false;

		if (isspace(s[i]))
			space = true;

		if (space)
		{
			quantity++;
		}
		else
		{
			if (quantity > max) max = quantity;
			quantity = 0;
		}

	}

	printf_s("Max quantity: %d\n", max);
	_getch();
}

void third()
{
	char *s1 = (char*)calloc(length, sizeof(char));
	char *slash1 = NULL, *slash2 = NULL;

	//do
	//{
	//	slash1 = strchr(s, '\\');
	//
	//	while (slash1 != NULL && slash1[1] != '*')
	//	{
	//		if (slash1[1] != '*')
	//			slash1 = strchr(&slash1[1], '\\');
	//	}
	//	if (slash1 == NULL) break;
	//
	//	slash2 = strchr(&slash1[1], '\\');
	//	if (slash2 == NULL || slash2[-1] != '*' || &slash2[-1] == &slash1[1]) break;
	//
	//	int len = strlen(s), n = 0;
	//
	//	for (int i = 0; i < len; i++)
	//	{
	//		if (&s[i] == slash1)
	//		{
	//			n = i;
	//			break;
	//		}
	//	}
	//
	//	if (n)	strncat_s(s1, len, s, n);
	//	strcat_s(s1, length, slash2 + 1);
	//	strcpy_s(s, length, s1);
	//	free(s1);
	//	puts(s);
	//} while (slash1 != NULL && slash2 != NULL);

	do
	{
		slash1 = strchr(s, '\\');
		while (slash1 != NULL && slash1[1] != '*')
		{
			if (slash1[1] != '*')
				slash1 = strchr(&slash1[1], '\\');
		}
		if (slash1==NULL)
			break;

		slash2 = strchr(&slash1[1], '\\');
		while (slash2 != NULL && slash2[-1] != '*')
		{
			if (slash2[-1] != '*')
				slash2 = strchr(&slash2[1], '\\');
		}
		if (slash2==NULL)
			break;

		int len = strlen(s), n = 0;
		for (int i = 0; i < len; i++)
		{
			if (&s[i] == slash1)
			{
				n = i;
				break;
			}
		}
		if (n)	strncat_s(s1, len, s, n);
		strcat_s(s1, length, slash2 + 1);
		strcpy_s(s, length, s1);
		free(s1);
		puts(s);

	} while (slash1 != NULL && slash2 != NULL);


	_getch();
}

int main()
{
	setlocale(LC_ALL, "");

	gets_s(s, length);

	third();

	first();

	second();

}