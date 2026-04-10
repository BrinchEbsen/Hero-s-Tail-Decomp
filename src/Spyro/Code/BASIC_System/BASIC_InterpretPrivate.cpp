#include <BASIC_System/BASIC_InterpretInterfaceLayer.h>

u8 BASIC_Main::DoCompare(s32 val1, s32 val2, u8 oper) {
  
  s32 result = 0;
  switch (oper & 7u) {
    case 1:
      result = val1 == val2;
      break;
    case 2:
      result = val1 > val2;
      break;
    case 3:
      result = val1 >= val2;
      break;
    case 4:
      result = val1 < val2;
      break;
    case 5:
      result = val1 <= val2;
      break;
    case 6:
      result = val1 != val2;
      break;
  }

  if ((oper & 8u) == 0) {
    return result;
  } else {
    return !result;
  }
}

s32 BASIC_Main::DoMaths(s32 val1, s32 val2, u8 oper) {
  switch (oper) {
    case 3:
      return val1 + val2;
    case 4:
      return val1 - val2;
    case 1:
      return val1 * val2;
    case 2:
      return val1 / val2;
    case 10:
      return val1 * -val2;
    case 11:
      return val1 / -val2;
    case 5:
      return val1 << val2;
    case 6:
      return val1 >> val2;
    case 7:
      return val1 & val2;
    case 8:
      return val1 | val2;
    case 9:
      return val1 ^ val2;
    default:
      return 0;
  }
}

s32 BASIC_Main::GetVariable(u8 ref) {
  if (ref < NumGlobals) {
    return Globals[ref].value;
  }
  
  return CurrentInstance->locals[ref - NumGlobals].value;
}

void BASIC_Main::SetVariable(u8 ref, s32 value) {
  if (ref < NumGlobals) {
    Globals[ref].value = value;
  } else {
    CurrentInstance->locals[ref - NumGlobals].value = value;
  }
}
