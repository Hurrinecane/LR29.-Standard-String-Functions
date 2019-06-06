/*
9.	В заданном тексте удалить все части текста, заключенные в скобки (вместе со скобками).
18.	Дан текст. Найдите наибольшее количество подряд идущих пробелов в нем.
27.	Исключить из строки группы символов, расположенные между символами «\*», «*\» включая границы.Предполагается, что нет вложенных скобок.
*/
#include<iostream>
#include <conio.h>

int main()
{
	setlocale(LC_ALL, "");
	int length = 256;
	char *s = (char*)malloc(length * sizeof(char));
	gets_s(s, length);
	char *parenthesis1 = 0;
	char *parenthesis2 = 0;
#pragma region 1


	do
	{

		int len = strlen(s);
		parenthesis1 = strchr(s, '(');
		parenthesis2 = strchr(s, ')');
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
			len = strlen(s1);
			strcat_s(s1, length, parenthesis2 + 1);
			strcpy_s(s, length, s1);
		}
	} while (parenthesis1 != 0 && parenthesis2 != 0);
	puts(s);
	system("pause");

#pragma endregion


}