#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void charr (int n, char ch[]){ //�������� ��������� ����� ������� � ��������� ���� ���������, �� ������� ����������.
    int i;
    puts("Array:");
    for (i = 0; i < n; i++){
        printf("%c ", ch[i]);
    }
}

void changeontab(int n, char ch[]){ //������� �� ������ ������� � ����� ������� �� ������, ������� �������� ������ ������� ����� ����.
    int i;
    for (i  = 0; i < n; i++){
        if (isdigit(ch[i])){
            ch[i] = ' ';
        }
        printf("%c, ",ch[i]);
    }
}

int alfaIndex(int n, char ch[]){ //������ ������ ������� ���������� ������� � �����.
    int i, index = -1;
    for (i = 0; i < n; i++){
        if (isalpha(ch[n-i])){
            index = n-i;
        }
    }
    return index;
}

int main()
{
    int n = 10;
    char ch[n];
    puts("Enter the symbols:");
    gets(ch);
    if (strlen(ch) < n){
        printf("Incorrect amount of symbols!");
    }
    else{
        //charr(n, ch);
        //changeontab(n, ch);
        //int f1 = alfaIndex(n, ch);
        //printf("%i", f1);
    }
    return 0;
}

/*
� ����� ������� ������� �� ����� � �������� ������ � ������ ������, � �� ������ ������� ������� �� ������� (9 - �����, ���������, ���� ������ '3', �� ������� ���� �� 9 - 3 = '6').������� ������ ������ ��������� � ������ �������� ������ � ����� �������.
������� ����� �������. ���������� �� ������� ������� �� ������� ������, ���� �� ������ �������, � � ���� �� ���� �������. ������� ������������ ����� � ������.
������� ����� ������� � ������� ������. ��������� �� �������� ���� � ��� ������� ������ � ����� �������.
*/
