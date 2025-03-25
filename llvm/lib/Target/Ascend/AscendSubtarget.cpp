#include "AscendSubtarget.h"
#include "Ascend.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "ascend-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "AscendGenSubtargetInfo.inc"

AscendSubtarget::AscendSubtarget(const StringRef &CPU, const StringRef &TuneCPU,
                           const StringRef &FS, const TargetMachine &TM)
    : AscendGenSubtargetInfo(TM.getTargetTriple(), CPU, TuneCPU, FS) {
  ASCEND_DUMP_CYAN
}