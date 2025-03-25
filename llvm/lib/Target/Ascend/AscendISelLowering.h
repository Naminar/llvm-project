#ifndef LLVM_LIB_TARGET_ASCEND_ASCENDISELLOWERING_H
#define LLVM_LIB_TARGET_ASCEND_ASCENDISELLOWERING_H

#include "Ascend.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

class AscendSubtarget;
class AscendTargetMachine;

namespace AscendISD {

enum NodeType : unsigned {
  // Start the numbering where the builtin ops and target ops leave off.
  FIRST_NUMBER = ISD::BUILTIN_OP_END,
  RET,
  CALL,
  BR_CC,
};

} // namespace AscendISD

class AscendTargetLowering : public TargetLowering {
public:
  explicit AscendTargetLowering(const TargetMachine &TM, const AscendSubtarget &STI);

  /// This method returns the name of a target specific DAG node.
  const char *getTargetNodeName(unsigned Opcode) const override;

  AscendSubtarget const &getSubtarget() const { return STI; }

private:
  const AscendSubtarget &STI;
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_ASCEND_ASCENDISELLOWERING_H