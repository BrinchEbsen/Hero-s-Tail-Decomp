#ifndef EXSTRING_H
#define EXSTRING_H

#include "types.h"

typedef struct EXStringData { // 0x8
	/* 0x0 */ u32 Refs;
	/* 0x4 */ u16 Len;
	/* 0x6 */ u16 Alloc;
} EXStringData;

class EXString { // 0x4
protected:
    /* 0x0 */ char* m_pData;

public:
	// EXString();
	// EXString();
	// EXString();
	// EXString();
	// EXString(EXString*, int, void);
	// void Empty();
	// EXString& operator=();
	// EXString& operator=();
	// EXString& operator+=();
	// EXString& operator+=();
	// EXString& operator+=();
	// void MakeUnique();
	// void ToUpper();
	// void ToLower();
	u16 Length();
	u16 Capacity();
	s32 Find(char ch, s32 pos) const;
	// Bool IsEmpty();
	// char* GetBuffer();
	// void ReleaseBuffer();
	// s8 Compare();
	// s8 CompareNoCase();
	// char* operator char *();
	// char* c_str();
	// char* data();
	// char* data();
	// EXString Token();
	// EXString Token();
	// int Tokenise();
	// s16 Format();
protected:
	// void AllocMem();
	// void ReallocMem();
	// void DeallocMem();
	// int IncRefCount();
	// void SetLength();
};

#endif // EXSTRING_H
