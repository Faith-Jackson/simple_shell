#include "shell.h"

int releaseMemory(void **memoryPtr)
{
    if (memoryPtr && *memoryPtr)
    {
        free(*memoryPtr);
        *memoryPtr = NULL;
        return (1);
    }
    return (0);
}
