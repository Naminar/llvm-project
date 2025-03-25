#include "AscendRegisterInfo.h"
#include "Ascend.h"
#include "AscendFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "AscendGenRegisterInfo.inc"

AscendRegisterInfo::AscendRegisterInfo() : AscendGenRegisterInfo(Ascend::R0) {
  ASCEND_DUMP_GREEN
}