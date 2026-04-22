#include "libc/stddef.h"
#include <EngineX/EXMalloc.h>

void EXMemBlock::Init(size_t size)
{
}

void* EXMemHeap::_EXAlloc(size_t size, unsigned long unk0)
{
    EXMemHeap::_sysAlloc(size, unk0);
}

void* EXMemHeap::_EXAllocPure(size_t size, unsigned long unk0)
{
    EXMemHeap::_sysAlloc(size, unk0);
}
