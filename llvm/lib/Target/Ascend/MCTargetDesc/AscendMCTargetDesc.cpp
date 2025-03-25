#include "MCTargetDesc/AscendInfo.h"
#include "Ascend.h"
#include "TargetInfo/AscendTargetInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "AscendGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "AscendGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "AscendGenSubtargetInfo.inc"

static MCRegisterInfo *createAscendMCRegisterInfo(const Triple &TT) {
  ASCEND_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitAscendMCRegisterInfo(X, Ascend::R0);
  return X;
}

static MCInstrInfo *createAscendMCInstrInfo() {
  ASCEND_DUMP_MAGENTA
  MCInstrInfo *X = new MCInstrInfo();
  InitAscendMCInstrInfo(X);
  return X;
}

static MCSubtargetInfo *createAscendMCSubtargetInfo(const Triple &TT,
                                                 StringRef CPU, StringRef FS) {
  ASCEND_DUMP_MAGENTA
  return createAscendMCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeAscendTargetMC() {
  ASCEND_DUMP_MAGENTA
  Target &TheAscendTarget = getTheAscendTarget();
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheAscendTarget, createAscendMCRegisterInfo);
  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheAscendTarget, createAscendMCInstrInfo);
  // Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(TheAscendTarget,
                                          createAscendMCSubtargetInfo);
}
