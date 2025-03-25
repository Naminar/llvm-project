#ifndef LLVM_LIB_TARGET_ASCEND_MCTARGETDESC_ASCENDMCTARGETDESC_H
#define LLVM_LIB_TARGET_ASCEND_MCTARGETDESC_ASCENDMCTARGETDESC_H

// Defines symbolic names for Ascend registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "AscendGenRegisterInfo.inc"

// Defines symbolic names for the Ascend instructions.
#define GET_INSTRINFO_ENUM
#include "AscendGenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_ASCEND_MCTARGETDESC_ASCENDMCTARGETDESC_H
