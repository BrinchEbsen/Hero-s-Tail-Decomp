#include <include/EngineX/EXString.h>

u16 EXString::Capacity() {
    if (m_pData != NULL) {
        return ((EXStringData*)m_pData)[-1].Alloc;
    } else {
        return 0;
    }
}

u16 EXString::Length() {
    if (m_pData != NULL) {
        return ((EXStringData*)m_pData)[-1].Len;
    } else {
        return 0;
    }
}

s32 EXString::Find(char ch, s32 pos) const {
    if (m_pData == NULL) {
        return -1;
    }

    if (pos < 0) {
        return -1;
    }

    EXStringData* dat = ((EXStringData*)m_pData) - 1;

    if (pos >= dat->Len) {
        return -1;
    }

    for (; pos < ((EXStringData*)m_pData)[-1].Len; pos++) {
        char* c = m_pData+pos;
        if (*c == ch) {
            return pos;
        }
    }

    return -1;
}
