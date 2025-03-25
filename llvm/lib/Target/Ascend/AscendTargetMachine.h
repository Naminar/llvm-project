#ifndef LLVM_LIB_TARGET_ASCEND_ASCENDTARGETMACHINE_H
#define LLVM_LIB_TARGET_ASCEND_ASCENDTARGETMACHINE_H

#include "AscendSubtarget.h"
#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include <optional>

namespace llvm {
extern Target TheAscendTarget;

class AscendTargetMachine : public CodeGenTargetMachineImpl {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  AscendSubtarget Subtarget;

public:
  AscendTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                   StringRef FS, const TargetOptions &Options,
                   std::optional<Reloc::Model> RM,
                   std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                   bool JIT);

  const AscendSubtarget *getSubtargetImpl(const Function &) const override {
    ASCEND_DUMP_CYAN
    return &Subtarget;
  }
  // Pass Pipeline Configuration
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override;
};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_ASCEND_ASCENDTARGETMACHINE_H
