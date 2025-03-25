#include "AscendInstrInfo.h"
#include "Ascend.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineMemOperand.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_INSTRINFO_CTOR_DTOR
#include "AscendGenInstrInfo.inc"

#define DEBUG_TYPE "Ascend-inst-info"

AscendInstrInfo::AscendInstrInfo() : AscendGenInstrInfo() { ASCEND_DUMP_GREEN }
