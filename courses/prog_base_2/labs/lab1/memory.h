#pragma once

#define MAX_AMOUNT_OF_BYTES 256

#include "header.h"

enum MemoryError{
	MEMORY_FULL,
	MEMORY_EMPTY,
	MEMORY_OK,
	MEMORY_INCORRECTDATA
};

int memory_getSize(memory_t * mem); // �������� ������ ���������� ������
void memory_writeBytesInMemory(memory_t * mem, char * bytes); // �������� ������������������ ���� � ������
char * memory_readBytesfromMemory(memory_t * mem); // ������� ������������������ ������ �� ������

int memory_getStructSize();

void memory_setNullAllocMemorySize(memory_t * mem);
void memory_setNullAmountOfObjects(memory_t * mem);
void memory_setNullData(memory_t * mem);