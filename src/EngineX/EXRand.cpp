#include <EngineX/EXRand.h>

void EXRandClass::SetSeed(u64 Seed)
{
    m_RandShift = Seed;
}

void EXRandClass::SetState(EXRandClass& State)
{
    m_RandShift = State.m_RandShift;
}

void EXRandClass::GetState(EXRandClass& State) const
{
    State.m_RandShift = m_RandShift;
}

u32 EXRandClass::Rand32()
{
    u32 tmpRand;
    u32 tmpRand2;

    tmpRand2 = m_RandShift * 0x343fd + 0x269ec3; // 214013 and 2531011
    tmpRand = tmpRand2 * 0x343fd + 0x269ec3; // 214013 and 2531011
    m_RandShift = tmpRand;
    return tmpRand2 & 0xffff0000 | tmpRand >> 16;
}

float EXRandClass::Randf()
{
    return (float)EXRandClass::Rand32() * 16;
}
