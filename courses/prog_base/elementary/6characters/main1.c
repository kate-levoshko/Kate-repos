#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void printn(int n, char ch){ //1  ������� ������ �� ����������� � �������� � �����, ������� ��� ������ ����� N ��� ����� � ������.
    int i;
    for (i = 0; i < n; i++){
		printf("%c", ch);
	}
}

int isdig (char ch){ //��������� �� ������ � ������ � ������� ��������� (1 - ���, 0 - �).
    if (!isdigit(ch)){
       return 0;
	}
	return 1;
}

int isalf(char ch){ //��������� �� ������ � ������ � ������� ���������.

    if (!isalpha(ch)){
       return 0;
	}
	return 1;
}

int regist (char ch){ //���� ������ � ��������� ������ ������� 2, ���� � �������� 1, ���� �� ����� - ������� 0.

    if (!isalpha(ch)){
       return 0;
	}
	else if (toupper(ch) == ch){
        return 2;
	}
	return 1;
}

int printable (char ch){ //��������� �� � ������ ������ (������������) � ������� ���������.
	if (!isspace(ch)){
       return 0;
	}
	return 1;
}

int main()
{
	int n = 5;
	char ch;
	puts("Enter the symbol");
	scanf("%c",&ch);
	//printn(n, ch);
	int f1 = isdig(ch), f2 = isalf(ch), f3 = regist(ch), f4 = printable(ch);
	printf("%d", f4);
	return 0;
}
