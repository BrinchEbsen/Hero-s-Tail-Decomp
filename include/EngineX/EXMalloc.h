#ifndef EXMALLOC_H
#define EXMALLOC_H

#include "types.h"

struct EXMemBlock
{
    union
    {
        EXMemBlock* m_pPrev;
        void* m_pOwner;
    };
    union
    {
        EXMemBlock* m_pNext;
        // EXMEMCALLBACK* m_pFunc;
        // EXMemCacheEntry* m_pCache;
    };
    u32 m_Size_Flags;
    u32 m_PrevSize_Align;

    // EXMemBlock& operator=();
    EXMemBlock();
    // EXMemBlock();
    void SetFlag();
    void ClrFlag();
    void SetFlags();
    void SetOwner();
    void* Owner();
    void SetTime();
    void SetFunc();
    Bool LockMem();
    char* AlignText();
    void Init(u32);
    void Copy();
    void* Data();
    // EXMEMCALLBACK* Func();
    Bool CallFunction();
    void SetAlignFlags();
    u32 AlignFlags();
    u32 Alignment();
    u32 IsFree();
    u32 IsMoveable();
    u32 IsCache();
    u32 Flags();
    void SetPrevSize();
    void SetSize();
    u32 Size();
    void SetDefaults();
    EXMemBlock* PrevLink();
    EXMemBlock* NextLink();
    EXMemBlock* LinkAddr();
    EXMemBlock* Split();
    void Add();
    void Remove();
    void JoinNext();
    s32 GetSize();
};

struct EXMemHeap
{
    void* m_pMemAlloc;
    EXMemBlock* m_pStart;
    EXMemBlock* m_pEnd;
    //EXDListItem m_FreeList[5];
    //EXMemCacheArray m_CacheLists[3];
    s32 m_HeapId;
    u32 m_HeapSize;
    char* m_HeapName;
    static Bool m_ForceCompactHeaps;
    static Bool m_EnableCompactHeaps;
    static void (*m_PreCompactCallback)(/* parameters unknown */);
    static void (*m_PostCompactCallback)(/* parameters unknown */);
    unsigned int m_DebugStats[4];

    // static EXFixedArray<unsigned int, 7> m_gAlignTbl;
    // static EXFixedArray<const char*, 7> m_gAlignTxt;

    // EXMemHeap& operator=();
    EXMemHeap();
    // EXMemHeap();
    EXMemHeap(EXMemHeap*, int, void);
    void Init();
    void* MemAlloc();
    EXMemBlock* MemStart();
    EXMemBlock* MemEnd();
    char* Name();
    u32 HeapId();
    u32 HeapSize();
    EXMemBlock* FindLargestFree();
    void* _EXAlloc(unsigned int, unsigned long);
    void* _EXAllocPure(unsigned int, unsigned long);
    void* _EXAllocRel();
    void* _EXAllocFnc();
    void* _EXCache();
    void* _EXCacheDel();
    void* _EXRealloc();
    void EXFree();
    static void CompactHeaps(/* parameters unknown */);
    static void ForceCompactHeaps(/* parameters unknown */);
    static void EnableAutoHeapCompact(/* parameters unknown */);
    static void SetCompactCallbacks(/* parameters unknown */);
    void Update();
    static void UpdateAllHeaps(/* parameters unknown */);
    static void UpdateHeapStats(/* parameters unknown */);
    static void FlushAllCacheMem(/* parameters unknown */);
    static void RegisterMallocVars(/* parameters unknown */);
    void Debug_CalculateStats();
    u32 Debug_Stats();

    void* _sysAlloc(unsigned int, unsigned long);
    void* _sysAllocRel();
    void* _sysAllocFnc();
    void* _sysCache();
    void* _sysCacheDel();
    void* _sysRealloc();
    EXMemBlock* _sysFree();
    void _sysSetAsCache();
    void UpdateFirstLastFree();
    EXMemBlock* _FindFirstFree();
    EXMemBlock* _FindLastFree();
    EXMemBlock* _FindFree();
    EXMemBlock* _FindLargestFree();
    EXMemBlock* _FindFreeLastChance();
    EXMemBlock* _FindFreeCacheMem();
    EXMemBlock* SplitAlignMemory();
    EXMemBlock* SplitAlignMemory2();
    EXMemBlock* AllocBlock();
    EXMemBlock* AddFreeList();
    EXMemBlock* AddFreeList2();
    EXMemBlock* CompactMemLo();
    EXMemBlock* CompactMemHi();
    EXMemBlock* CompactMemHiAlignMemory();
    void AddCache();
    void RemoveCache();
    void AgeCacheMem();
    void FlushCacheMem();
    Bool Compact();
};

#endif // EXMALLOC_H
