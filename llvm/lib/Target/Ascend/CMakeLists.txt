add_llvm_component_group(Ascend)

set(LLVM_TARGET_DEFINITIONS Ascend.td)

tablegen(LLVM AscendGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM AscendGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM AscendGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM AscendGenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM AscendGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM AscendGenCallingConv.inc -gen-callingconv)

add_public_tablegen_target(AscendCommonTableGen)

add_llvm_target(AscendCodeGen
  AscendTargetMachine.cpp
  AscendRegisterInfo.cpp
  AscendInstrInfo.cpp
  AscendSubtarget.cpp
  AscendAsmPrinter.cpp
  AscendISelDagToDag.cpp
  AscendISelLowering.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  AscendInfo
  AsmPrinter
  SelectionDAG

  ADD_TO_COMPONENT
  Ascend
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
