#ifndef LLVM_LIB_TARGET_ASCEND_MCTARGETDESC_ASCENDMCASMINFO_H
#define LLVM_LIB_TARGET_ASCEND_MCTARGETDESC_ASCENDMCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class AscendELFMCAsmInfo : public MCAsmInfoELF {
public:
  explicit AscendELFMCAsmInfo(const Triple &TheTriple);
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_ASCEND_MCTARGETDESC_ASCENDMCASMINFO_H