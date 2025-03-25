add_llvm_component_group(Ascend)

add_llvm_target(AscendCodeGen
  AscendTargetMachine.cpp

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
