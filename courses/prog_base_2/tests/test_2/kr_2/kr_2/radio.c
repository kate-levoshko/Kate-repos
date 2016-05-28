#include "radio.h"

void radio_print(radio_t * radio) {
	printf("Name: %s\nSurname: %s\nStart job date: %s\nJob Experience: %f\nStyle: %s\nSalary: %d\nAmount of programs: %d\n\n",
		radio->name, radio->surname, radio->jobBeginDate, radio->jobExperience, radio->style, radio->salary, radio->programsAmount);
}

void radio_printList(radio_t * arr, int len) {
	for (int i = 0; i < len; i++) {
		radio_print(&arr[i]);
	}
}


char * radio_getName(radio_t * radio){
	return radio->name;
}

char * radio_getSurname(radio_t * radio){
	return radio->surname;
}

char * radio_getJobBeginDate(radio_t * radio){
	return radio->jobBeginDate;
}

float radio_getJobExperience(radio_t * radio){
	return radio->jobExperience;
}

char * radio_getStyle(radio_t * radio){
	return radio->style;
}

int radio_getSalary(radio_t * radio){
	return radio->salary;
}

int radio_getProgramsAmount(radio_t * radio){
	return radio->programsAmount;
}
