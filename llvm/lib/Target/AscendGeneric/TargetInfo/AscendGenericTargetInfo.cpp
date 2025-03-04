#include "TargetInfo/AscendGenericTargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
using namespace llvm;

Target &llvm::getTheAscendGenericTarget() {
  static Target TheAscendGenericTarget;
  return TheAscendGenericTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeAscendGenericTargetInfo() {
  RegisterTarget<Triple::AscendGeneric> X(getTheAscendGenericTarget(), "AscendGeneric", "AscendGeneric 32",
                                   "AscendGeneric");
}