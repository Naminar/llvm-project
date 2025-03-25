#include "Ascend.h"
#include "TargetInfo/AscendTargetInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "AscendGenRegisterInfo.inc"

static MCRegisterInfo *createAscendMCRegisterInfo(const Triple &TT) {
  ASCEND_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitAscendMCRegisterInfo(X, Ascend::R0);
  return X;
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeAscendTargetMC() {
  ASCEND_DUMP_MAGENTA
  Target &TheAscendTarget = getTheAscendTarget();
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheAscendTarget, createAscendMCRegisterInfo);
}
