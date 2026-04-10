#ifndef BASIC_INTERPRET_INTERFACE_LAYER_H
#define BASIC_INTERPRET_INTERFACE_LAYER_H

#include "types.h"

struct FinalCompile {
  u8 instr;
  u8 data1;
  u8 data2;
  u8 data3;
  s32 data4;
};

struct FinalVariable {
  s32 value;
};

struct FinalProc {
  u16 realstart;
  u8 blocked;
  u8 Type;
  char name[10];
  u8 exclusive;
  u8 numlocals;
};

struct ProcStackUnit { // 0x4
	/* 0x0 */ u16 returnline;
	/* 0x2 */ u8 data1;
	/* 0x3 */ u8 data2;
};

struct BASIC_Instance { // 0x54
	/* 0x00 */ s32 WaitState;
	/* 0x04 */ u32 FrameCount;
	/* 0x08 */ FinalVariable *locals;
	/* 0x0c */ ProcStackUnit ProcStack[6];
	/* 0x24 */ short unsigned int RepStack[8];
	/* 0x34 */ u16 ProgCounter;
	/* 0x36 */ unsigned char IfStack[8];
	/* 0x3e */ unsigned char SWITCHStack[8];
	/* 0x46 */ u8 RepNest;
	/* 0x47 */ u8 IfNest;
	/* 0x48 */ u8 ProcNest;
	/* 0x49 */ u8 SwitchNest;
	/* 0x4a */ u8 RunExclusive;
	/* 0x4b */ u8 FuncID;
	/* 0x4c */ u8 PauseState;
	/* 0x4d */ s8 Speed;
	/* 0x4e */ u8 InstanceNum;
	/* 0x4f */ u8 ReturnVar;
	/* 0x50 */ u8 ChainMode;
};

class BASIC_Main {
  u32 NumInstances;
  u32 Overall_Speed;
  u32 Error_ID;
  u16 NumLines;
  u8 NumVars;
  u8 NumGlobals;
  u8 NumProcs;
  u8 PollFrom;
  FinalVariable *Globals;
  FinalCompile *ScriptCode;
  FinalProc *ProcTable;
  /* 0x20 */ char* name;
  /* 0x24 */ u8* VTable;
  /* 0x28 */ void* m_pOwner; // XSEItemHandler_Base*
  /* 0x2c */ BASIC_Instance GlobalInstance;
  /* 0x80 */ BASIC_Instance *DynamicInstances[16];
  /* 0xc0 */ BASIC_Instance *CurrentInstance;
  public:
  // 	/* 0xc4 */ __vtbl_ptr_type *$vf14428;

  // 	BASIC_Main& operator=();
    BASIC_Main();
  protected:
  	void SetVariable(u8 ref, s32 value);
  	s32 GetVariable(u8 ref);
  	s32 DoMaths(s32 val1, s32 val2, u8 oper);
  	u8 DoCompare(s32 val1, s32 val2, u8 oper);
  // 	u8 ProcessOneLine();
  // 	u32 InterpretExclusive();
  // 	u32 InterpretTimeSlice();
  // 	u32 InitiateScriptInstance();
  // 	void RemoveScriptInstance();
  // 	void RemoveScriptInstanceByEntry();
  // 	s32 FindScriptByName();
  // 	Bool UpdatePointers();
  // public:
  // 	BASIC_Main();
  // 	/* vtable[1] */ virtual BASIC_Main(BASIC_Main*, int, void);
  // 	Bool Init();
  // 	s32 PollScripts();
  // 	u32 RunScript();
  // 	u32 RunScript();
    void SetArg(u8 num, s32 val);
  // 	s32 GetArg();
  // 	void SetReturn();
  // 	s32 GetReturn();
  // 	void SetWaitState(BASIC_Main*, int, void);
  // 	bool IsProcedureRunning();
  /* vtable[2] */ virtual u8 ProcessGameSpecificInstruction(FinalCompile *line,
                                                            u32 *lnum);
  /* vtable[3] */ virtual Bool CheckWaitState(int);
};

#endif // BASIC_INTERPRET_INTERFACE_LAYER_H
