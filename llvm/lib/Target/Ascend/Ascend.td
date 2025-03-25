include "llvm/Target/Target.td"
include "AscendRegisterInfo.td"
include "AscendInstrInfo.td"

def AscendInstrInfo : InstrInfo;
def Ascend : Target {
  let InstructionSet = AscendInstrInfo;
}
