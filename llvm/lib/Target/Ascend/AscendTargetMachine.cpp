#include "AscendTargetMachine.h"
#include "Ascend.h"
#include "TargetInfo/AscendTargetInfo.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"
#include <optional>

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeAscendTarget() {
  // Register the target.
  ASCEND_DUMP_CYAN
  RegisterTargetMachine<AscendTargetMachine> A(getTheAscendTarget());
}

AscendTargetMachine::AscendTargetMachine(const Target &T, const Triple &TT,
                                   StringRef CPU, StringRef FS,
                                   const TargetOptions &Options,
                                   std::optional<Reloc::Model> RM,
                                   std::optional<CodeModel::Model> CM,
                                   CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(T, "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32",
                               TT, CPU, FS, Options, Reloc::Static,
                               getEffectiveCodeModel(CM, CodeModel::Small), OL),
      TLOF(std::make_unique<TargetLoweringObjectFileELF>()) {
  ASCEND_DUMP_CYAN
  initAsmInfo();
}

namespace {

/// Ascend Code Generator Pass Configuration Options.
class AscendPassConfig : public TargetPassConfig {
public:
  AscendPassConfig(AscendTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  AscendTargetMachine &getAscendTargetMachine() const {
    return getTM<AscendTargetMachine>();
  }

  bool addInstSelector() override {
    ASCEND_DUMP_CYAN
    addPass(createAscendISelDag(getAscendTargetMachine(), getOptLevel()));
    return false;
  }
};

} // end anonymous namespace

TargetPassConfig *AscendTargetMachine::createPassConfig(PassManagerBase &PM) {
  ASCEND_DUMP_CYAN
  return new AscendPassConfig(*this, PM);
}

TargetLoweringObjectFile *AscendTargetMachine::getObjFileLowering() const {
  ASCEND_DUMP_CYAN
  return TLOF.get();
}
