#include <string.h>

/*Варіант 21: У рядках записані цілі додатні числа, розділені одним пробілом.
  Знайти рядок у якому сума цих чисел найбільша.
  У результат записати індекс рядка, пробіл і добуток цих чисел рядка поділений на довжину рядка.
*/


/*gcc - std = c89 - pedantic - errors*/
char * process(char * resultStr, const char * textLines[], int linesNum, const char * extraStr) {
int i, j, sum = 0, maxSum = 0, num = 0, maxIndex = 0, k = 1;

static char res[100];

for (i = 0; i < linesNum; i++){

sum = 0;
for (j = 0; j < strlen(textLines[i]); j++){
if (isdigit(*(textLines[i] + j))){
sum = sum + (*(textLines[i] + j) - '0');


}
if (maxIndex < sum){
maxIndex = i;
for (j = 0; j < strlen(textLines[i]); j++){
if (isdigit(*(textLines[i] + j))){
k = (k * (*(textLines[i] + j) - '0'))/strlen(textLines[i]);


}
}

}
}

sprintf(res, "%d %d ", maxSum, k);
return res;
}
}
