#ifndef LLVM_LIB_TARGET_ASCEND_MCTARGETDESC_ASCENDMCTARGETDESC_H
#define LLVM_LIB_TARGET_ASCEND_MCTARGETDESC_ASCENDMCTARGETDESC_H

#include <memory>
namespace llvm {
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;
class MCAsmBackend;
class MCObjectTargetWriter;
class MCRegisterInfo;
class MCSubtargetInfo;
class MCTargetOptions;
class Target;

MCCodeEmitter *createAscendMCCodeEmitter(const MCInstrInfo &MCII, MCContext &Ctx);
MCAsmBackend *createAscendAsmBackend(const Target &T, const MCSubtargetInfo &STI,
                                  const MCRegisterInfo &MRI,
                                  const MCTargetOptions &Options);
std::unique_ptr<MCObjectTargetWriter> createAscendELFObjectWriter(bool Is64Bit,
                                                               uint8_t OSABI);
} // namespace llvm

// Defines symbolic names for Ascend registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "AscendGenRegisterInfo.inc"

// Defines symbolic names for the Ascend instructions.
#define GET_INSTRINFO_ENUM
#include "AscendGenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_ASCEND_MCTARGETDESC_ASCENDMCTARGETDESC_H
