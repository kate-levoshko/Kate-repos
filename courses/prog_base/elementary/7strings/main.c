#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void printn (int n, char str[100]){ //������� ������ �� ����� N ��� � ������, ����� ������ �� ���������� � ������ �����.
    int i;
    for (i = 0; i < n; i++){
        puts(str);
    }
}

void changeRegist (char str[100]){ //������� � ������ �� ������� � �������� ������ �� ������� ������� � ��������� ������ � �������. ������� ������ � ������.
    int i;
    for (i = 0; i < strlen(str); i++){
        if (tolower(str[i]) != str[i]){
            printf("%c", tolower(str[i]));
        }
        else if (tolower(str[i] == str[i])){
            printf("%c", toupper(str[i]));
        }
    }
}

int numAmount (char str[100]){ // ���������� � ������� ������� ��� �������� ������� � ������.
    int i;
    int number = 0;
    for(i = 0; i < strlen(str); i++){
        if (isdigit(str[i])){
            number++;
        }
    }
    return number;
}
int numSum (char str[]){ //������� ���� ��� �������� ������� �� ������.
    int i;
    int sum = 0;
    for(i = 0; i < strlen(str); i++){
        if(isdigit(str[i])){
            sum += str[i];
        }
    return sum;
    }
}
int main() //������� ������, ��� ��� ����������.
{
    int i;
    int n = 5;
    char str[100];
    puts("Please, enter the string");
    gets(str);
    int f1 = numAmount (str);
    int f2 = numSum (str);
    //printn (n, str);
    //changeRegist (str);
    //printf("%d", f1);
    printf("%d", f2);
    return 0;
}
