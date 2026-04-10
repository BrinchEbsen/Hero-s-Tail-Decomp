#include <BASIC_System/BASIC_InterpretInterfaceLayer.h>

BASIC_Main::BASIC_Main() {
    PollFrom = 0;
    ProcTable = NULL;
    ScriptCode = NULL;
    Globals = NULL;
    m_pOwner = NULL;
    NumInstances = 0;

    for (int i = 0; i < 16; i++) {
        DynamicInstances[i] = NULL;
    }

    Overall_Speed = 5;
    GlobalInstance.locals = NULL;
}

void BASIC_Main::SetArg(u8 num, s32 val) {
    if (num < 8) {
        SetVariable(num, val);
    }
}
