#ifndef LLVM_LIB_TARGET_Ascend_Ascend_H
#define LLVM_LIB_TARGET_Ascend_Ascend_H

#include "MCTargetDesc/AscendMCTargetDesc.h"
#include "llvm/Support/raw_ostream.h"

#define ASCEND_DUMP(Color)                                                        \
  {                                                                            \
    llvm::errs().changeColor(Color)                                            \
        << __func__ << "\n\t\t" << __FILE__ << ":" << __LINE__ << "\n";        \
    llvm::errs().changeColor(llvm::raw_ostream::WHITE);                        \
  }
// #define ASCEND_DUMP(Color) {}

#define ASCEND_DUMP_RED ASCEND_DUMP(llvm::raw_ostream::RED)
#define ASCEND_DUMP_GREEN ASCEND_DUMP(llvm::raw_ostream::GREEN)
#define ASCEND_DUMP_YELLOW ASCEND_DUMP(llvm::raw_ostream::YELLOW)
#define ASCEND_DUMP_CYAN ASCEND_DUMP(llvm::raw_ostream::CYAN)
#define ASCEND_DUMP_MAGENTA ASCEND_DUMP(llvm::raw_ostream::MAGENTA)
#define ASCEND_DUMP_WHITE ASCEND_DUMP(llvm::raw_ostream::WHITE)

#endif // LLVM_LIB_TARGET_Ascend_Ascend_H