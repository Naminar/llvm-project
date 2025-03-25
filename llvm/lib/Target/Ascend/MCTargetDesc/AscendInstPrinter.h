#ifndef LLVM_LIB_TARGET_ASCEND_INSTPRINTER_ASCENDINSTPRINTER_H
#define LLVM_LIB_TARGET_ASCEND_INSTPRINTER_ASCENDINSTPRINTER_H

#include "llvm/MC/MCInstPrinter.h"
#include "llvm/MC/MCRegister.h"

namespace llvm {

class AscendInstPrinter : public MCInstPrinter {
public:
  AscendInstPrinter(const MCAsmInfo &MAI, const MCInstrInfo &MII,
                 const MCRegisterInfo &MRI)
      : MCInstPrinter(MAI, MII, MRI) {}

  std::pair<const char *, uint64_t>
  getMnemonic(const MCInst &MI) const override {}

  // Override MCInstPrinter.
  void printRegName(raw_ostream &O, MCRegister Reg) override {}
  void printInst(const MCInst *MI, uint64_t Address, StringRef Annot,
                 const MCSubtargetInfo &STI, raw_ostream &O) override {}
};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_ASCEND_INSTPRINTER_ASCENDINSTPRINTER_H