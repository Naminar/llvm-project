include "llvm/Target/Target.td"
include "AscendRegisterInfo.td"
include "AscendInstrInfo.td"
include "AscendCallingConv.td"

class Proc<string Name, list<SubtargetFeature> Features>
 : Processor<Name, NoItineraries, Features>;

def : Proc<"generic", []>;

def AscendInstrInfo : InstrInfo;
def Ascend : Target {
  let InstructionSet = AscendInstrInfo;
}
