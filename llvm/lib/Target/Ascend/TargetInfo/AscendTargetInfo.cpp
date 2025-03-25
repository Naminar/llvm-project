#include "TargetInfo/AscendTargetInfo.h"
#include "Ascend.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheAscendTarget() {
  ASCEND_DUMP_YELLOW
  static Target TheAscendTarget;
  return TheAscendTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeAscendTargetInfo() {
  ASCEND_DUMP_YELLOW
  RegisterTarget<Triple::ascend> X(getTheAscendTarget(), "ascend",
                                "Ascendulator target for LLVM course", "ASCEND");
}
