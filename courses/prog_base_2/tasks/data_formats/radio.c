#include "radio.h"

struct radio_s{
	int leadAmount;
	struct radioLead_s * leads[MAX_NUMBER_OF_LEADS];
};

struct radioLead_s{
	char * name;
	char * surname;
	char * date;
	double jobExp;
	int salary;
	char * favouritePerfomer;
	char * favouriteSong;
};

radio_t * radio_newRadio(void){
	radio_t * radio = (radio_t *)malloc(sizeof(struct radio_s));
	radio->leadAmount = 0;
	for (int i = 0; i < radio->leadAmount; i++){
		radio->leads[i] = radioLead_newRadioLead();
	}
	return radio;
}

radioLead_t * radioLead_newRadioLead(void){
	radioLead_t * radioLead = (radio_t *)malloc(sizeof(struct radioLead_s));
	return radioLead;
}

void radio_free(radio_t * self){
	for (int i = 0; i < self->leadAmount; i++){
		free(self->leads[i]);
	}
	free(self);
}

void radio_printRadio(xmlNode * xSt){

	printf("\t%s\n\n", xSt->name);

	for (xmlNode * xI = xSt->children; xI; xI = xI->next){
		if (XML_ELEMENT_NODE != xI->type){
			continue;
		}
		if (xmlStrcmp(xI->name, "musicPrefer") == 0){
			xmlNode * xPerfomer = xI;
			xmlNode * xSong = xPerfomer->children->next;
			const char * groupName = xmlGetProp(xI, "perfomer");
			const char * song = xmlNodeGetContent(xSong);
			printf("\t\t%10s %s\n\t\t\t  %s \n\n\n", "musicPrefer:", groupName, song);
			continue;
		}
		const char * contents = xmlNodeGetContent(xI);
		printf("\t\t%10s : %s\n", xI->name, contents);
	}
}

void radio_parseXML(radio_t * self){
	char line[LINE_MAX_SIZE];
	char text[TEXT_MAX_SIZE] = "";
	FILE * fr = fopen("radio.xml", "r");
	while (fgets(line, LINE_MAX_SIZE, fr)) {
		strcat(text, line);
	}

	xmlDoc * xDoc = xmlReadMemory(text, strlen(text), NULL, NULL, 0);
	xmlNode * xRoot = xmlDocGetRootElement(xDoc);
	printf("\n\n", xRoot->name);
	for (xmlNode * xI = xRoot->children; xI; xI = xI->next){
		if (XML_ELEMENT_NODE != xI->type){
			continue;
		}
		radio_printRadio(xI);
	}
}


