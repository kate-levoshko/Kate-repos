#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "mutex.h"
#include "thread.h"

typedef struct reader_s * reader_t;

reader_t new_reader(text_t * text);
void reader_delete(reader_t reader);
