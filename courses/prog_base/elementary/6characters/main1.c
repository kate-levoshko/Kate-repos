#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void printn(int n, char ch){ //1  Зчитати символ від користувача і записати у змінну, вивести цей символ підряд N раз підряд у консолі.
    int i;
    for (i = 0; i < n; i++){
		printf("%c", ch);
	}
}

int isdig (char ch){ //Визначити чи символ є цифрою і вивести результат (1 - так, 0 - ні).
    if (!isdigit(ch)){
       return 0;
	}
	return 1;
}

int isalf(char ch){ //Визначити чи символ є буквою і вивести результат.

    if (!isalpha(ch)){
       return 0;
	}
	return 1;
}

int regist (char ch){ //Якщо символ у верхньому регістрі вивести 2, якщо у нижньому 1, якщо не буква - вивести 0.

    if (!isalpha(ch)){
       return 0;
	}
	else if (toupper(ch) == ch){
        return 2;
	}
	return 1;
}

int printable (char ch){ //Визначити чи є символ пустим (недрукованим) і вивести результат.
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
