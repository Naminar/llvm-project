#ifndef LLVM_LIB_TARGET_ASCEND_ASCENDREGISTERINFO_H
#define LLVM_LIB_TARGET_ASCEND_ASCENDREGISTERINFO_H

#define GET_REGINFO_HEADER
#include "AscendGenRegisterInfo.inc"

namespace llvm {

struct AscendRegisterInfo : public AscendGenRegisterInfo {
public:
  AscendRegisterInfo();
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_ASCEND_ASCENDREGISTERINFO_H