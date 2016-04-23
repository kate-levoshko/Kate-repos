#include "main.h"

int compare(queue_t * self){
    return (queue_getSum(self) > 100);
}

int reaction(queue_t * self){
    for (int i = 0; i < queue_getCount(self); i++){
        if (queue_getSum(self) > 50){
            queue_dequeue(self);
        }
    }
    return 0;
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
