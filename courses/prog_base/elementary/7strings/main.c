#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void printn (int n, char str[100]){ //Вивести строку на екран N раз у консолі, кожна строка має виводитись з нового рядка.
    int i;
    for (i = 0; i < n; i++){
        puts(str);
    }
}

void changeRegist (char str[100]){ //Замінити у строці всі символи у нижньому регістрі на відповідні символи у верхньому регістрі і навпаки. Вивести строку у консолі.
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

int numAmount (char str[100]){ // Порахувати і вивести кількість всіх цифрових символів у строці.
    int i;
    int number = 0;
    for(i = 0; i < strlen(str); i++){
        if (isdigit(str[i])){
            number++;
        }
    }
    return number;
}
int numSum (char str[]){ //Вивести суму всіх цифрових символів із строки.
    int i;
    int sum = 0;
    for(i = 0; i < strlen(str); i++){
        if(isdigit(str[i])){
            sum += str[i];
        }
    return sum;
    }
}
int main() //Зчитати строку, яку ввів користувач.
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
