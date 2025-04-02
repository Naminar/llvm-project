#ifndef LLVM_LIB_TARGET_ASCEND_MCTARGETDESC_ASCENDINFO_H
#define LLVM_LIB_TARGET_ASCEND_MCTARGETDESC_ASCENDINFO_H

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace AscendOp {
enum OperandType : unsigned {
  OPERAND_SIMM16 = MCOI::OPERAND_FIRST_TARGET,
};
} // namespace AscendOp

} // end namespace llvm

#endif
