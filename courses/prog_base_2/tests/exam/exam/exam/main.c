/*�������, �� ������ ������ � ��� ������ ���� ������� ��� �����, 
�� ������� ���� �����(����������� ���� - ��� ������� ��������� ������� �� ������ � �������).
������� ������� ���� ��� �����.*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int getString(char str[6]){
		int mas[30]; // ������ �����
		int N = 0; // ���������� �����
		int sum = 0;
		char * end;

		int p = strtol(str, &end, 10);
		mas[N++] = p;
		while (p = strtol(&end, NULL,0))
			mas[N++] = p;

		for (int i = 0; i < N; i++){
			sum += mas[i];
		}
			
		return sum;
}
	
int main()
{
	int func = getString("1, 0,3");
		
	printf("%d", func);
	getchar();
	return 0;
}
