#include "main.h"

int compare(queue_t * self){
    return (queue_getCount(self) > 10);
}

int reaction (queue_t * self){
    int sum = 0;
    int removeElement;
    for (int i = 0; i < 5; i++){
        removeElement = queue_dequeue(self);
        sum += removeElement;
    }
    return sum;
}

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}
