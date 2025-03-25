#ifndef LLVM_LIB_TARGET_Ascend_Ascend_H
#define LLVM_LIB_TARGET_Ascend_Ascend_H

#include "MCTargetDesc/AscendMCTargetDesc.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"

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
namespace llvm {
class AscendTargetMachine;
class FunctionPass;
class AscendSubtarget;
class AsmPrinter;
class InstructionSelector;
class MCInst;
class MCOperand;
class MachineInstr;
class MachineOperand;
class PassRegistry;

bool lowerAscendMachineInstrToMCInst(const MachineInstr *MI, MCInst &OutMI,
                                  AsmPrinter &AP);
bool LowerAscendMachineOperandToMCOperand(const MachineOperand &MO,
                                       MCOperand &MCOp, const AsmPrinter &AP);
FunctionPass *createAscendISelDag(AscendTargetMachine &TM, CodeGenOptLevel OptLevel);

} // namespace llvm

#endif // LLVM_LIB_TARGET_Ascend_Ascend_H