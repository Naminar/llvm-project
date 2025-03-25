add_llvm_component_group(Ascend)

set(LLVM_TARGET_DEFINITIONS Ascend.td)

tablegen(LLVM AscendGenRegisterInfo.inc -gen-register-info)

add_public_tablegen_target(AscendCommonTableGen)

add_llvm_target(AscendCodeGen
  AscendTargetMachine.cpp
  AscendRegisterInfo.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  AscendInfo

  ADD_TO_COMPONENT
  Ascend
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
