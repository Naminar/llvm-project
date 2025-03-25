#include "AscendISelLowering.h"
#include "Ascend.h"
#include "AscendRegisterInfo.h"
#include "AscendSubtarget.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFunction.h"

#define DEBUG_TYPE "Ascend-lower"

using namespace llvm;

AscendTargetLowering::AscendTargetLowering(const TargetMachine &TM,
                                     const AscendSubtarget &STI)
    : TargetLowering(TM), STI(STI) {
  ASCEND_DUMP_RED
  addRegisterClass(MVT::i32, &Ascend::GPRRegClass);
}

const char *AscendTargetLowering::getTargetNodeName(unsigned Opcode) const {
  ASCEND_DUMP_RED
  switch (Opcode) {
  case AscendISD::CALL:
    return "AscendISD::CALL";
  case AscendISD::RET:
    return "AscendISD::RET";
  }
  return nullptr;
}
