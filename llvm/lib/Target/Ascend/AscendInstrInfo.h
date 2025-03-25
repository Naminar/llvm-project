#ifndef LLVM_LIB_TARGET_ASCEND_ASCENDINSTRINFO_H
#define LLVM_LIB_TARGET_ASCEND_ASCENDINSTRINFO_H

#include "AscendRegisterInfo.h"
#include "MCTargetDesc/AscendInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "AscendGenInstrInfo.inc"

namespace llvm {

class AscendSubtarget;

class AscendInstrInfo : public AscendGenInstrInfo {
public:
  AscendInstrInfo();

};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_ASCEND_ASCENDINSTRINFO_H
