/*
9.	� �������� ������ ������� ��� ����� ������, ����������� � ������ (������ �� ��������).
18.	��� �����. ������� ���������� ���������� ������ ������ �������� � ���.
27.	��������� �� ������ ������ ��������, ������������� ����� ��������� �\*�, �*\� ������� �������.��������������, ��� ��� ��������� ������.
*/
#include<iostream>
#include <conio.h>

int main()
{
	setlocale(LC_ALL, "");
	int length = 256;
	char *s = (char*)malloc(length * sizeof(char));
	gets_s(s, length);
	int len = strlen(s);
	char *parenthesis1 = strchr(s, '(');
	char *parenthesis2 = strchr(s, ')');
	if (parenthesis1 && parenthesis2 && parenthesis1 < parenthesis2) //mozno li?
	{
		char *s1 = (char*)malloc(length * sizeof(char));
		int n;
		for (int i = 0; i < len; i++)
		{		
			if (s[i] == ')')
			{
				n = i;
				break;
			}
		}
		strncat_s(s1,sizeof(s1) , s, n);
		strcat_s(s1, sizeof(s1), parenthesis2);
		puts(s1);
	}


}