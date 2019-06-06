/*
9.	В заданном тексте удалить все части текста, заключенные в скобки (вместе со скобками).
18.	Дан текст. Найдите наибольшее количество подряд идущих пробелов в нем.
27.	Исключить из строки группы символов, расположенные между символами «\*», «*\» включая границы.Предполагается, что нет вложенных скобок.
*/
#include<iostream>
#include <conio.h>

int length = 256;
char *s = (char*)malloc(length * sizeof(char));
char *parenthesis1 = NULL;
char *parenthesis2 = NULL;

void nine()
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
		}

		puts(s);

	} while (true);


	_getch();
}

int main()
{
	setlocale(LC_ALL, "");

	gets_s(s, length);

	nine();

#pragma region 2

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

#pragma endregion


}