#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "header.h"

void jump(int x, int y){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hConsole, pos);
}

int main(){
	COORD pos;
	//runTests();
	
	heap_t * heap1 = heap_new(7);
	jump(45, 0);
	heap_t * heap2 = heap_new(77);
	memory_t * mem;
	memory_t * addMemory1 = heap_addMemory(heap1);
	mem = heap_addMemory(heap1);

	memory_writeBytesInMemory(mem, "011");
	memory_writeBytesInMemory(mem, "55");

	int sizeOfMemory = memory_getSize(mem);
	printf("Size of allocated memory is: %d\n", sizeOfMemory);

	char * read = memory_readBytesfromMemory(mem);
	if (read != NULL) printf("Read data is: %s", read);

	heap_freeMemory(heap1, mem);
	heap_free(heap1);
	jump(45, 1);

	heap_free(heap2);
	getchar();
	return 0;
}