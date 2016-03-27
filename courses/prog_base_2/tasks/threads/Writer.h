#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "mutex.h"
#include "thread.h"

typedef struct writer_s * writer_t;

writer_t new_writer(text_t * text);
void writer_delete(writer_t writer);
