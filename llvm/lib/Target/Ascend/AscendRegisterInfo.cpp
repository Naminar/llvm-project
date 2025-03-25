#include "AscendRegisterInfo.h"
#include "Ascend.h"
#include "AscendFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "AscendGenRegisterInfo.inc"

AscendRegisterInfo::AscendRegisterInfo() : AscendGenRegisterInfo(Ascend::R0) {
  ASCEND_DUMP_GREEN
}
const MCPhysReg *
AscendRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  ASCEND_DUMP_GREEN
  return CSR_Ascend_SaveList;
}

BitVector AscendRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  ASCEND_DUMP_GREEN
  AscendFrameLowering const *TFI = getFrameLowering(MF);

  BitVector Reserved(getNumRegs());
  Reserved.set(Ascend::R1);

  if (TFI->hasFP(MF)) {
    Reserved.set(Ascend::R2);
  }
  return Reserved;
}

bool AscendRegisterInfo::requiresRegisterScavenging(
    const MachineFunction &MF) const {
  return false;
}

bool AscendRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                          int SPAdj, unsigned FIOperandNum,
                                          RegScavenger *RS) const {
  ASCEND_DUMP_GREEN
  assert(SPAdj == 0 && "Unexpected non-zero SPAdj value");

  MachineInstr &MI = *II;
  MachineFunction &MF = *MI.getParent()->getParent();
  DebugLoc DL = MI.getDebugLoc();

  int FrameIndex = MI.getOperand(FIOperandNum).getIndex();
  Register FrameReg;
  int Offset = getFrameLowering(MF)
                   ->getFrameIndexReference(MF, FrameIndex, FrameReg)
                   .getFixed();
  Offset += MI.getOperand(FIOperandNum + 1).getImm();

  if (!isInt<16>(Offset)) {
    llvm_unreachable("");
  }

  MI.getOperand(FIOperandNum).ChangeToRegister(FrameReg, false, false, false);
  MI.getOperand(FIOperandNum + 1).ChangeToImmediate(Offset);
  return false;
}

Register AscendRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  ASCEND_DUMP_GREEN
  const TargetFrameLowering *TFI = getFrameLowering(MF);
  return TFI->hasFP(MF) ? Ascend::R2 : Ascend::R1;
}

const uint32_t *
AscendRegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                      CallingConv::ID CC) const {
  ASCEND_DUMP_GREEN
  return CSR_Ascend_RegMask;
}
